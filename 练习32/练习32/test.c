//分别用while和for写一个程序。程序让用户输入一个n，然后计算1到n的和。
//#include<stdio.h>
//int main()
//{
//	int n;
//	int sum = 0, i = 1;
//	scanf("%d", &n);
//	while (i <= n)
//	{
//		sum += i;
//		i++;
//	}
//	printf("%d\n", sum);
//	return 0;
//}
//
//#include<stdio.h>
//int main()
//{
//	int n;
//	int sum = 0, i;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		sum += i;
//	}
//	printf("%d\n", sum);
//	return 0;
//}
//
//编写一个程序，程序实现用户输入两个数，计算他们的最小公倍数和最大公约数
//
//
//#include<stdio.h>
//
//int main()
//{
//	int n, m, temp, sum;
//	scanf("%d%d", &n, &m);
//	sum = n*m;
//	if (n < m)
//	{
//		temp = n;
//		n = m;
//		m = temp;
//	}
//	while (n%m != 0)
//	{
//		temp = m;
//		m = n%m;
//		n = temp;
//	}
//	printf("最大公约数是%d\n", m);
//	printf("最小公倍数是%d\n", sum / m);//最小公倍数是这两个数的乘积除以最大公约数 
//	return 0;
//}