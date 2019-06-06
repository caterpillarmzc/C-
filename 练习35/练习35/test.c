//一元一瓶汽水，喝完后两个空瓶子换一瓶汽水，问：有20块钱，最多可以喝多少瓶水？
#include <stdio.h>
int money(double money, int sum)
{
	while (money >= 1)
	{
		sum = sum + (int)money;
		money = ((int)money) * 0.5 + money - (int)money;
		printf("money = %f\n", money);
	}
	return sum;
}
void main()
{
	int sum = 0;
	sum = money(20.0, 0);
	printf("%d\n", sum);
}


/*一个函数求任意多个整数的平均值(使用可变参数列表)
可变参数列表作用：可以处理任意多的参数。
可变参数列表实现方法：可变参数列表是通过宏来实现的，这些宏定义于stdarg.h头文件中，它是标准库的一部分。
这个头文件声明一个类型va_list 和三个宏va_start、va_arg和va_end。
我们可以声明一个类型为va_list的变量，与这几个宏配合使用，访问参数。
各个变量的作用：
声明一个va_list 类型的变量arg，它用于访问参数列表的未确定部分，这个变量是调用va_start来初始化的，
它的第一个参数是va_list的变量名，第2个参数是省略号前最后一个有名字的参数。
初始化过程把arg变量设置为指向可变参数部分的第一个参数。
为了访问参数，需要使用va_arg，这个宏接受两个参数：va_list变量和参数列表中下一个参数的类型。
va_arg返回这个参数的值，并使用va_arg指向下一个可变参数。
最后，当访问完毕最后一个可变参数之后，我们需要调用va_end*/
#include<stdio.h>
#include<stdarg.h>

int average(int val, ...)
{
	va_list arg;
	int count = 0;
	int sum = 0;

	va_start(arg, val);
	for (count = 0; count < val; count++)
	{
		sum += va_arg(arg, int);
	}
	va_end(arg);

	return sum / val;
}
int main()
{
	int ret = average(3, 2, 4, 6);
	printf("平均数为：%d\n", ret);
	return 0;
}

//有一个字符串是 student a am i, 现将字符串转换为 i am a student 空间复杂度为 : O(1)


#include<stdio.h>
#include<assert.h>
void my_reverse(char* left, char* right)
{
	assert(left);
	assert(right);

	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

int my_strlen(char *str)//得到数组长度定义求取字符串长度的函数
{
	assert(str);
	int count = 0;
	while (*str++)
	{
		count++;
	}
	return count;
}

void Reverse(char s[])
{
	assert(s);
	char* start = s;
	char* end = s + my_strlen(s) - 1;
	char* cur = NULL;

	my_reverse(start, end);

	while (*s)
	{
		cur = s;
		while (*s != '\0' && *s != ' ')
		{
			s++;
		}
		end = s - 1;
		my_reverse(cur, end);
		if (*s == ' ')
		{
			s++;
		}
	}
}

int main()
{
	char s[] = "student a am i";
	Reverse(s);
	printf("%s\n", s);
	return 0;
}


//百度笔试题  使用c语言编写函数 unsigned int reverse_bit(unsigned int value);
//这个函数的返回值value的二进制模式从左到右翻转后的值
//00000000000000000000000000011001  翻转前  25
//10011000000000000000000000000000  翻转后
//程序结果返回： 2550136832
#include<stdio.h>

int reverse_bit(unsigned int value)
{
	int ret = 0;
	int bit = 0;
	for (int i = 0; i < 32; i++)
	{
		ret = ret << 1;		//左移一位，保存前一位  
		bit = value & 1;	//取出最后一位  
		value = value >> 1;	//值右移，取下一位  
		ret = bit | ret;	//最后一位赋给ret  
	}
	return ret;
}

int main()
{
	unsigned int value = 25;
	unsigned int ret = reverse_bit(value);
	printf("%u\n", ret);
	return 0;
}
