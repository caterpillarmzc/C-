//在每一行输入两个数，用空格隔开，可以一直输入，结果是两个数相加的和的输出。例如：
//输入 1 2
//4 6
//8 5
//1 2
//输出 3
//10
//13
//3
//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	int i = 0, j, a, b, sum[100] = { 0 };
//	while (scanf("%d %d", &a, &b) != EOF){
//		sum[i] = a + b;
//		i++;
//	}
//	for (j = 0; j < i; j++){
//		printf("%d\n", sum[j]);
//	}
//	return 0;
//}
// while(scanf("%d %d",&a,&b)!=EOF)这条语句表示当输入ctrl+z表示结束时退出while循环！
//
//
//	 先输入一个数n表示有n组数据，然后每一行输入两个数表示一组数据，结果是输入两个数相加的和。例如：
//	 输入：
//	 3
//	 2 3
//	 5 6
//	 6 9
//	 输出：
//	 5
//	 11
//	 15
//#include <stdio.h>
//#include <stdlib.h>
//
//	 int main()
// {
//		 int n, a, b, i = 0, j, sum[100] = { 0 };
//		 scanf("%d", &n);
//		 while (i != n){
//			 scanf("%d %d", &a, &b);
//			 sum[i] = a + b;
//			 i++;
//		 }
//		 for (j = 0; j < i; j++){
//			 printf("%d\n", sum[j]);
//		 }
//		 return 0;
//	 }
//
// 输入多列测试数，每行有一对整数，以输入0 0作为结束输入的标志，结果是输出每一行的和。例：
//
//	 输入： 2 5
//	 3 7
//	 5 8
//	 0 0
//	 输出： 7
//	 10
//	 13
//#include <stdio.h>
//#include <stdlib.h>
//
//	 int main()
// {
//		 int a, b, i = 0, j, sum[100] = { 0 };
//		 while (1){
//			 scanf("%d %d", &a, &b);
//			 if (a == 0 && b == 0){
//				 break;
//			 }
//			 sum[i] = a + b;
//			 i++;
//		 }
//		 for (j = 0; j < i; j++){
//			 printf("%d\n", sum[j]);
//		 }
//		 return 0;
//	 }
//
// 输入多个测试用例，输入的每行测试用例的第一个数表示该行测试的个数，当测试用例的第一个数输入为0时，则表示输入结束，然后将每行相加的结果输出，例：
//
//	 输入： 5 1 2 3 4 5
//	 2 5 6
//	 5 12 2 3 6 5
//	 3 5 6 4
//	 0
//
//	 输出： 15
//	 11
//	 28
//	 15
//
//#include<stdio.h>
//	 int main(){
//		 int t, i = 0, j = 0, sum[100] = { 0 }, a[100] = { 0 };
//		 int k;
//		 while (scanf("%d", &t) != EOF){
//			 if (t == 0){
//				 break;
//			 }
//			 for (i = 0; i < t; i++){
//				 scanf("%d", &a[i]);
//				 sum[j] += a[i];
//			 }
//			 j++;
//		 }
//		 for (k = 0; k < j; k++){
//			 printf("%d\n", sum[k]);
//		 }
//		 return 0;
//	 }
//
// 先输入一个数表示一共有几行输入，然后每行的第一个数表示该行数的个数，结果输出每行的和。例：
//
//	 输入：2
//	 4 1 2 3 4
//	 5 1 2 3 4 5
//
//	 输出：10
//	 15

#include<stdio.h>
	 int main(){
		 int i = 0, j, n, t, d, k = 0, a[100] = { 0 }, sum[100] = { 0 };
		 scanf("%d", &n);
		 while (i != n){
			 scanf("%d", &d);
			 for (j = 0; j < d; j++){
				 scanf("%d", &a[j]);
				 sum[k] += a[j];
			 }
			 k++;
			 i++;
		 }
		 for (t = 0; t < k; t++){
			 printf("%d\n", sum[t]);
		 }
		 return 0;
	 }