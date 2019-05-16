//计算一个程序的运行时间
#include<stdio.h>
#include<time.h>
#include<windows.h>
int main()
{
	int start = 0;
	int end = 0;
	start = clock();
	for (int i = 0; i < 10000; i++)
	{
		for (int i = 0; i < 10000; i++)
		{
		}
	}
	end = clock();
	printf("%d\n", end - start);
	system("pause");
	return 0;

}

//计算十个整数中的最大值
int main()
{
	int i, j;
	int temp = 0;
	int arr[10] = {};
	//int arr[10] = { 11, 33, 44, 66, 87, 90, 99, 65, 48, 77 };
	for (i = 0, j = 1; j <= 10; j++)
	{
		scanf("%d", arr);
		if (arr[i] <= arr[j])
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = arr[i];
		}
	}
	printf("%d\n", arr[i]);
	system("pause");
	return 0;
}


//交换两个整数的值
int main()
{
	int temp = 0;
	int a = 50;
	int b = 100;
	printf("%d %d\n", a, b);
	temp = a;
	a = b;
	b = temp;
	printf("%d %d\n", a, b);
	system("pause");
	return 0;
}
