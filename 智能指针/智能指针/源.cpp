#include <iostream>
using namespace std;

//智能指针,自动释放资源
//RAII管理资源+将*和->重载,实现指针的功能
//问题是存在浅拷贝的问题
#if 0
//加一个命名空间
namespace Raii
{
	template<class T>
	class auto_ptr
	{
	public:
		//RAII
		auto_ptr(T* ptr = nullptr)
			: _ptr(ptr)
		{}

		auto_ptr(auto_ptr<T>& ap)//拷贝构造,使之前的对象与资源断开联系
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;//使之前的对象与资源断开联系
		}

		auto_ptr<T>& operator=(auto_ptr<T>& ap)//赋值运算符重载
		{
			if (this!=&ap)//检测是否为自己给自己赋值
			{
				if (_ptr)
					delete _ptr;//如果已经管理资源,将原来的资源释放
				_ptr = ap._ptr;//转移资源
				ap->_ptr = nullptr;
			}
		}

		~auto_ptr()//析构函数
		{
			if (_ptr)
			{
				delete _ptr;
				_ptr = nullptr;
			}
		}
		//具有类似指针的行为
		T* operator->()
		{
			return _ptr;
		}

		T& operator*()
		{
			return *_ptr;
		}
	};
private:
	T* _ptr;
}

//直接通过ap1给ap2拷贝构造,两个对象使用同一份资源,在释放时就会因为多次释放导致代码奔溃
void TestAuto1()
{
	int a = 10;
	int* pa1 = &a;
	int* pa2(pa1);

	*pa1 = 20;//解引用访问的是实体
	*pa2 = 30;

	Raii::auto_ptr<int> ap1(new int);
	Raii::auto_ptr<int> ap2(ap1);
	*ap1 = 10;
	*ap2 = 20;//ap1和ap2同时访问资源会出错----->缺陷


	Raii::auto_ptr<int> ap3;
	ap3 = ap2;
}

int main(){
	TestAuto1();
	return 0;
}



#endif

#if 0
//改进---->资源管理权的转移,对资源进行释放的权利,不让对象与资源完全脱离关系
//mutable bool _owner;  // 资源真正的拥有者(资源的释放者),两种状态:true和false

namespace bite
{
	template<class T>
	class auto_ptr
	{
	public:
		// RAII
		auto_ptr(T* ptr = nullptr)
			: _ptr(ptr)
			, _owner(false)//先给权限为false
		{
			if (_ptr)
			{
				_owner = true;//如果用户提供资源,改为true
			}
		}

		~auto_ptr()
		{
			if (_ptr && _owner)//有资源+有权利
			{
				delete _ptr;
				_owner = false;
				_ptr = nullptr;
			}
		}

		// 类似指针的行为
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		T* get()
		{
			return _ptr;
		}

		auto_ptr(const auto_ptr<T>& ap)
			: _ptr(ap._ptr)
			, _owner(ap._owner)
		{
			ap._owner = false;//之前的对象对资源没有了释放权
		}

		auto_ptr<T>& operator=(const auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				if (_ptr && _owner)//有资源+有权利
				{
					delete _ptr;
				}

				_ptr = ap._ptr;
				_owner = ap._owner;
				ap._owner = false;
			}

			return *this;
		}
	private:
		T* _ptr;
		mutable bool _owner;  // 资源真正的拥有者(资源的释放着)
		//mutable可以改变被const修饰对象
	};
}

//实例化
void TestAutoPtr()
{
	bite::auto_ptr<int> ap1(new int);
	bite::auto_ptr<int> ap2(ap1);

	*ap1 = 10;
	*ap2 = 20;//这时可以同时访问资源,并且资源被释放一次

	bite::auto_ptr<int> ap3;
	ap3 = ap2;

	//缺陷
	if (true)
	{
		// ap3将资源以及其释放权利转移给ap4
		// ap4在销毁时已经将资源释放了,此时会出错
		bite::auto_ptr<int> ap4(ap3);
	}

	// 野指针
	*ap3 = 10;
}


#endif



//资源独占,不允许发生拷贝和赋值的智能指针unique_ptr
//缺陷:不支持拷贝赋值
#if 0

namespace bite
{
	template<class T>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr = nullptr)
			: _ptr(ptr)
		{}

		~unique_ptr()
		{
			if (_ptr)
			{
				delete _ptr;
				_ptr = nullptr;
			}
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		// 防止被拷贝
		// C++98
		//private:只声明不定义,给成私有
		//	unique_ptr(const unique_ptr<T>&);只声明不定义
		//	unique_ptr<T>& operator=(const unique_ptr<T>& ap);

		// C++11 delete:禁止默认成员函数的生成
		unique_ptr(const unique_ptr<T>&) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>& ap) = delete;

	private:
		T* _ptr;
	};
}

class A
{
public:
	A(int a)
		: _a(a)
	{}

	A() = default;


private:
	int _a;
};

void TestA()
{
	A a1(10);
	A a2;
}

void TestUniquePtr()
{
	bite::unique_ptr<int> up1(new int);
	//bite::unique_ptr<int> up2(up1);

	bite::unique_ptr<int> up3;
	//up3 = up1;
}

#endif

//shared_ptr：共享类型智能指针
/*
share_ptr的原理:通过引用计数的方式来实现多个share_ptr对象之间共享资源
1.share_ptr在其内部,给每个资源都维护着一份计数,用来记录该份资源被几个对象共享
2.在对象被销毁时(也就是析构函数调用),就说明自己不使用该份资源了,对象的引用计数减一
3.如果引用计数是0,则说明自己是最后一个使用该份资源的对象,必须释放该资源
4.如果不是0,则说明还有对象在使用该资源,不能释放资源,否则会产生野指针
5.share_ptr本身也存在浅拷贝问题,但是资源由最后一个使用的对象来释放
*/

#if 0
namespace bite
{
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			: _ptr(ptr)
		{
			if (_ptr)
				_count = 1;
		}

		shared_ptr(shared_ptr<T>& sp)
			: _ptr(sp._ptr)
		{
			_count++;
		}

		~shared_ptr()
		{
			if (_ptr && 0 == --_count)
			{
				delete _ptr;
				_ptr = nullptr;
			}
		}
	private:
		T* _ptr; // 资源
		static int _count;
	};

	template<class T>
	int shared_ptr<T>::_count = 0;
}

void TestSharedPtr()
{
	bite::shared_ptr<int> sp1(new int);
	bite::shared_ptr<int> sp2(sp1);

	bite::shared_ptr<int> sp3(new int);
}


int main()
{
	TestSharedPtr();
	return 0;
}
#endif

#if 0


namespace bite
{
	// 只能管理new的资源
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			: _ptr(ptr)
			, _pCount(nullptr)
		{
			if (_ptr)//用户给资源,count给成1
				_pCount = new int(1);
		}

		//拷贝构造,资源共享,计数指针共享
		shared_ptr(const shared_ptr<T>& sp)
			: _ptr(sp._ptr)
			, _pCount(sp._pCount)
		{
			if (_ptr)//资源存在才能给计数指针解引用再加1,所以先判断
				++(*_pCount);
		}
		//三种情况:
		// sp2:没有管理资源 --->与sp1直接共享
		// sp2: 独自管理资源 
		// sp2: 与其他对象共享资源  --->计数-1
		// sp2 = sp1
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (this != &sp)
			{
				// 让当前对象与之前管理的资源断开联系
				release();

				// 让当前对象与sp共享资源
				_ptr = sp._ptr;
				_pCount = sp._pCount;
				if (_ptr)
					++(*_pCount);
			}

			return *this;
		}

		~shared_ptr()
		{
			release();
		}

		int use_count()
		{
			return *_pCount;//获取引用计数
		}

	private:
		void release()
		{
			//如果存在资源,并且count--之后等于0,释放资源
			if (_ptr && 0 == --*_pCount)
			{
				delete _ptr;
				_ptr = nullptr;

				delete _pCount;
				_pCount = nullptr;
			}
		}
	private:
		T* _ptr; // 资源
		int* _pCount;  // 指向计数的空间
	};
}

void TestSharedPtr1()
{
	bite::shared_ptr<int> sp1(new int);
	bite::shared_ptr<int> sp2(sp1);
	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;

	bite::shared_ptr<int> sp3(new int);
	cout << sp3.use_count() << endl;
}

void TestSharedPtr2()
{
	// 	bite::shared_ptr<int> sp1(new int);
	// 	bite::shared_ptr<int> sp2;
	// 
	// 	// sp2没有管理资源
	// 	sp2 = sp1;

	// 	bite::shared_ptr<int> sp1(new int);
	// 	bite::shared_ptr<int> sp2(new int);
	// 	sp2 = sp1;

	bite::shared_ptr<int> sp1(new int);
	bite::shared_ptr<int> sp2(new int);
	bite::shared_ptr<int> sp3(sp2);

	sp2 = sp1;
}

int main()
{
	//TestSharedPtr1();
	TestSharedPtr2();
	return 0;
}

//缺陷:
// 所有资源是采用delete方式进行释放
// 正确释放方式：根据资源的类型去释放
// 析构资源时，析构方式必须灵活
#endif



//使用仿函数改进:让一个类可以按照函数的方式进行调用
// new
template<class T>
class DFDel
{
public:
	void operator()(T*& p)
	{
		if (p)
		{
			delete p;
			p = nullptr;
		}
	}
};

// malloc的资源
template<class T>
class Free
{
public:
	void operator()(T*& p)
	{
		if (p)
		{
			free(p);
			p = nullptr;
		}
	}
};

//文件
class FClose
{
public:
	void operator()(FILE*& pf)
	{
		if (pf)
		{
			fclose(pf);
			pf = nullptr;
		}
	}
};
namespace bite
{
	template<class T, class DF = DFDel<T> >//模板参数列表中加上释放的仿函数
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr = nullptr)
			: _ptr(ptr)
			, _pCount(nullptr)
		{
			if (_ptr)
				_pCount = new int(1);
		}

		shared_ptr(const shared_ptr<T>& sp)
			: _ptr(sp._ptr)
			, _pCount(sp._pCount)
		{
			if (_ptr)
				++(*_pCount);
		}

		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (this != &sp)
			{
				// 让当前对象与管理资源断开联系
				release();

				// 让当前对象与sp共享资源
				_ptr = sp._ptr;
				_pCount = sp._pCount;
				if (_ptr)
					++(*_pCount);
			}

			return *this;
		}

		~shared_ptr()
		{
			release();
		}

		int use_count()
		{
			return *_pCount;
		}

	private:
		void release()
		{
			if (_ptr && 0 == --*_pCount)
			{
				//delete _ptr;
				//DF df;
				//df.operator()(_ptr);
				DF()(_ptr);//DF 可以当做函数用,调用释放

				_ptr = nullptr;

				delete _pCount;
				_pCount = nullptr;
			}
		}
	private:
		T* _ptr; // 资源
		int* _pCount;  // 指向计数的空间
	};
}

void TestSharedPtr()
{
	bite::shared_ptr<int> sp1(new int);
	bite::shared_ptr<int, Free<int>> sp2((int*)malloc(sizeof(int)));
	bite::shared_ptr<FILE, FClose> sp3(fopen("1.txt", "w"));
}

int main()
{
	TestSharedPtr();
	return 0;
}