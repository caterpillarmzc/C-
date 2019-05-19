//输入一行字符，分别统计出其中英文字母、空格、数字和其它字符的个数
#include<stdio.h>
int main()
{
	char c;
	int letters = 0, spaces = 0, digits = 0, others = 0;
	printf("请输入一些字母：\n");
	while ((c = getchar()) != '\n')
	{
		if ((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z'))
			letters++;
		else if (c >= '0'&&c <= '9')
			digits++;
		else if (c == ' ')
			spaces++;
		else
			others++;
	}
	printf("字母=%d,数字=%d,空格=%d,其他=%d\n", letters, digits, spaces, others);
	return 0;
}

//猴子吃桃问题：猴子第一天摘下若干个桃子，当即吃了一半，还不瘾，又多吃了一个 //第二天早上又将剩下的桃子吃掉一半，又多吃了一个。以后每天早上都吃了前一天剩下 //的一半零一个。到第10天早上想再吃时，见只剩下一个桃子了。求第一天共摘了多少 #include <stdio.h>
#include <stdlib.h>
int main(){
	int day, x1 = 0, x2;
	day = 9;
	x2 = 1;
	while (day > 0) {
		x1 = (x2 + 1) * 2;  // 第一天的桃子数是第2天桃子数加1后的2倍
		x2 = x1;
		day--;
	}
	printf("总数为 %d\n", x1);

	return 0;
}

//有5个人坐在一起，问第五个人多少岁？他说比第4个人大2岁。问第4个人岁数，
//他说比第3个人大2岁。问第三个人，又说比第2人大两岁。问第2个人，
//说比第一个人大两岁。最后问第一个人，他说是10岁。请问第五个人多大？
#include <stdio.h>

int age(n)
int n;
{
	int c;
	if (n == 1) c = 10;
	else c = age(n - 1) + 2;
	return(c);
}
int main()
{
	printf("%d\n", age(5));
}