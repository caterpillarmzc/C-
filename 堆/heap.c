#include "heap.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>


//初始化
void InitHeap(Heap* hp, HPDataType* array, int size, PCOM compare)
{
	assert(hp);
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType));
	if (NULL==hp->_array)
	{
		assert(0);
		return;
	}
	hp->_capacity = size;

	for (int i = 0; i < size;++i)
	{
		hp->_array[i] = array[i];
	}
	hp->_size = size;
	//根据传入的参数选择大堆还是小堆
	hp->Compare = compare;
	//将该完全二叉树调整让其满足堆的性质
	//先找最后一个结点size-1,进而找到其双亲((size-1)-1)/2,
	//即为最后一个非叶节点的位置
	int root  = ((size - 2) >> 1);
	//每次调整的都是以parent为根root的树
	for (; root >= 0;--root)
	{
		AdjustDown(hp->_array, size, root,hp->Compare);
	}

}//注意:将元素放入堆所在的空间后,不一定满足堆的性质


//申请空间并将元素放进去
void Swap(HPDataType* pleft, HPDataType* pright)
{
	HPDataType temp = *pleft;
	*pleft = *pright;
	*pright = temp;
}


//两种创建大堆和小堆的方法
int Less(HPDataType left, HPDataType right)
{
	return left < right;
}
int Greater(HPDataType left, HPDataType right)
{
	return left > right;
}


//向上调整
void AdjustUp(HPDataType* array,int size,int child,PCOM Compare)
{
	int parent = (child - 1) / 2;
	while(child)//当child到了根节点的位置时,循环结束
	{

		if (Compare(array[child] , array[parent]))
		{
			Swap(&array[child], &array[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			return;
	}
}


//向下调整
void AdjustDown(HPDataType* array, int size, int parent, PCOM Compare)//将要调整的节点标记为parent
{
	//默认让child标记parent的左孩子,
	//完全二叉树某个节点如果只有一个孩子,那一定是左孩子
	int child = parent * 2 + 1;

	while (child < size)
	{
		//双亲跟较小的孩子比较,来调整
		//先寻找较小的孩子
		if (child + 1 < size&&Compare(array[child + 1], array[child]))
		{
			child += 1;
		}
		if (Compare(array[child], array[parent]))
		{
			Swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}
}


//扩容
void CheckCapacity(Heap* hp)
{
	assert(hp);
	if (hp->_size==hp->_capacity)
	{
		//申请新空间
		int newCapacity = hp->_capacity * 2;
		HPDataType* pTemp = (HPDataType*)malloc(sizeof(HPDataType)*newCapacity);
		if (NULL==pTemp)
		{
			assert(0);
			return;
		}
		//拷贝元素
		for (int i = 0; i < hp->_size;++i)
			pTemp[i] = hp->_array[i];
		//释放空间
		free(hp->_array);
		hp->_array = pTemp;
		hp->_capacity = newCapacity;
	}
}


//堆的插入,插入元素data
//插入到最后一个节点后边
//需要判断空间是否够插入
//一步步往上走,每次都跟双亲节点比较交换(即为向上调整)
void InsertHeap(Heap* hp, HPDataType data)
{
	CheckCapacity(hp);
	hp->_array[hp->_size] = data;
	hp->_size++;
	AdjustUp(hp->_array, hp->_size, hp->_size - 1,hp->Compare);
}


//堆的删除--一般是删除堆顶元素
void EraseHeap(Heap* hp)
{
	if (HeapEmpty(hp))
		return;
	//堆顶元素与最后一个节点交换位置,size再减小一个空间,
	//则相当于删除,删除完成后再进行调整
	Swap(&hp->_array[0], &hp->_array[hp->_size - 1]);
	hp->_size -= 1;
	AdjustDown(hp->_array, hp->_size, 0, hp->Compare);
}


//判断对内有效元素个数
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}


//判断堆是否为空
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return 0 == hp->_size;
}


//获取堆顶元素
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->_array[0];
}


//将空间释放
void DestroyHeap(Heap* hp)
{
	assert(hp);
	if (hp->_array)
	{
		free(hp->_array);
		hp->_capacity = 0;
		hp->_size = 0;
	}
}

//调整为大堆
void HeapAdjust(int* array,int size,int parent)
{
	int child = parent * 2 + 1;
	while(child<size)
	{
		//找左右孩子中较小的一个
		if (child + 1 < size&&array[child + 1] > array[child])
			child += 1;
		if(array[child]>array[parent])
		{
			Swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}
	}
}
void HeapSort(int* array, int size)
{
	//建堆---大堆 小堆
	//如创建大堆,找到书第一个非叶子节点
	int root = ((size - 2) >> 1);
	for (; root >= 0; --root)
		HeapAdiust(array, size, root);
	//排序
	int end = size - 1;
	while (end)//当end=0是截止
	{
		//堆顶元素与最后一个元素交换位置,
		//删除堆底的最后一个元素,总元素减1,再向下调整,循环
		Swap(&array[0], &array[end]);
		HeapAdjust(array, end, 0);
		end--;
	}

}
//测试程序
void TestHeap()
{
	Heap hp;
	int array[] = { 2,3,8,0,9,1,7,4,6,5 };
	InitHeap(&hp, array, sizeof(array)/sizeof(array[0]),Less);
	printf("%d\n", HeapSize(&hp));
	printf("%d\n", HeapTop(&hp));
	EraseHeap(&hp);
	printf("%d\n", HeapTop(&hp));
	InsertHeap(&hp, 0);
	printf("%d\n", HeapTop(&hp));
	DestroyHeap(&hp);
}

