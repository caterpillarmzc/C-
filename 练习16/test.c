//使用递归的方法求N的阶乘
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int Factor(int n){
//	if (n==1){
//		return 1;
//	}
//	return n*Factor(n - 1);
//}
//int main(){
//	int ret;
//	int i;
//	printf("请输入n= ");
//	scanf("%d", &i);
//	printf("ret=%d\n", Factor(i));
//	system("pause");
//	return 0;
//}

int Fib(int n){
	if (n==1||n==2)
	{
		return 1;
	}
	return Fib(n - 1) + Fib(n - 2);
}
int main(){
	int i;
	int ret;
	printf("请输入n= ");
	scanf("%d", &i);
	printf("ret=%d\n", Fib(i));//递归一般都是这种格式,记住
	system("pause");
	return 0;
}