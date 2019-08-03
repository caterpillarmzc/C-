#include <iostream>
using namespace std;
#if 0


class Person{
public:
	virtual void BuyTicket(){
		cout << "buy ticket " << endl;
	}
};

class Student:public Person{
public:
	virtual void BuyTicket(){
		cout << "buy ticket " << endl;
	}
};


class A
{
public:
	virtual void f() final {}
};
class B :public A
{
public:
	virtual void f(){}

};
class Person{
public:
	virtual A* f(){
		return new A;
	}
};
class Student:public Person{
public:
	virtual B* f(){
		return new B;
	}
}; 


//检测虚函数是否被重写的两个关键字
class A
{
public:
	virtual void f(){}
};
class B :public A
{
public:
	virtual void f()override{}

};


class A
{
public:
	virtual void f() final {}
};
class B :public A
{
public:
	virtual void f(){}

};
#endif

#if 0


class Person
{
public:
	virtual void Ticket() = 0;
};

class Student :public Person
{
public:
	virtual void Ticket()
	{
		cout << "50% off" << endl;
	}
};

class Soldier :public Person
{
public:
	virtual void Ticket()
	{
		cout << "first priority " << endl;
	}
};

void Test(){
	Person* pStudent = new Student;
	pStudent->Ticket();

	Person* pSoldier = new Soldier;
	pSoldier->Ticket();
}

int main(){
	Test();
	return 0;
}
#endif

class Base
{
public:
	virtual void Func(){
		cout << "Func()" << endl;
	}
	virtual void Func2(){
		cout << "Func2()" << endl;
	}
	void Func3(){
		cout << "Func3()" << endl;
	}
private:
	int _b = 1;
};

class Dev :public Base
{
public:
	virtual void Func(){
		cout << "Func()" << endl;
	}
	virtual void Func4(){
		cout << "Func4()" << endl;
	}
private:
	int _d = 2;
};

//打印虚表
//传基类对象的指针或引用,不光可以打印基类的虚表,还可以打印派生类的虚表.
//基类的引用可以直接引用派生类的对象
typedef void(*P)();
void Print(Base &b)
{//从对象的前四个字节中获取虚表的地址
	P* p=(P*)*(int*)&b;//用P*类型的变量p将转换的地址接收一下
//通过虚表指针获取虚函数的入口地址并调用
	while (*p)
	{
		(*p)();//对p这个指针解引用,相当于调用该函数
		++p;
	}
}

int main(){
	Base b;
	Dev d;
	cout << "Base:" << endl;
	Print(b);
	cout << "Dev:" << endl;
	Print(d);
	return 0;
}