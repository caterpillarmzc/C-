#include <iostream>
using namespace std;
/*
初始化列表的作用:
初始化类中的成员变量
每个成员变量在初始化列表中只能出现一次(初始化只能初始化一次)
如果初始化列表没有显示给出,编译器会自动完成初始化列表的功能,赋随机值
但是函数体中可以赋值多次
类中包含以下成员，必须放在初始化列表位置进行初始化： 
引用成员变量 
const成员变量 
类类型成员(该类没有默认构造函数)
*/
#if 0
//时间类的构造函数:非缺省值的构造函数
class Time
{
public:
	Time(int hour,int minute,int second)
		:_hour(hour)
		,_minute(minute)
		,_second(second)
	{

	}
protected:
private:
	int _hour;
	int _minute;
	int _second;
};
//在日期类中包含一个时间类的对象
class Date
{
public:
	Date(int year, int month, int day)
		:_year(year)
		, _month(month)
		, _day(day)
		,_a(year)//引用类型的成员变量初始化
		,_c(year)//const成员变量初始化
		,_t(0,0,0)//对类类型成员初始化
	{}
private:
	int _year;
	int _month;
	int _day;
	int & _a;
	const int _c;
	Time _t;

};

#endif
#if 0
//尽量使用初始化列表进行初始化,因为不管你是否使用初始化列表,对于自定义类型的成员变量,一定会使用初始化列表初始化

class A
{
public:
	A(int a = 10)
		: _a(a)
	{
		cout << "A::A()" << endl;
	}
private:
	int _a;
};

class B
{
public:
	B()
		//: _a(10)    即使没有给出,编译器也会自动完成这步操作
	{

	}

private:
	A _a;
};

int main(){
	B b;
	return 0;
}
#endif
class Date
{
public://声明次序
	Date(int year, int month)
		:_year(year)
		, _day(month)
		,_month(_day)
	{}
private://初始化次序
	int _year;
	int _day;
	int _month;
	/*int _year;这种写法month不能初始化成功,
	int _month;成员变量在构造函数初始化规则:按照成员在类中声明的先后次序来进行初始化
	int _day;  而不是按照在初始化列表中出现的先后次序*/
};//尽量不要使用成员来初始化成员,最好按照声明次序来初始化成员

int main(){
	Date d(2019, 7);
	return 0;
}