#include "Queue.h"
#include <malloc.h>
#include <assert.h>
#include <stdio.h>
//链式结构实现队列,用到链表里的尾插和头删

//申请空间
QNode* BuyQueueNode(QDataType data)
{
	QNode* pNewNode = (QNode*)malloc(sizeof(QNode));
	if (NULL == pNewNode)//判断是否申请成功
	{
		assert(0);
		return NULL;
	}

	pNewNode->_data = data;
	pNewNode->_pNext = NULL;
	return pNewNode;
}

//队列的初始化
void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_back = NULL;//创建的队列为空,无元素
}

//入队列(即尾插)
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	QNode* pNewNode = BuyQueueNode(data);
	if (QueueEmpty(q))//如果队列为空,队头队尾都指向的是插入的新节点
		q->_front = q->_back = pNewNode;
	else
	{
		q->_back->_pNext = pNewNode;//链表最后一个结点的下一位指向新节点
		q->_back = pNewNode;//back挪到新节点
	}
}

//出队列(头删)
void QueuePop(Queue* q)
{
	QNode* pDelNode = NULL;//pDelNode表示要删除的结点
	if (QueueEmpty(q))//为空,不能出队列,直接返回
		return;

	pDelNode = q->_front;
	if (NULL == pDelNode->_pNext)//如果要删除的结点的下一个结点为空.即对队列只有一个结点
	{
		q->_front = q->_back = NULL;
	}
	else
	{
		q->_front = pDelNode->_pNext;
	}

	free(pDelNode);
}

//获取队头元素
QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->_front->_data;
}

//获取队尾元素
QDataType QueueBack(Queue* q)
{
	assert(q);
	return q->_back->_data;
}

//当前队列的有效元素总数
int QueueSize(Queue* q)
{
	int count = 0;
	QNode* pCur = q->_front;//从队头开始遍历
	while (pCur)
	{
		count++;
		pCur = pCur->_pNext;
	}

	return count;
}

//判断当前队列是否为空
int QueueEmpty(Queue* q)
{
	assert(q);
	return NULL == q->_front;//如果队头指向空,则队列为空
}

//释放队列的空间
void QueueDestroy(Queue* q)
{
	QNode* pCur = q->_front;
	while (pCur)//先确保队列不为空
	{
		q->_front = pCur->_pNext;
		free(pCur);
		pCur = q->_front;
	}

	q->_front = q->_back = NULL;
}


void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	printf("front = %d\n", QueueFront(&q));
	printf("back = %d\n", QueueBack(&q));
	printf("size = %d\n", QueueSize(&q));

	QueuePop(&q);
	printf("front = %d\n", QueueFront(&q));
	printf("back = %d\n", QueueBack(&q));
	printf("size = %d\n", QueueSize(&q));

	QueuePop(&q);
	QueuePop(&q);
	printf("front = %d\n", QueueFront(&q));
	printf("back = %d\n", QueueBack(&q));
	printf("size = %d\n", QueueSize(&q));

	QueuePop(&q);
	printf("size = %d\n", QueueSize(&q));
	QueueDestroy(&q);
}