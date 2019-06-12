//快速排序,去基准值,左同时向中间靠拢
//左边遇到大的停止,右边遇到小的停止
//交换大小数的位置,两个指针到同一位置时,与基准值交换
//最终结果是小..基准值..大

#include <stdio.h>
#include <stdlib.h>
//基准值的取法随意时,容易造成时间复杂度很高的情况
//三数取中法:取三个数,左端右端,中间,选择大小处于中间的数作为基准值
int GetMiddleIndex(int *array,int left,int right){
	int mid = left + ((right - left) >> 1);
	if (array[left]<array[right-1]){
		if (array[mid] < array[left])
			return left;
		else if (array[mid]>array[right - 1])
			return right - 1;
		else
			return mid;
	}
	else{
		if (array[mid]>array[left])
			return left;
		else if (array[mid] < array[right - 1])
			return right - 1;
		else
			return mid;
	}
}



//快排方法1
int Partion1(int *array,int left,int right){
	int begin = left;
	int end = right - 1;
	int mid = GetMiddleIndex(array, left, right);//调用求基准值的函数
	Swap(&array[mid], &array[right - 1]);//交换最右边元素与基准值
	int key = array[right - 1];
	while (begin<end){
		//从左到右找比基准值大的元素,找到后停止
		while (begin<end&&array[begin]<=key)
		{
			begin++;
		}
	}
}


//快排方法2
int Partion2(int* array,int left,int right){
	int cur = left;    //此处的代码可以用基准值的选取优化
	int prer = cur;    //int mid=GetMiddleIndex(array,left,right);
	int key = array[right - 1];     //Swap(&array[mid],&array[right-1]);
	while (cur<right){
		if (array[cur] < key&&++prer != cur)
			Swap(&array[cur], &array[prer]);
		++cur;
	}
	if (++prer != right)
		Swap(&array[prer], &array[right - 1]);
	return prer;
}

//快排方法3---挖坑法
//基准值先设为最后一个值,即 key=array[right-1]
//首位为begin,末尾为end
//把你准直挖走,end为空,从前往后把第一个大于key的值放入end
//从end开始往前遍历,找到比key小的填begin的坑,循环直到相遇
//再用key填入相遇的坑

int Partion3(int* array,int left,int right){
	int begin = left;
	int end = right - 1;
	int key = array[right - 1];
	while (begin<end){   //从前往后找比key打的元素,找到后填充end
		while (array[begin] <= key)
			begin++;
		if (begin<end){//填充end位置的坑
			array[end] = array[begin];
			end--;
		}
		while (begin < end&&array[end] >= key)  //从后往前找比基准值小的元素,找到后填充begiin
			end--;
		if (begin<end){
			array[begin] = array[end];
			begin++;
		}
	}
	array[begin] = key;
	return begin;
}



//测试以上三种方法
void QuickSort(int* array,int left,int right){
	if (right-left>1){
		int div = Partion1(array, left, right);//按照基准值将区间分割成左右两部分,小于..基准..大于
		QuickSort(array, left, div);
		QuickSort(array, div + 1, right);
	}
}

//用递归的方式快速排序
void QuickSort(int*array,int left,int right){
	if (right - left < 16)
		InsertSort(array, right - left);//元素个数小于16时,用插入排序提高效率
	else{
		int div = Partion1(array, left, right);//按照基准值将区间分割成左右两部分,小于..基准..大于
		QuickSort(array, left, div);
		QuickSort(array, div + 1, right);
	}
}//空间复杂度O(NlogN)   N为递归深度


//用循环的方式快速排序--用到栈
#include "Stack.h"
void QuickSortNor(int *array,int size){
	int left = 0;
	int right = size;
	Stack s;
	StackInit(&s);
	StackPush(&s, right);  //压栈,先压右,在压左,取出时先取左
	StackPush(&s, left);
	while (!StackEmpty(&s)){//若栈不为空
		left = StackTop(&s);
		StackPop(&s);
		right = StackTop(&s);
		StackPop(&s);
		if (right-left>1){//如果个数小于1,则循环继续
			int div = Partion1(array, left, right);
			//两个区间[left,div)和[div+1,right)
			StackPush(&s, right);//保存右半区间
			StackPush(&s, div+1);
			StackPush(&s, div);//保存左半区间
			StackPush(&s, left);

		}
	}
}