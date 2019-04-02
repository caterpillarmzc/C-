//#include<stdio.h>
//#include<stdlib.h>
//int count = 0;     //加了一个计数器
//int fib(int n)
//{
//	if (n == 3)     //我们求第n个数的时候第三个数被计算了count 次
//		count++;
//
//	if (n <= 2)
//	{
//		return 1;
//	}
//	else
//		return fib(n - 1) + fib(n - 2);
//}
//int main()
//{
//	int n = 0;
//	printf("求第n个斐波那契数:");
//	scanf("%d", &n);
//	printf("%d\n", fib(n));
//
//	printf("count = %d", count);   
//	system("pause");
//	return 0;
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int fib(int n)
{
	int a = 1;
	int b = 1;
	int c = 0;
	int i = 0;
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}
int main()
{
	int n = 0;
	printf("求出第n个斐波那契数:n=");
	scanf("%d", &n);
	printf("%d\n", fib(n));

	system("pause");
	return 0;
}