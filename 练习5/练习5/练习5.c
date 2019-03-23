#include<stdio.h>
#include<stdlib.h>
//int Factor(int n){
//	int result = 1;
//	for (int i = 1; i <= n; ++i){
//		//i的值每次都与result的值相乘再赋给result
//		result *= i;
//	}
//	return result;
//}
//char str1[] = "welcome to my computer!";
//char str2[] = "#######################";
//int left = 0;
//int right = strlen(str2) - 1;
//while (left <= right){
//	printf("%s\n", str2);
//	str2[left] = str1[left];
//	str2[right] = str1[right];
//	++left;
//	--right;


//查找语句
//int main(){
//	int arr[4] = { 1, 2, 3, 4 };
//	int to_find = 7;
//	int i = 1;
//	//如果要把for里的表达式一提前到全局变量
//	//i++后边要加;或者把表达式一看做空语句
//	 for (; i < 4; i++) {
//		if (arr[i] == to_find){
//			//break,printf两端务必加;
//			break;
//		}
//	}
//	if (i < 4){
//	printf("get it!");
//}
//	else{
//		printf("none!\n");
//	}
//	system("pause\n");
//	return 0;
//}
//二分查找
int main(){
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int to_find = 2;
	int left = 0;
	int right = 9;
	while (left <= right){
		int mid = (left + right) / 2;
		if (arr[mid] < to_find){
			left = mid + 1;
		}
		else if (arr[mid]>to_find){
			right = mid - 1;
		}
		else{
			
			break;
		}
	}
	if (left <= right){
		printf("get it!\n");
	}
	else{
		printf("none\n");
	}



	system("pause\n");
	return 0;
}