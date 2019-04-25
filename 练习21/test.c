//练习动态内存管理函数
//malloc
//#include <stdio.h>
//#include<stdlib.h>
//
//int main(){
//	//malloc()中表示的是申请内存空间的大小
//	int *p = (int*)malloc(10 * sizeof(int));
//	for (int i = 0; i < 10;++i )
//	{
//		p[i] = i;
//	}
//	for (int i = 0; i < 10;++i )
//	{
//		printf("%d\n", p[i]);
//	}
//	//内存释放,不释放的话跟随整个程序
//	//如果一直申请但不释放,会引起内存泄漏
//	//后续再申请就申请不到了
//	free(p);
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include<stdlib.h>
//int main()
//{
//	//不是alloc申请的动态内存不能用free
//	//一次申请的动态内存不能释放两次
//	int num = 10;
//	int*p = &num;
//	free(p);
//	//释放后得到的指针是野指针
//	system("pause");
//	return 0;
//}

//#include <stdio.h>
//#include<stdlib.h>
////calloc练习
//int main(){
//	
//	int *p = (int*)calloc (10,sizeof(int));
//	for (int i = 0; i < 10; ++i)
//	{
//		p[i] = i;
//	}
//	for (int i = 0; i < 10; ++i)
//	{
//		printf("%d\n", p[i]);
//	}
//	
//	free(p);
//	system("pause");
//	return 0;
//}

//#include <stdio.h> #include <stdlib.h>
//
//int main() {
//	int *p = calloc(10, sizeof(int));
//	if (NULL != p)    {        //使用空间 
//	}    
//	free(p);
//	p = NULL;
//	system("pause");
//	return 0;
//}

//#include <stdlib.h>
//#include<stdio.h>
//
//int main()
//{
//	char* p = (char *)malloc(100);
//	if (p)
//		printf("内存分配在: %p\n", p);
//	else
//		printf("没有足够内存!/n");
//	char *lcf = (char *)realloc(p, 256);
//	if (lcf)
//		printf("内存重新分配在: %p\n", lcf);
//	else
//		printf("没有足够内存!/n");
//	free(lcf);
//	system("pause");
//	return 0;
//}
