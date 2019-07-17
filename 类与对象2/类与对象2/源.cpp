#include <stdio.h>
#include <iostream>
using namespace std;

#if 0
//构造函数
class Date
{
public:
	//带参构造函数
	Date(int year, int month, int day){
		_year = year;
		_month = month;
		_day = day;
	}
#if 0
	//无参构造函数
	Date(){

	}
	//全缺省构造函数,即给一个初始值
	Date(int year = 2019, int month = 7, int day = 16){
		_year = year;
		_month = month;
		_day = day;
	}
#endif
	void SetDate(int year, int month, int day){
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate(){
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

void TestDate(){
	Date d1(2019, 7, 16);//调用有参构造函数
	Date d2();//调用无参构造函数
	d1.PrintDate();

}
/*如果类中没有显式定义构造函数,则编译器会自动生成一个无参的默认构造函数,
若用户定义,则不再生成
无参构造函数和全缺省的构造函数都称为默认构造函数,但是只能存在一个
一般用全缺省
注意:无参构造函数,全缺省构造函数,编译器自动生成的构造函数都可以认为是默认成员函数

*/
int main(){
	TestDate();
}

/*
构造函数是一个特殊的成员函数,名字与类名相同,创建类类型对象时由编译器
自动调用,保证每个数据成员都有一个合适的初始值,并且在对象生命周期内只调用一次
构造函数没有返回值类型,不用加void
一个类中,构造函数可以有多个,对象参数不同,构造函数不同
构造函数主要任务不是在空间中创建对象,而是初始化对象
构造函数的特征:
1.函数名与类名相同
2.无返回值
3.对象实例化时编译器自动调用对应的构造函数
4.构造函数可以重载
*/
#endif

#if 0
class Date
{
public:
	// 全缺省的构造函数
	Date(int year = 1900, int month = 1, int day = 1) //冒号之后是初始化参数列表
		: _year(year)
		, _month(month)
		, _day(day)
	{
		// 一旦进入到构造函数体中，对象已经创建成功
		// 进行的是赋值，不是初始化,函数体就不再写以下内容了,而是写其他内容
		//_year = year;
		//_month = month;
		//_day = day;

	}
	//拷贝构造函数同样
	Date(const Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{}


private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2019, 6, 16);
	Date d2(d1);
	return 0;
}
#endif

#if 0
//析构函数

#include <assert.h>
#include <malloc.h>
typedef int DataType;

class SeqList{
public:
	SeqList(size_t capacity=3){
		_array = (DataType*)malloc(sizeof(DataType)*capacity);
		if (nullptr==_array)
		{
			assert(0);
			return;
		}
		_capacity = capacity;
		_size = 0;
	}
		//析构函数
	~SeqList(){
			if (_array)
			{
				free(_array);
				_array = nullptr;
			}
		}
private:
	DataType* _array;
	size_t _size;
	size_t _capacity;
};

void TestSeqlist(){
	SeqList s;
}
/*
析构函数不是完成对象的销毁,销毁是由编译器完成的,而是在对象销毁时
自动调用析构函数,完成类的一些资源清理工作
(堆上的空间需要用析构函数释放)
析构函数的特性:
1.析构函数是在类名前加上取反符号~
2.无参数无返回值不能重载
3.一个类有且只有一个析构函数,未显式定义则编译器自动生成默认的的析构函数
4.对象生命周期结束时,C++编译系统自动调用析构函数
5.编译器生成的默认析构函数,会对自定类型成员调用它的析构函数
*/
int main(){
	TestSeqlist();
	return 0;
}


#endif

#if 0


//拷贝构造函数
class Date{
public:
	//全缺省的构造函数
	Date(int year=2019,int month=7,int day=16){
		_year = year;
		_month = month;
		_day = day;
	}
	//拷贝构造函数
	Date(const Date& d){
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	void SetDate(int year, int month, int day){
		_year = year;
		_month = month;
		_day = day;
	}
	void PrintData(){
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

void TestDate(){
	Date d1;
	//Date d2(2019,7,16);
	Date d3(d1);//使用d2拷贝构造d3
}
int main(){
	TestDate();
	return 0;
}
/*
拷贝构造函数:
只有单个形参,该形参是对本类类型对象的引用(常用const修饰)
用const修饰的目的是复制期间不改变原参数内容
在用已存在的类类型对象创建新对象时由编译器自动调用
拷贝构造函数的特征:
1.拷贝构造函数是构造函数的重载形式(同一作用域,名字相同,参数列表不同)
2.拷贝构造函数的参数只有一个且必须使用引用传参(例如Date&d或者Date d3(d2)用d2构造d3),
  使用传值方式会引发无穷递归调用
3.若未显式定义,则系统生成默认的拷贝构造函数,默认的拷贝构造函数
按对象内存存储按字节序完成拷贝,这种拷贝我们称之为浅拷贝或者值拷贝
浅拷贝导致多个对象共用一份资源,多次释放会导致程序崩溃
*/
#endif


#if 0
//运算符的重载
class Date{
public:
	//全缺省的构造函数,即给一个初始值
	Date(int year = 2019, int month = 7, int day = 16){
		_year = year;
		_month = month;
		_day = day;
	}
	//拷贝构造函数
	Date(const Date& d){
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	void SetDate(int year, int month, int day){
		_year = year;
		_month = month;
		_day = day;
	}
	void PrintData(){
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	
	//运算符重载
	Date operator+(int days){//注意这里如果用Date&,,表示返回值不能是栈上的空间,而tmp就是栈上的空间,出了作用域,tmp就会被销毁
		Date tmp(*this);//创建一个临时对象来保证+之后原本的day不变
		tmp._day += days;
		return tmp;
	}
	//如果把其当做全局函数时,需要两个参数d1和d2,但是在类中定义时,this指针也算一个参数
	bool operator ==(const Date &d){
		return _year == d._year &&
			_month == d._month &&
			_day == d._day;
	}
	bool operator !=(const Date &d){
		return _year == d._year &&
			_month == d._month &&
			_day == d._day;
	}
#if 0
	//或者
	bool operator ==(const Date &d){
		return !(*this == d);
	}
#endif
	// 前置++
	Date& operator++()
	{
		_day += 1;
		return *this;//返回+1之后的新的值
	}

	// 后置++
	Date operator++(int)
	{
		Date temp(*this);
		_day += 1;
		return temp;//返回+1之前的旧值
	}


	Date& operator--()
	{
		_day -= 1;
		return *this;
	}

	Date operator--(int)
	{
		Date temp(*this);
		_day -= 1;
		return temp;
	}

	//赋值运算符重载
	/*
	赋值运算符需要注意的几点
	1.参数类型
	2.返回值
	3.检测自己给自己赋值
	4.返回*this
	5.如果没有显示定义赋值运算符重载,则编译器也会生成一个,但是是浅拷贝
	*/
	Date& operator=(const Date& d){
		if (this != &d)//排除自己给自己赋值的情况
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;//注意返回值为引用
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	int a = 10;
	int b = 10;
	int c = 100;

	a = b = c;//不能连续赋值
	Date d1(2019, 6, 16);
	Date d2(2019, 6, 17);
	Date d3(2019, 6, 18);
	Date& d4 = d1;
	d4 = d1;//相当于自己给自己赋值
	//d1 = d2;   //等价于 d1.operator=(d2); //  底层Date::operator=(&d1, d2);

	//d1 = d2 = d3;  //实际上的赋值顺序:d1 = (d2 = d3)
	d1.operator=(d2.operator=(d3));

	return 0;
}
/*
C++为了加强代码的可读性引入了运算符重载,运算符重载是具有特殊函数名的函数
也具有其返回值,函数名及其参数列表,其返回值与参数列表与普通函数类似
函数名字为:关键字operator后面接需要重载的运算符的符号
函数原型:返回值类型operator操作符(参数列表)
注意:
不能通过连接其他运算符号来创建新的操作符,如operator@
重载操作符必须有一个类类型或者枚举类型的操作数,即必须要有一个自定义类型的参数
用于内置类型的操作符,其含义不能改变,例如:内置的整形+,不能改变其含义
作为类成员的重载函数时,其形参看起来比操作数数目少1,成员函数的操作符
有一个默认的形参this,限定为第一个形参
.*   ;;   sizeof  ?:   .
以上五个运算符不能形成重载
*/


#endif
class Date
{
public:
	Date(int year, int month, int day){
		_year = year;
		_month = month;
		_day = day;
	}

	// const成员函数中不能修改成员变量
	// const修饰this指针，表明：当前对象中的内容不允许被修改

	

	// this指针的类型Date* const  表明this指针不能修改,但是成员变量可以修改
	void PrintDate()
	{
		_day = 1;
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	// this指针的类型const Date* const  表明this指针指向的地址和地址保存的内容都不能修改
	void PrintDate()const
	{
		//this->_day = 1;
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	//以上两个函数可以形成重载


	bool operator==(const Date& d)const
	{
		//_day = 1;
		//d._day = 1;
		return _year == d._year &&
			_month == d._month &&
			_day == d._day;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main(){
	Date d(2019, 7, 17);
	d.PrintDate();
	cout << &d << endl;
	return 0;
}

/*
注意:
1.const对象不可以调用非const成员函数,但是非const对象可以调用const成员函数,相当于只读
2.const成员函数内不可以调用其他非const成员函数,但是非const成员函数内可以调用其他的const成员函数

*/

