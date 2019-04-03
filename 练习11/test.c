#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
//int  digui(int n, int k)
//{
//	if (k == 0)
//	{
//		return 1;
//	}
//	else if (k == 1)
//	{
//		return n;
//	}
//	else
//	{
//		return digui(n, k - 1)*n;
//	}
//}
//int main()
//{
//	int n = 0;
//	int k = 0;
//	printf("请输入n和k\n");
//	scanf("%d%d", &n, &k);
//	printf("%d\n", digui(n, k));
//	system("pause");
//	return 0;
//}
//int DigitSum(int n)
//{
//	if (n <= 0)
//		return 0;
//	else if (n > 0 && n < 9)
//		return n;
//	else
//		return(n % 10 + DigitSum(n / 10));
//}
//int main()
//{
//	int n = 0;
//	printf("请输入一个整数\n");
//	scanf("%d", &n);
//	int num = DigitSum(n);
//	printf("%d\n", num);
//	system("pause");
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a = 0, b = 0, c = 0, d = 0, e = 0;
//	for (a = 1; a <= 5; a++)
//	{
//		for (b = 1; b <= 5; b++)
//		{
//			for (c = 1; c <= 5; c++)
//			{
//				for (d = 1; d <= 5; d++)
//				{
//					for (e = 1; e <= 5; e++)
//					{
//						if ((2 == b && 3 != a) || (2 != b && 3 == a) == 1)
//						{
//							if ((2 == b && 4 != e) || (2 != b && 4 == e) == 1)
//							{
//								if ((1 == c && 2 != d) || (1 != c && 2 == d) == 1)
//								{
//									if ((5 == c && 3 != d) || (5 != c && 3 == d) == 1)
//									{
//										if ((4 == e && 1 != a) || (4 != e && 1 == a) == 1)
//										if (a*b*c*d*e == 120)
//										{
//											printf("a= %d, b= %d,c= %d,d= %d,e= %d\n", a, b, c, d, e);
//										}
//									}
//								}
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	system("pause");
//	return 0;
//}
#include<stdio.h>
#include<stdlib.h>
//      A:murderer != A
//      B:murderer == C
//      C:murderer == D
//      D:murderer != D 

//int main()
//{
//	char murderer = 0;
//	for (murderer = 'A'; murderer <= 'D'; murderer++)
//	{
//		if ((murderer != 'A') +
//			(murderer == 'C') +
//			(murderer == 'D') +
//			(murderer != 'D') == 3)
//		{
//			printf("凶手是 %c\n", murderer);
//		}
//	}
//	system("pause");
//	return 0;
//}
#include <stdio.h>
#define N 20
int main()
{
	int i;
	int j;
	//数组为10行10列
	int a[N][N];
	for (i = 0; i < N; i++)
	{
		//使第一列的元素为1
		a[i][0] = 1;
		//使对角线的元素为1
		a[i][i] = 1;
	}
	for (i = 2; i < N;i++)
	{
		for (j = 1; j < i;j++)
		{
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
	}
	}
	for (i = 0; i < N;i++)
	{
		for (j = 0; j < (2 * N - 2 * i);j++)
		{
			printf("");
		}for (j = 0; j <= i;j++)
		{
			//输出各组元素的值
			printf("%10d", a[i][j]);
	}
		printf("\n");
	}
	system("pause");
	return 0;
}
