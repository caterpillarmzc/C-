#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <stdlib.h>
int main()
{
	//当按照W方式打开文件时,会清空文件的原有内容
	/*FILE* fp = fopen("E:/test.txt","a");
	char str[] = "hahahahah";
	fwrite(str,1,strlen(str),fp);*/
	//read和write最终显示的是读取或者写入的内容
	/*FILE* fp = fopen("E:/test.txt", "r");
	char buf[1024] = "haha";
	size_t n=fread(buf, 1, sizeof(buf), fp);
	printf("buf=%s\n",buf);
	printf("%d\n", n);
	fclose(fp);*/

	FILE* fp = fopen("E:/test.txt", "w");
	int x = 10;
	//将字符写入到txt中,
	//fprintf(fp,"x=%d", x);
	//将字符输出到屏幕上
	//fprintf(stdout,"x=%d\n", x);
	//sprintf是忘一个字符数组中输出一个格式化字符串
	char buf[1024] = { 0 };
	sprintf(buf,"x=%d\n",x);
	//从语言中可以使用sprintf实现讲一个数字(整数,浮点数)转化为一个字符串
	sprintf(buf, "%d", x);
	int y = 0;
	//sscanf正好相反
	sscanf(buf, "%d", &y);
	printf("y=%d\n", y);
	printf("%s\n", buf);
	fclose(fp);
	system("pause");
	return 0;
}