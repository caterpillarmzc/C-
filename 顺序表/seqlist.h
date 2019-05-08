#pragma once
////静态顺序表
////顺序表的容量,是在编译期间确定
//struct SeqList 
//{
//	int array[100];//容量是100
//	int size;//顺序表实际存储的数据个数
//}; SeqList;

//动态顺序表
//运行时期确定的(运行时期)
typedef struct SeqList{
	int *array;
	int capacity;//容量
	int size;
}SeqList;

//初始化
void SeqListInit(SeqList*ps,int capacity);
//销毁
void SeqListDestroy(SeqList *ps);