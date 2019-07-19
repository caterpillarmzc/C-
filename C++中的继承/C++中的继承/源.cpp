using namespace std;
#include <iostream>
#include <string>
#if 0
//继承
/*
继承是使代码复用的重要手段,允许在保持原有类特性的基础上进行扩展
增加功能,产生的新类成为派生类,父类也称为基类
*/

//基类
class Person
{
public:
	void Print(){
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
protected:
	string _name = "mike";
	int _age = 18;

};

//派生类1
class Student:public Person//注意格式,:public表示继承方式,如果不加public的话,class默认是private,struct默认是public
{
protected:
	int _sutID;
};

//派生类2
class Teacher:public Person
{
protected:
	string _job;
};
/*
继承后父类的成员(成员函数+成员变量)都会变成子类的一部分
两个派生类复用了父类的成员
总结:
1.基类private成员在派生类中不论以何种继承方式都是不可见的,
不可见是指基类的私有成员还是继承到了派生类中,但是语法限制
派生类对象无论在类内还是类外都不能访问它
2.基类private成员在派生类中不能被访问,如果积累成员不想被在类外被访问
但是需要在派生类中可以被访问,就定义为protected,所以保护乘员限定符是因为继承而出现的
3.访问方式:public>protected>private,实际上一般都是用public继承,其他两个很少用
*/
#endif


#if 0
//基类和派生类对象赋值转换
/*
派生类对象可以赋值给基类的对象/基类的指针/基类的引用,
但是基类对象不能赋值给派生类对象
基类的指针可以通过强制类型转换赋值给派生类的指针,
但是必须是基类的指针是指向派生类对象是才是安全的*/

class Person
{
public:
	void Print(){
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
protected:
	string _name = "mike";
	int _age = 18;

};

class Student :public Person//注意格式,:public表示继承方式,如果不加public的话,class默认是private,struct默认是public
{
public:
	int _sutID;
};
void Test(){
	//1.子类对象可以赋值给基类对象/指针/引用
	Student sobj;
	Person pobj = sobj;
	Person* pp = &sobj;
	Person& rp = sobj;

	//2.基类对象不能赋值给派生类对象
	//sobj = pobj;

	//3.基类的指针可以通过前置类型转换赋值给派生类的指针
	pp = &sobj;
	Student* ps1 = (Student*)pp;//转换为派生类的指针
	ps1->_sutID = 10;
}

int main(){
	void Test();
}


#endif


#if 0


//继承中的作用域
/*1.在继承体系中基类和派生类都有独立的作用域
2.子类和父类中有同名成员,子类成员将屏蔽父类对同名成员的直接访问
这叫做函数隐藏,也叫重定义,(在子类成员函数中,可以使用 基类::基类成员  显示访问)
只要函数名相同就构成隐藏,实际使用最好不要定义同名函数*/

//派生类的六个默认成员数
/*派生类的构造函数必须调用基类的构造函数来初始化属于基类的那一部分成员
如果基类没有默认的的构造函数,则必须在派生类狗凹函数的初始化列表显式调用
同样,派生类的拷贝构造函数和赋值运算符的重载也都要调用基类的来完成基类那一部分成员的操作
派生类的析构函数会在被调用完成之后自动调用基类的析构函数,这样才能保证先清理派生类再清理基类
派生类对象初始化先调用基类构造再调用派生类构造
派生类对象析构先调用基类的析构再调用基类析构,因为需要先初始化基类,再调用派生类*/
//基类
class Base
{
public:
	Base(int b)//基类构造函数
		:_b(b)
	{
		cout << "Base(int)" << endl;
	}

	Base(Base& b)//基类拷贝构造函数
		:_b(b._b)
	{
		cout << "Base(Base)" << endl;
	}

	Base& operator=(const Base& b){
		if (this!= &b)
		{
			_b = b._b;//用基类对象给当前对象赋值
		}
		return *this;
	}

	~Base(){
		cout << "Base()" << endl;
	}
protected:
	int _b;

};
//派生类
class Derived:public Base
{
public:
	Derived(int b,int d)
		:Base(b)//显示将基类构造函数调用
		,_d(d)//再初始化自己的成员
	{
		cout << "derived(int)" << endl;
	}
	Derived(Derived& d)
		:Base(d)//显示调用基类拷贝构造函数
		,_d(d._d)
	{
		cout << "Derived(Derived&)" << endl;
	}
	Derived& operator-(const Derived& d){
		if (this!=&d)
		{
			Base::operator=(d);//用基类的赋值初始化基类的部分
			_d = d._d;
		}
		return *this;
	}
	~Derived(){
		cout << "Derived()" << endl;
		//自动调用基类的析构函数
		//call Base::~Base();
	}
protected:
	int _d;

};

int main(){
	Derived d1(10,20);
	Derived d2(d1);
	Derived d3(30,40);
	d1 = d3;
	return 0;
}

#endif


#if 0
//友元关系不能继承,也就是说基类友元不能访问子类的私有和保护成员
class Base
{
	friend void Print();//基类的友元函数
public:
	Base(int b=0)//基类构造函数
		:_b(b)
	{ }
protected:
	int _b;
};

class Derived :public Base
{
public:
	Derived(int b, int d)
		:Base(b)
		, _d(d)
	{}
private:
	int _d;
};
void Print(){
	Base b;
	b._b = 10;
	Derived d(1, 2);
	//d._d = 10;   //友元关系不能继承,不能访问派生类
}
int main(){
	void Print();
}


#endif

