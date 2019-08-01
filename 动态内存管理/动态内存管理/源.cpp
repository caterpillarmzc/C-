#include <iostream>
#include <stdlib.h>
using namespace std;

class Date
{
public:
	Date(int year=2019,int month=7,int day=25)
		:_year(year)
		,_month(month)
		,_day(day)
	{
		cout << "Date()" << endl;
	}

	~Date()
	{
		cout << "~Data()" << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};
//new申请空间不需要判空,不需要类型转化
int main(){
	//new和malloc只能申请和释放单个的空间
	//使用new申请空间
	Date* pd = new Date;
	delete pd;//释放

	//但是如果使用malloc,申请到的是一块大小与Date相同的空间,并且不会调用类的构造函数,存放随机值
	Date*pd2 = (Date*)malloc(sizeof(Date));
	free(pd2);
	//申请多个空间,使用new[]和delete[]
	Date* pd3 = new Date[10];
	delete[] pd3;

	//new申请内置类型的空间
	int *p1 = new int;
	int *p2 = new int(10);
	int *p3 = new int[10];//连续空间
	int *p4 = new int[10]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};//连续空间并且初始化

	delete p1;
	delete p2;
	delete[] p3;
	delete[] p4;
	return 0;
}

