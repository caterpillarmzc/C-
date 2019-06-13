#include "BinTree.h"
#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "Queue.h"



BTNode* BuyBinTeeNode(BTDataType data)
{
	BTNode* pNewNode = (BTNode*)malloc(sizeof(BTNode));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}

	pNewNode->_data = data;
	pNewNode->_pLeft = NULL;
	pNewNode->_pRight = NULL;

	return pNewNode;
}

// 二叉树的创建 
BTNode* _CreateBinTree(BTDataType* array, int size, int* index, BTDataType invalid)
{
	BTNode* pRoot = NULL;
	if (*index < size && invalid != array[*index])
	{
		// 根节点
		pRoot = BuyBinTeeNode(array[*index]);

		// 根的左子树
		++(*index);
		pRoot->_pLeft = _CreateBinTree(array, size, index, invalid);

		// 根的右子树
		++(*index);
		pRoot->_pRight = _CreateBinTree(array, size, index, invalid);
	}

	return pRoot;
}

// 递归：中序遍历 
void PreOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		printf("%c ", pRoot->_data);
		PreOrder(pRoot->_pLeft);
		PreOrder(pRoot->_pRight);
	}
}

// 递归：中序遍历
void InOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		InOrder(pRoot->_pLeft);
		printf("%c ", pRoot->_data);
		InOrder(pRoot->_pRight);
	}
}

// 递归：后序遍历
void PostOrder(BTNode* pRoot)
{
	if (pRoot)
	{
		PostOrder(pRoot->_pLeft);
		PostOrder(pRoot->_pRight);
		printf("%c ", pRoot->_data);
	}
}

// 层序遍历
void LevelOrder(BTNode* pRoot)
{
	Queue q;
	if (NULL == pRoot)
		return;

	QueueInit(&q);
	QueuePush(&q, pRoot);
	while (!QueueEmpty(&q))
	{
		BTNode* pCur = QueueFront(&q);
		printf("%c ", pCur->_data);

		// 如果左孩子存在，保存当前节点的左孩子
		if (pCur->_pLeft)
			QueuePush(&q, pCur->_pLeft);

		// 如果右孩子存在，保存当前节点的右孩子
		if (pCur->_pRight)
			QueuePush(&q, pCur->_pRight);

		QueuePop(&q);
	}

	QueueDestroy(&q);
	printf("\n");
}

//交换节点
void Swap(BTNode** pLeft, BTNode** pRight)
{
	BTNode* pTemp = *pLeft;
	*pLeft = *pRight;
	*pRight = pTemp;
}

void MirrorNor(BTNode* pRoot)
{
	Queue q;
	if (NULL == pRoot)
		return;

	QueueInit(&q);
	QueuePush(&q, pRoot);
	while (!QueueEmpty(&q))
	{
		BTNode* pCur = QueueFront(&q);
		Swap(&pCur->_pLeft, &pCur->_pRight);

		// 如果左孩子存在，保存当前节点的左孩子
		if (pCur->_pLeft)
			QueuePush(&q, pCur->_pLeft);

		// 如果右孩子存在，保存当前节点的右孩子
		if (pCur->_pRight)
			QueuePush(&q, pCur->_pRight);

		QueuePop(&q);
	}

	QueueDestroy(&q);
}

// 二叉树的镜像
void Mirror(BTNode* pRoot)
{
	if (pRoot)
	{
		Swap(&pRoot->_pLeft, &pRoot->_pRight);
		Mirror(pRoot->_pLeft);
		Mirror(pRoot->_pRight);
	}
}

BTNode* CreateBinTree(BTDataType* array, int size, BTDataType invalid)
{
	int index = 0;
	return _CreateBinTree(array, size, &index, invalid);
}

//确定叶子结点个数
int GetLeafCount(BTNode* pRoot)
{
	if (NULL == pRoot)
		return 0;

	if (NULL == pRoot->_pLeft && NULL == pRoot->_pRight)
		return 1;

	return GetLeafCount(pRoot->_pLeft) + GetLeafCount(pRoot->_pRight);
}

int GetKLevelNodeCount(BTNode* pRoot, int K)
{
	if (NULL == pRoot || K <= 0)
		return 0;

	if (1 == K)
		return 1;

	return GetKLevelNodeCount(pRoot->_pLeft, K - 1) +
		GetKLevelNodeCount(pRoot->_pRight, K - 1);
}

BTNode* BinaryTreeFind(BTNode* pRoot, BTDataType x)
{
	BTNode* pRet = NULL;
	if (NULL == pRoot)
		return NULL;

	if (x == pRoot->_data)
		return pRoot;

	if (pRet = BinaryTreeFind(pRoot->_pLeft, x))
		return pRet;

	return BinaryTreeFind(pRoot->_pRight, x);
}

//销毁二叉树
void DestroyBinTree(BTNode** pRoot)
{
	assert(pRoot);
	if (*pRoot)
	{
		DestroyBinTree(&(*pRoot)->_pLeft);
		DestroyBinTree(&(*pRoot)->_pRight);
		free(*pRoot);
		*pRoot = NULL;
	}
}

void TestBinTree()
{
	char* str = "ABD$$$CE$$F";
	BTNode* pRoot = CreateBinTree(str, strlen(str), '$');
	Mirror(pRoot);
	MirrorNor(pRoot);
	printf("前序遍历结果：");
	PreOrder(pRoot);
	printf("\n");

	printf("中序遍历结果：");
	InOrder(pRoot);
	printf("\n");

	printf("后序遍历结果：");
	PostOrder(pRoot);
	printf("\n");

	printf("层序遍历结果：");
	LevelOrder(pRoot);

	printf("K=3: %d\n", GetKLevelNodeCount(pRoot, 3));

	if (BinaryTreeFind(pRoot, 'E'))
	{
		printf("E is in BTree!!!\n");
	}
	else
	{
		printf("E is not in BTree!!!\n");
	}
	DestroyBinTree(&pRoot);
}