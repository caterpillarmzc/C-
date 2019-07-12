#define  _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <string.h>
#include <iostream>
#include <stdio.h>

#if 0
struct Student 
{
	void SetStudentInfo(const char* name,const char*gender,int age)
	{
		strcpy(_name, name);
		strcpy(_gender, gender);
		_age = age;
	}
	void PrintStudentInfo(){
		cout << _name << " " << _gender << " " << _age << endl;
	}
	char _name[20];
	char _gender[3];
	int _age;
};

int main(){
	Student s;
	s.SetStudentInfo("peter", "man", 18);
	system("pause");
	return 0;
}
#endif

#if 0
class Person{
public:
	void PrintPersonInfo();
private:
	char _name[20];
	char _gender[3];
	int _age;
};

void Person::PrintPersonInfo(){
	//表明PrintPersonInfo属于Person这个类域
	cout << _name << "" << _gender << "" << _age << endl;
}
#endif

//类的实例化
class Person{
public:
	void showinfo();
	char* _name;
	char* _sex;
	int _age;
};

void Test(){
	Person man;
	man._name = "hack";
	man._age = 20;
	man._sex = "男";
	man.showinfo();
}
