#if 0
//命名空间
#include<stdio.h>
namespace N1//N1为命名空间的名称
{
	//命名空间的内容既可以定义变量,也可以定义函数
	int a;
	int Add(int left,int right){
		return left + right;
	}
}

//命名空间可以嵌套
namespace N2
{
	int a;
	int b;
	int Add(int left, int right){
		return left + right;
	}
	namespace N3
	{
		int c;
		int d;
		int sub(int left,int right){
			return left - right;
		}
	}
}
//同一个工程中允许存在多个相同名称的命名空间
//编译器最后会合成在同一个命名空间中
//一个命名空间就定义了一个新的作用域,命名空间中的所有内用都继续按与该命名空间中

//命名空间的使用

//加命名空间名称及作用域限定符
int main(){
	printf("%d\n", N1::a);
	return 0;
}

//使用using将命名空间中成员引入
using N2::b;
int main(){
	printf("%d\n", N2::a);
	return 0;
}

//使用using namespace命名空间名称引入
using namespace N1;
int main()
{
	printf("%d\n", N2::a);
	printf("%d\n", b);
	Add(10, 20);
	return 0;
}
#endif

/*C++的输入输出
头文件 #include <iostream>
C++的标准库在std命名空间下实现,一般使用<iostream>+std的方式
标准输入 cin
标准输出 cout
C++不需要增加数据格式控制,比如:--%d,字符--%c*/

#include <iostream>
using namespace std;

int main(){
	int a;
	double b;
	char c;

	cin >> a;
	cin >> b >> c;
	cout << a << endl;
	cout << b << " " << endl;
	return 0;
}


//缺省参数
//缺省参数是声明或定义函数时为函数的参数指定一个默认值
//在调用该函数时,如果没有指定实参则采用该默认值,否则使用指定的实参
void TestFunc(int a=0){
	cout << a << endl;
}
int main(){
	TestFunc();//没有传参时,使用参数的默认值
	TestFunc(10);//传参时,使用指定的实参
}

//全缺省参数
void TestFunc(int a=10, int b = 10, int c = 20){
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
}
//半缺省参数
void TestFunc(int a,int b=10,int c=20){
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
}
/*注意:
半缺省参数必须从左到右依次来给出,不能间隔着给
缺省参数不能在函数声明和定义中同时出现
缺失值必须是常量或者全局变量
C语言不支持*/


/*函数重载
函数重载:是函数的一种特殊情况，C++允许在同一作用域中声明几个功能类似的同名函数，
这些同名函数的 形参列表(参数个数 或 类型 或 顺序)必须不同，
常用来处理实现功能类似数据类型不同的问题
只因为返回值不同不能形成重载*/

int Add(int left,int right){
	return left + right;
}

double Add(double left,double right){
	return left + right;
}

/*名字修饰
程序运行经历的阶段:预处理--编译--汇编--链接
C++编译器对函数名字修饰规则:将参数的类型编译到函数的名字中
例如       int Add(double left,int right)
格式为     ?Add@@YAhnh@Z
@表示函数结束,YA表示参数开始,@Z表示参数列表结束,H-- int,N-- double
C语言不支持函数重载;C语言对函数名字的修饰规则相对简单,
只见一个"_",同名函数无法区分调用哪个函数
如果在C++中想要使用c格式库, 则需要加一个
extern"c"在int Add(int left, int right);之前
这是寻找库就按照c语言格式_Add寻找*/

//引用
/*引用不是新定义一个变量，而是给已存在变量取了一个别名，编译器
不会为引用变量开辟内存空间，它和它 引用的变量共用同一块内存空间
类型&引用变量名(对象名)=引用实体*/
void TestRef(){
	int a = 10;
	int &ra = a;//<===定义引用类型
	printf("%p\n", &a);
	printf("%p\n", &ra);

}
//引用在定义时必须初始化
//一个变量可以有多个引用
//引用类型必须和引用实体是同一类型的
//实体为常量时,引用必须也是常量
//引用一旦引用一个实体,再不能引用其他实体
引用的使用场景
1.做参数
void Swap(int left,int right){
	int temp = left;
	left = right;
	right = temp;
}
2.做返回值
int& Test(int& a){
	a += 10;
	return a;
}
/*注意：如果函数返回时，离开函数作用域后，其栈上空间已经还给系统，
因此不能用栈上的空间作为引 用类型返回。如果以引用类型返回，
返回值的生命周期必须不受函数的限制(即比函数生命周期长)。*/

/*交换函数的两种方式
传值:传参效率低,不能通过形参改变实参,函数副作用不影响外部实参
传指:传参效率高,可以通过形参改变实参,不安全,指针需要判空,可读性较差
引用和指针的不同点 :
1. 引用在定义时必须初始化，指针没有要求 
2. 引用在初始化时引用一个实体后，就不能再引用其他实体，而指针可以在任何时候指向任何一个同类型 实体 
3. 没有NULL引用，但有NULL指针 
4. 在sizeof中含义不同：引用结果为引用类型的大小，但指针始终是地址空间所占字节个数(32位平台下占 4个字节) 
5. 引用自加即引用的实体增加1，指针自加即指针向后偏移一个类型的大小 
6. 有多级指针，但是没有多级引用 
7. 访问实体方式不同，指针需要显式解引用，引用编译器自己处理 
8. 引用比指针使用起来相对更安全*/

/*内联函数
以inline修饰的函数叫做内联函数，编译时C++编译器会在调用内联函数的地方展开，
没有函数压栈的开销， 内联函数提升程序运行的效率。
特性
1. inline是一种以空间换时间的做法，省去调用函数额开销。所以代码很长或者有循环 / 递归的函数不适宜 使用作为内联函数
2. inline对于编译器而言只是一个建议，编译器会自动优化，如果定义为inline的函数体内有循环/递归等 等，编译器优化时会忽略掉内联。 
3. inline不建议声明和定义分离，分离会导致链接错误。因为inline被展开，就没有函数地址了，链接就会找不到*/


//auto关键字
int TestAuto(){
	return 10;
}
int main(){
	int a = 10;
	auto b = a;
	auto c = 'a';
	auto d = TestAuto();
	auto e;//auto e;无法通过编译,使用auto定义变量是必须对其进行初始化
	return 0;
}

/*使用auto定义变量时必须对其进行初始化，在编译阶段编译器需要根据初始化表达式来推导auto的实际类 型。
因此auto并非是一种“类型”的声明，而是一个类型声明时的“占位符”，编译器在编译期会将auto替换为 变量实际的类型
auto 使用细则
1. auto与指针和引用结合起来使用
用auto声明指针类型时，用auto和auto*没有任何区别，但用auto声明引用类型时则必须加&
如 int main(){
int x=10;
auto a=&x;
auto*b=&x;
auto& c=x;
}
2. 在同一行定义多个变量
当在同一行声明多个变量时，这些变量必须是相同的类型，否则编译器将会报错，
如 auto c=3,d=4.0;编译失败,因为c和d的初始化表达式类型不同
因为编译器实际只对 第一个类型进行推导，然后用推导出来的类型定义其他变量。
3. auto不能作为函数的参数,如void TestAuto(auto a){}
4.auto不能直接用来声明数组,如void TestAuto(){ auto b[]={1,2,3}}
5. auto不能定义类的非静态成员变量*/


//基于范围的for循环
//for循环后的括号由冒号“ ：”分为两部分：
//第一部分是范围内用于迭代的变量， 第二部分则表示被迭代的范围。
void TestFor(){
	int array[] = { 1, 2, 3, 4, 5 };
	for (auto&e : array)
		e *= 2;
	for (auto e : array)
		c << e << " ";
	return 0;
}
//注意：与普通循环类似，可以用continue来结束本次循环，也可以用break来跳出整个循环。
//范围for的使用条件
//对于数组来说,范围就是数组第一个元素和最后一个元素的范围;
//对于类而言,应该提供begin和end的方法,begin到end就是for循环迭代的范围
//迭代的对象要实现++和==的操作

//指针空值nullptr
//nullptr代表一个指针空值常量,类型为nullptr_t,仅仅可以被隐式转换为指针类型.
//1. 在使用nullptr表示指针空值时，不需要包含头文件，因为nullptr是C++11作为新关键字引入的。
//2. 在C++11中，sizeof(nullptr) 与 sizeof((void*)0)所占的字节数相同。
//3. 为了提高代码的健壮性，在后续表示指针空值时建议好使用nullptr
