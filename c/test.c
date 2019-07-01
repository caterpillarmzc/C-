#define  _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
int main(){
	int a = 10;
	int b = 20;
	int temp;
	a = b;
	temp = a;
	b = temp;
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	system("pause");
	return 0;
}
#endif
#if 0


#include<stdio.h>
int main(){
	int a = 10;
	int b = 20;
	int*p1 = &a;
	int*p2 = &b;
	int tmp;
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	system("pause");
	return 0;
}
#endif
#if 0


//不创建临时变量,交换ab的值
#include <stdio.h>
int main(){
	int a=10;
	int b=20;
	a = a^b;
	b = a^b;
	a = a^b;
	printf("a=%d\n", a);
	printf("b=%d\n", b);
	system("pause");
	return 0;
}
#endif

#if 0
//求两个数的最大公约数
int main(){
	int a;
	int b;
	printf("a=");
	scanf("%d", &a);
	printf("b=");
	scanf("%d", &b);

	if (a > b)
	{
		int c = a%b;
		while (c != 0)
		{
			a = b;
			b = c;
			c = a%b;
		}

		printf("最大公约数是:%d", b);
	}
	else
	{
		int d = b%a;
		while (d != 0)
		{
			b = a;
			a = d;
			d = b%a;
		}

		printf("最大公约数是:%d", a);
	}
	system("pause");
	return 0;
}
#endif

#if 0
//将三个整数从大到小输出
#include<stdio.h>
int main(){
	int a, b, c, t;
	printf("输入三个整数:");
	scanf("%d %d %d", &a, &b, &c);
	if (a > b);
	else
	{
		t = a, a = b, b = t;
	}
	if (a > c);
	else
	{
		t = a, a = c, c = t;
	}
	if (b > c);
	else
	{
		t = b, b = c, c = t;
	}
	printf("%d>%d>%d", a, b, c);
	system("pause");
	return 0;

}

#endif
//求十个整数的最大值
#include <stdio.h>
int main(){
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 }, i, max=a[0];
	for (i = 0; i < 10; i++)
	{
		if (max < a[i])
			max = a[i];
	}
	printf("%d", max);
	system("pause");
	return 0;
}
