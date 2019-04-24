#include <stdio.h>
void Swap(int *x,int *y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
void Bubble(int arr[],int size)
{
	int bound = 0;
	for (; bound < size;++bound)
	{
		for (int cur = size - 1; cur>bound;--cur)
	{if (arr[cur-1]>arr[cur])
		{
			Swap(&arr[cur - 1], &arr[cur]);
	}
	}
	}
}
int main(){
	int arr[5] = { 100, 32, 56, 200, 1 };
	Bubble(arr, 5);
	for (int i = 0; i < 5;++i)
	{
		printf("%d\n",arr[i]);
	}
	system("pause");
	return 0;
}