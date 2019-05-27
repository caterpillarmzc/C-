
#define _CRT_SECURE_NO_WARNINGS
//有一个数列：8,4,2,1,23,344,12。请循环输出数列的值；求数列中所有数值的和及平均值；猜数游戏，
//即从键盘中任意输入一个数据，判断数列中是否包含此数。

#include <stdio.h>
#include <stdlib.h>

//int main()
//{
//	int i; //循环变量
//	int sum = 0;
//	int searchNum;    //要查找的数字
//	double avg;
//	//定义数组，并初始化
//	int nums[] = { 8, 4, 2, 1, 23, 344, 12 };
//	//循环输出
//	printf("输出数组元素：\n");
//	for (i = 0; i < 7; i++)
//	{
//		printf("%d\t", nums[i]);
//	}
//	printf("\n*****************************\n");
//	//求和及平均值
//	for (i = 0; i < 7; i++)
//	{
//		sum += nums[i];  //经典累加
//	}
//	avg = sum / 7.0;
//	printf("和是%d，平均值为%lf", sum, avg);
//	printf("\n*****************************\n");
//	//查找数字
//	printf("请输入要查找的数字：");
//	scanf("%d", &searchNum);
//	for (i = 0; i < 7; i++)
//	{
//		//一个一个元素进行对比
//		if (searchNum == nums[i])
//		{
//			printf("找到了相同的元素！\n");
//			break;
//		}
//	}
//	
//	//通过观察，循环正常退出时，i的值应该为7
//	if (i == 7){
//		printf("没有找到合适的数字！");
//	}
//	return 0;
//}

//循环录入5个整型数字，进行降序排列后输出结果

//#define N 5  //宏定义，并不是必须的
//
//int main()
//{
//	int i, j;  //循环变量
//	int temp;  //用来交换的临时变量
//	int nums[N] = { 16, 25, 9, 90, 23 };
//	//外层循环控制轮数
//	for (i = 0; i < N - 1; i++)
//	{
//		//内层循环控制每轮的比较次数
//		for (j = 0; j < N - i - 1; j++)
//		{
//			//如果当前值小于后面一个值，就交换
//			if (nums[j] < nums[j + 1])
//			{
//				temp = nums[j];
//				nums[j] = nums[j + 1];
//				nums[j + 1] = temp;
//			}
//		}
//	}
//	printf("排序后的结果是：\n");
//	for (i = 0; i < N; i++)
//	{
//		printf("%d\t", nums[i]);
//	}
//	return 0;
//}

//根据要求操作排行榜战力榜：战力值从大到小排列；
//删除战斗力42322；插入战斗力41000并保持降序

int main()
{
	int count = 5; //表示数组元素的个数
	double powers[5] = { 42322, 45771, 40907, 41234, 40767 };
	double deletePower;   //用户要删除的战力值
	int deleteIndex = -1;   //要删除战力值的下标，给一个不可能的值，方便判断
	int i;             //循环变量
	double insertPower;   //新插入的战力值
	printf("请输入要删除的战力值：");
	scanf("%lf", &deletePower);
	for (i = 0; i < count; i++)
	{
		if (deletePower == powers[i])
		{
			//记录下当前的下标
			deleteIndex = i;
			break;  //找到了要删除的战力值，直接跳出循环，提升效率
		}
	}
	//根据判断(是否找到)，执行后续的操作
	if (-1 == deleteIndex)
	{
		printf("没有找到要删除的战力值\n");
	}
	else
	{
		//从下标开始，后面一个覆盖前面一个数字
		for (i = deleteIndex; i < count - 1; i++)
		{
			powers[i] = powers[i + 1];
		}
		//删除后，一定记得数组的总长度-1
		count--;
	}
	printf("删除后的结果为：\n");
	for (i = 0; i < count; i++)
	{
		printf("%.2lf\t", powers[i]);
	}
	//删除之后进行插入
	printf("\n请输入新的战力值：");
	scanf("%lf", &insertPower);
	powers[count] = insertPower;
	//插入操作完毕后，记得总长度加1
	count++;
	printf("插入后的结果为：\n");
	for (i = 0; i < count; i++)
	{
		printf("%.2lf\t", powers[i]);
	}
	return 0;
}