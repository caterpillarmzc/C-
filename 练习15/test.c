//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分。
//#include <stdio.h>
//#include <stdlib.h>
//void func(int *a,int size)
//{
//	int i = 0; //左边元素的下标
//	int j = size - 1;//右边元素的下标
//	for (i = 0; i != j;i++)
//	{if (a[i]%2!=0)//判断两个指针的奇偶性
//	{
//		continue;
//	}
//	else
//	{
//		//交换位置
//		int t = a[i];
//		a[i] = a[j];
//		a[j] = t;
//		if (a[j]%2==0)
//		{
//			j--;
//		}
//		j--;
//	 }
//	}
//}
//
//int main(){
//	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8 ,9};
//	int size = sizeof(a) / sizeof(a[0]);//获取元素个数size
//	int i;
//	func(a, size);//调用函数
//	for (i = 0; i < size;i++)
//	{
//		printf("%d", a[i]);
//	}
//	system("pause");
//	return 0;
//}

//2.杨氏矩阵 
//有一个二维数组.
//数组的每行从左到右是递增的，每列从上到下是递增的.
//在这样的数组中查找一个数字是否存在。
//时间复杂度小于O(N);
//#include <stdio.h>
//#include <stdlib.h>
//
//#define ROW 3
//#define COL 3
//int func(int arr[ROW][COL], int row, int col, int num)
//{
//	int left = 0;
//	int right = col - 1;
//	while ((left >= 0) && (right < col))
//	{
//		//如果这个数字小于num，后移一位；
//		if (arr[left][right] < num)
//		{
//			left++;
//		}
//		//如果这个数字小于num，前移一位；
//		if (arr[left][right] > num)
//		{
//			right--;
//		}
//		if (arr[left][right] == num)
//		{
//			return 1;
//		}
//	}
//	return 0;
//
//}
//int main()
//{
//	int arr[ROW][COL] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int key = 9;
//	int ret = func(arr, ROW, COL, key);
//	if (ret==1)
//	{
//		printf("找到了\n");
//	}
//	if (ret==0)
//	{
//		printf("没找到\n");
//	}
//
//	system("pause");
//	return 0;
//}

