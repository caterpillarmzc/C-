//有1、2、3、4个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？
//#include<stdio.h>
//
//int main()
//{
//	int i, j, k;
//	printf("\n");
//	for (i = 1; i < 5; i++) { // 以下为三重循环
//		for (j = 1; j < 5; j++) {
//			for (k = 1; k < 5; k++) { // 确保i、j、k三位互不相同
//				if (i != k&&i != j&&j != k) {
//					printf("%d,%d,%d\n", i, j, k);
//				}
//			}
//		}
//	}
//}

//将一个正整数分解质因数。例如：输入90,打印出90=2*3*3*5
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//int main()
//{
//	int n, i;
//	printf("请输入整数：");
//	scanf("%d", &n);
//	printf("%d=", n);
//	for (i = 2; i <= n; i++)
//	{
//		while (n%i == 0)
//		{
//			printf("%d", i);
//			n /= i;
//			if (n != 1) printf("*");
//		}
//	}
//
//	printf("\n");
//	return 0;
//}

//一球从100米高度自由落下，每次落地后反跳回原高度的一半；再落下，
//求它在第10次落地时，共经过多少米？第10次反弹多高？
//#include<stdio.h>
//int main()
//{
//	float h, s;
//	h = s = 100;
//	h = h / 2; //第一次反弹高度
//	for (int i = 2; i <= 10; i++)
//	{
//		s = s + 2 * h;
//		h = h / 2;
//	}
//	printf("第10次落地时，共经过%f米，第10次反弹高%f米\n", s, h);
//	return 0;
//}


//练习函数调用
#include <stdio.h>
void hello_world(void)
{
	printf("Hello, world!\n");
}
void three_hellos(void)
{
	int counter;
	for (counter = 1; counter <= 3; counter++)
		hello_world();/*调用此函数*/
}
int main(void)
{
	three_hellos();/*调用此函数*/
}