#pragma once


// 二叉树的链式存储方式---孩子表示法

typedef char BTDataType;
typedef struct BTNode
{
	struct BTNode* _pLeft;
	struct BTNode* _pRight;
	BTDataType _data;
}BTNode;


BTNode* CreateBinTree(BTDataType* array, int size, BTDataType invalid);

// 概念
BTNode* CopyBinTree(BTNode* pRoot);
void PreOrder(BTNode* pRoot);
void InOrder(BTNode* pRoot);
void PostOrder(BTNode* pRoot);
void LevelOrder(BTNode* pRoot);
int GetBinTreeSize(BTNode* pRoot);
int GetKLevelNodeCount(BTNode* pRoot, int K);
int GetLeafCount(BTNode* pRoot);
int GetBinTreeHeight(BTNode* pRoot);
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
void MirrorNor(BTNode* pRoot);
void Mirror(BTNode* pRoot);
void DestroyBinTree(BTNode** pRoot);

void TestBinTree();