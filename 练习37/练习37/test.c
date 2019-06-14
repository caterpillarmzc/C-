//输入一个正整数n，再输入n个学生的成绩，计算平均分，并统计不及格成绩的学生人数
#define _CRT_SECURE_NO_WARNINGS
/*#include <stdio.h>
#include <stdlib.h>

int main()
{
	int count, i, n;
	double grade, total;

	printf("Enter n:");
	scanf("%d", &n);
	total = 0;
	count = 0;
	for (i = 1; i <= n; i++){
		printf("Enter grade#%d:", i);
		scanf("%lf", &grade);
		total = total + grade;
		if (grade < 60){
			count++;
		}
	}
	printf("Grade average=%.2f\n", total / n);
	printf("Number of failures=%d\n", count);
	system("pause");
	return 0;
}
*/

//求解简单的四则运算表达式，输入一个形式如“操作数 
//运算符  操作数”的四则运算表达式，输出运算结果
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
	double value1, value2;
	char op;
	printf("Type in an expression:");
	scanf("%lf%c%lf", &value1, &op, &value2);

	if (op == '+')
		printf("=%.2f\n", value1 + value2);
	else if (op == '-')
		printf("=%.2f\n", value1 - value2);
	else if (op == '*')
		printf("=%.2f\n", value1*value2);
	else if (op == '/')
		printf("=%.2f\n", value1 / value2);
	else printf("Unknown operator\n");

	return 0;
}*/
//输入10个字符，统计其中英文字母、数字字符和其他字符的个数。
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int digit, letter, other;
	char ch;
	int i;
	digit = letter = other = 0;
	printf("Enter 10 characters:");
	for (i = 1; i <= 10; i++)
	{
		ch = getchar();
		if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z'))
			letter++;
		else if (ch >= '0'&&ch <= '9')
			digit++;
		else other++;
	}
	printf("letter=%d,digit=%d,other=%d\n", letter, digit, other);
	return 0;
}

