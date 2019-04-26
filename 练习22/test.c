#define _CRT_SECURE_NO_WARNINGS
//#include <errno.h>
//#include<stdio.h>
//int main(){
//	FILE*fp = fopen("test.txt", 'r');//句柄,通过内存来操作外存
//	//FILE为文件打开操作,test.txt为文件名,r为打开方式
//	if (fp==NULL){
//		printf("%d\n", strerror(errno));
//	}
//	printf("error\n");
//	return 1;
//}

#include <stdio.h>
#include <errno.h>
int main(){
	//FILE* fp = fopen ("./test.txt", "r");
	////返回值为一个指针    路径     打开方式
	////FILE为一个结构体
	//if(fp==NULL){
	//	printf("%d\n", strerror(errno));//errno是错误码 发生错误时返回一个值,0为没错
	//	perror("result");
	//	return 1;
	//}
	////读文件是把磁盘上的数据读到内存中
	////申请内存空间buf用来存放读到的数据
	//char buf[1024] = { 0 };
	////读文件fread有四个参数,
	////buf为读到的数据存放的内存,第二个为元素的大小,第三个为元素的个数,再加一个读取位置文件指针
	//fread(buf,1,4,fp);
	//printf("%s\n", buf);


	FILE* fp = fopen("./test.txt", "w");

	//写文件是吧内存中的数据写到磁盘中
	//char buf2[1024] = "hahahaha";
	//fwrite(buf2, 1, 8, fp);
	int x = 1000;
	fprintf(fp, "x=%d", x);
	//stdout为标准输出,会同时输出在屏幕上
	fprintf(stdout, "x=%d\n", x);
	//sprintf是往字符数组中输出一个格式化字符串
	char buf[1024] = { 0 };
	sprintf(buf, "x=%d\n", x);
	printf("%s\n", buf);
	//关闭文件
	fclose(fp);
	system("pause");
	return 0;
}