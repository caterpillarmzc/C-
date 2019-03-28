//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<stdio.h>
//#include <windows.h>
//
//void print(int n)
//{
//	int x = 0;
//	for (x = 1; x <= n; x++)
//	{
//		int y = 0;
//		for (y = 1; y <= x; y++)
//		{
//			int z = 0;
//			z = x*y;
//			
//			printf("%d*%d=%d ", y, x, z);
//		}
//		printf("\n");
//	}
//	return;
//}
//
//int main()
//{
//	int n = 0;
//	printf("请输入行数：");
//	scanf("%d", &n);
//	print(n);
//	system("pause");
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//void swap(int *a, int *b){
//	int tmp;
//	tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//int main(){
//	int a =0;
//	int b =0;
//	printf("请输入两个整数\n");
//	printf("a = ");
//	scanf("%d", &a);
//	printf("b = ");
//	scanf("%d", &b);
//	swap(&a, &b);
//	printf("a=%d,b=%d", a, b);
//	system("pause");
//	return 0;
//}
//#include <stdio.h>
//int IsLeapYear(int year){
//	if((year% 4 == 0 && year / 100 != 0) || (year % 400 == 0))
//		return 1;
//else
//return 0;
//}
//int main ()
//{
//	int a = 0;
//	int b = 0;
//	printf("请输入年份：");
//	scanf_s("%d", &a);
//	b = IsLeapYear(a);
//	if (b == 1)
//		printf("是闰年\n");
//else
//printf("不是闰年!\n");
//system("pause");
//return 0;
//}
//#include<stdio.h>
//#include<string.h>
//void init(int arr[10])               //初始化数组
//{
//	int j = 0;
//	for (j = 0; j <= 9; j++)
//	{
//		arr[j] = j;
//	}
//}
//void empty(int arr[10], int SZ)             //清空数组
//{
//	memset(arr, 0, SZ*sizeof(arr[0]));
//}
//void reverse(int arr[10], int SZ)           //逆置数组元素
//{
//	int i = 0;
//	int temp = 0;
//	for (i = 0; i < SZ / 2; i++)
//	{
//		temp = arr[i];
//		arr[i] = arr[SZ - 1 - i];
//		arr[SZ - 1 - i] = temp;
//	}
//}
//int main()
//{
//	int arr[10] = { 1, 2, 3, 6, 5, 4, 2 };
//	int SZ = sizeof(arr) / sizeof(arr[0]);
//	empty(arr, SZ);                  //清空数组
//	init(arr);                       //初始化数组
//	reverse(arr, SZ);                 //数组元素逆置
//	int i = 0;
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int prime(int a)
{
	int i = 0;
	int k = 0;
	k = sqrt(a);
	for (i = 2; i <= k; i++)
	{
		if (a%i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int a;
	int sushu;
	printf("请输入一个大于1的正整数：");
	scanf("%d", &a);
	sushu = prime(a);
	if (sushu == 1)
	{
		printf("是素数\n", a);
	}
	else
	{
		printf("不是素数\n", a);
	}
	system("pause");
	return 0;
}




