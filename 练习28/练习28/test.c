//宏#define命令练习。
//#include<stdio.h>
//#define TRUE 1
//#define FALSE 0
//#define SQ(x) (x)*(x)
//int main()
//{
//	int num;
//	int again = 1;
//	printf("如果值小于 50 程序将终止。\n");
//	while (again)
//	{
//		printf("\n请输入数字：");
//		scanf("%d", &num);
//		printf("该数字的平方为 %d \n", SQ(num));
//		if (num >= 50)
//			again = TRUE;
//		else
//			again = FALSE;
//	}
//	return 0;
//}


//宏#define命令练习2。
//#include<stdio.h>
//#define exchange(a,b) { int t;t=a;a=b;b=t;}//注意放在一行里
//int main()
//{
//	int x = 10;
//	int y = 20;
//	printf("x=%d; y=%d\n", x, y);
//	exchange(x, y);
//	printf("x=%d; y=%d\n", x, y);
//	return 0;
//}
//宏#define命令练习3。
#define LAG >
#define SMA <
#define EQ ==
#include <stdio.h>
int main()
{
	int i, j;
	printf("请输入两个数字：\n");
	scanf("%d %d", &i, &j);
	if (i LAG j)
		printf("%d 大于 %d \n", i, j);
	else if (i EQ j)
		printf("%d 等于 %d \n", i, j);
	else if (i SMA j)
		printf("%d 小于 %d \n", i, j);
	else
		printf("没有值。\n");
	return 0;
}