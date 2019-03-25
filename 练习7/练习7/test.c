//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//void menu()
//{
//	printf("***********************************\n");
//	printf("***********  1.开始游戏 ***********\n");
//	printf("***********  0.结束游戏 ***********\n");
//	printf("***********************************\n");
//}
//
//void game()
//{
//	int i = 0;
//	int ret = 0;
//	ret = rand() % 100 + 1;
//	while (1)
//	{
//		printf("请输入1-100的数字：");
//		scanf("%d", &i);
//		if (i>ret)
//		{
//			printf("高了\n");
//		}
//		else if (i<ret)
//		{
//			printf("低了\n");
//		}
//		else
//		{
//			printf("恭喜你！猜对了\n");
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("请选择：\n");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("游戏结束\n");
//			break;
//		default:
//			printf("输入有误，请重新输入\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}





/*//写代码可以在整型有序数组中查找想要的数字， 
//找到了返回下标，找不到返回 - 1.（折半查找）
#include<stdio.h>
#include<stdlib.h>
int main(){
	int arr[] = { 7, 8, 9, 10, 11 };
	int to_find = 7;
	int left = 0;
	int mid = 0;
	//总的字节数/一个所占的字节数,再减一即为最后一个的下标
	int right =  sizeof(arr) /sizeof(arr[0]-1);
	while (left <= right){
		int mid = (left + right) / 2;
		if (to_find > arr[mid]){
			left = mid + 1; 
		}
		else if (to_find < arr[mid]){
			right = mid - 1;
		}
		else{ 
			break;
		}
	}
	if (left <= right){
		printf("找到了,下标为:%d\n", mid);
	}
	else{
		printf("-1\n");
	}
	system("pause");
	return 0;

}*/



//编写代码模拟三次密码输入的场景。 
//最多能输入三次密码，密码正确，提示“登录成功”, 密码错误，
//可以重新输入，最多输入三次。三次均错，则提示退出程序。
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h> 
//#include<windows.h>
//int main()
//{
//	int psw[10] = { 0 };
//	int i = 0;
//	for (i = 0; i < 3; ++i)
//	{
//		printf("请输入密码:");
//		scanf("%s", psw);
////strcmp函数是用来比较2个字符串的函数，
////如srcmp（字如果符串1，字符串2），从第一个字符开始比较，
////如果到最后两个字符串完全相同，则strcmp（）函数输出的值为0；
////若开始出现不同的字符，根据这个字符ASCII码进行比较，若字符串1的ASSCII值大于2
////则输出值 大于 0；反之，输出值 小于 0；
//		
//		if (strcmp("123456", psw) == 0)
//		{
//			printf("登陆成功\n");
//			break;
//		}
//		else
//		{
//			printf("密码错误\n");
//		}
//	}
//	if (i == 3)
//	{
//		printf("三次密码输入错误，退出系统！\n");
//	}
//	system("pause");
//	return 0;
//}




//编写一个程序，可以一直接收键盘字符，
//如果是小写字符就输出对应的大写字符，
//如果接收的是大写字符，就输出对应的小写字符，
//如果是数字不输出。
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//void main()
//{
//	char c = 'a';
//	printf("请输入一个键盘字符c:");
//	scanf("%c", &c);
//	if (c >= 'A' && c <= 'Z')
//	{
//		c = c + 32;
//	}
//	else if (c >= 'a' && c <= 'z')
//	{
//		c = c - 32;
//	}
//	printf("%c\n", c);
//	system("pause");
//}
