#if 0

//将数组a和数组b中的内容交换,两个数组的大小相等
#include<stdio.h>
int main(){
	int arrA[] = { 1, 2, 3, 4, 5 };
	int arrB[] = { 6, 7, 8, 9, 0 };
	int size = sizeof(arrB) / sizeof(arrB[1]);
	int i = 0;
	for (; i < size;i++){
		int tmp = arrA[i];
		arrA[i] = arrB[i];
		arrB[i] = tmp;
	}
	printf("arrA=");
	for (i=0; i < size; i++){
		printf("%d", arrA[i]);	
	}
	printf("\n");
	printf("arrB=");
	for (i = 0; i < size; i++){
		printf("%d", arrB[i]);	
	}
	system("pause");
	return 0;
}
#endif


//计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值
#include <stdio.h>
int main(){
	int i = 1;
	double sum = 0;
	int flag = 1;
	for (i=1; i <= 100;i++)
	{
		sum += flag*(1.0 / i);
		flag = -flag;
	}
	printf("sum=%lf\n", sum);
	system("pause");
	return 0;
}
