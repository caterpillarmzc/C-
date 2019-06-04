//编写一个函数求n的阶乘
//递归
#include<stdio.h>
#include<string.h>
#include<assert.h>
int fa(int n)
{
	if (n <= 1)
	{
		return 1;
	}
	else
	{
		return n*fa(n - 1);
	}
}

int main()
{
	int n = 5;
	int ret = fa(n);
	printf("ret = %d\n", ret);
	system("pause");
	return 0;
}

//编写一个函数，可以分别打印一个整数十进制的每一位
#include<stdio.h>
#include<string.h>
//#include<assert.h>
void print(int n)
{
	if (n > 9)
	{
		print(n / 10);
	}
	printf("%d\n", n % 10);
}
int main()

{
	print(1234);
	system("pause");
	return 0;

}

//编写一个函数实现n^k，使用递归实现
#include<stdio.h>
int pow(int n, int k)
{
	if (k == 0)
	{
		return 1;
	}
	else if (k == 1)
	{
		return n;
	}
	else
	{
		return n*pow(n, k - 1);
	}

}
int main()
{
	int n = 2;
	int k = 3;
	printf("%d\n", pow(n, k));
	system("pause");
	return 0;
}


//不允许创建临时变量求字符串长度，实现strlen的模拟
#include<stdio.h>
#include<assert.h>
int my_strlen_no(char const *p)
{
	assert(p != NULL);
	if (*p == NULL)
	{
		return 0;
	}
	else
	{
		return (1 + my_strlen_no(p + 1));
	}
}
int main()
{
	char *p = "abcdef";
	printf("长度是：%d\n", my_strlen_no(p));
	system("pause");
	return 0;
}

//编写一个函数reverse_string(char * string)（递归实现）
#include<stdio.h>
void reserve_string(char *string)
{
	if (*string == '\0')
		printf("%c", *string);
	else
	{
		reserve_string(++string);//输入下一个字符
		printf("%c", *(--string));
	}
}
int main()
{
	char s[] = "abcdef";
	reserve_string(s);
	system("pause");
	return 0;
}


//写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和
#include<stdio.h>
int dig(int n)
{
	if (n <= 10)
	{
		return 1;
	}
	else
	{
		return (n % 10 + dig(n / 10));

	}
}
int main()
{
	printf("%d\n", dig(1729));
	system("pause");
	return 0;
}
