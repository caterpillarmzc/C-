#include <stdio.h>

int BinSearch_Recursion(int Array[], int low, int high, int key);

//递归方法
int BinSearch_Recursion(int Array[], int len, int key)
{
	//如果传入的数组为空或者数组长度<=0那么就返回-1。防御性编程
	if (Array == NULL || len <= 0)
		return -1;
	return BinSearch_Recursion(Array, 0, len - 1, key);
}

int BinSearch_Recursion(int Array[], int low, int high, int key)  /*传入参数分别是找到的数组Array，数组起始位置，数组结束位置，要找的数组*/
{
	if (low <= high)
	{
		//int mid = (low+high)/2;  
		int mid = low + (high - low) / 2;//为了防止变量溢出
		if (key == Array[mid])
			return mid;
		else if (key<Array[mid])
			return BinSearch_Recursion(Array, low, mid - 1, key);
		else if (key>Array[mid])
			return BinSearch_Recursion(Array, mid + 1, high, key);
	}
	else
		return -1;
}

//非递归方法
int BinSearch(int Array[], int len, int key)  /*传入参数分别是数组地址Array，数组长度len，要找的数据key  返回值为key的位置*/
{
	//防御性编程
	if (Array == NULL || len <= 0)
		return -1;

	int low = 0, high = len - 1;
	int mid;
	while (low <= high)
	{
		//mid = (low+high)/2;  
		mid = low + (high - low) / 2;//为了防止变量溢出
		if (key == Array[mid])
			return mid;
		if (key<Array[mid])
			high = mid - 1;
		if (key>Array[mid])
			low = mid + 1;
	}
	return -1;
}

int main(void)
{
	int a[6] = { 0, 5, 20, 30, 88.102 };
	int len = sizeof(a) / sizeof(a[0]);
	int locate = 0, locate_recursion;
	locate = BinSearch(a, len, 88);
	locate_recursion = BinSearch_Recursion(a, len, 20);//根据参数个数选择执行的函数
	printf("%d  %d\n", locate, locate_recursion);
	return 0;
}
