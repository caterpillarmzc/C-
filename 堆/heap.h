#pragma once

typedef int HPDataType;

//通过函数指针传参的方法选择创建大堆还是小堆
typedef int(*PCOM)(HPDataType, HPDataType);
int Less(HPDataType left, HPDataType right);
int Greater(HPDataType left, HPDataType right);

typedef struct Heap
{
	HPDataType* _array;//指向一段连续的空间
	int _capacity;//容量
	int _size;//有效元素个数
	PCOM Compare;
}Heap;

void InitHeap(Heap* hp, HPDataType* array, int size,PCOM compare);

void TestHeap();
void AdjustDown(int	*array, int size, int parent);
void InsertHeap(Heap* hp, HPDataType data);
void EraseHeap(Heap* hp);
int HeapSize(Heap* hp);
int HeapEmpty(Heap* hp);
HPDataType HeapTop(Heap* hp);//获取堆顶元素
void DestroyHeap(Heap* hp);
void HeapSort(int* array, int size);