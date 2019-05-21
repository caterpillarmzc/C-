#include "Stack.h"
#include <malloc.h>
#include <assert.h>
#include <stdio.h>

//检测空间并扩容
void CheckCapacity(Stack* ps)
{
	assert(ps);
	if (ps->_size == ps->_capacity)//有效元素个数与容量相等是扩容
	{
		// 开辟新空间,空间大小为2倍
		int newCapacity = ps->_capacity * 2;
		SDataType* pTemp = (SDataType*)malloc(sizeof(SDataType)*newCapacity);
		if (NULL == pTemp)
		{
			assert(0);
			return;
		}

		// 拷贝元素
		for (int i = 0; i < ps->_size; ++i)
			pTemp[i] = ps->_array[i];

		// 释放旧空间
		free(ps->_array);
		ps->_array = pTemp;
		ps->_capacity = newCapacity;
	}
}

//栈的初始化
void StackInit(Stack* ps)
{
	assert(ps);//保证栈存在
	ps->_array = (SDataType*)malloc(sizeof(SDataType)* 3);//申请空间,3为暂时给的空间大小
	if (NULL == ps->_array)//判断空间是否申请成功
	{
		assert(0);
		return;
	}

	ps->_capacity = 3;//3为空间大小
	ps->_size = 0;//实际上还没有存储元素
}

//入栈(给栈内插入元素)
void StackPush(Stack* ps, SDataType data)
{
	// 检测是否有足够空间
	CheckCapacity(ps);//后边会有申请空间的函数

	ps->_array[ps->_size++] = data;//多了一个元素后size要++
}

//出栈(删除栈内元素)
void StackPop(Stack* ps)
{
	assert(ps);
	if (StackEmpty(ps))//如果栈为空的话无法进行删除操作,直接返回
		return;

	ps->_size -= 1;//栈不为空,元素个数减少一个
}

//获取栈内元素ps
SDataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->_array[ps->_size - 1];//栈顶指向的元素是最后一个元素的位置减一
}

//获取栈内有效元素的个数
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_size;//返回size的值即为个数
}

//判断栈是否为空
int StackEmpty(Stack* ps)
{
	assert(ps);
	return 0 == ps->_size;//判断是否有元素
}

//栈的销毁(避免内存泄漏)
void StackDestroy(Stack* ps)
{
	assert(ps);
	if (ps->_array)//将ps指向的栈的空间释放
	{
		free(ps->_array);
		ps->_capacity = 0;
		ps->_size = 0;
	}
}

void TestStack()
{
	Stack s;
	StackInit(&s);

	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	printf("size = %d\n", StackSize(&s));
	printf("top = %d\n", StackTop(&s));

	StackPush(&s, 4);
	StackPush(&s, 5);
	printf("size = %d\n", StackSize(&s));
	printf("top = %d\n", StackTop(&s));

	StackPop(&s);
	StackPop(&s);
	printf("size = %d\n", StackSize(&s));
	printf("top = %d\n", StackTop(&s));

	StackDestroy(&s);
}