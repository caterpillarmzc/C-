#pragma once
#include <stdlib.h>
//链表的节点
typedef struct Node
{
	int value;
	struct Node *next;//保存着下一个结点的地址,找到最后一个为NULL时结束
}Node;

//初始化链表就是一条空链表,一个节点都没有的链表,即first=NULL
void SListInit(Node **){
	*ppFirst = NULL;
}

void SListPushFront(Node **ppFirst, int v){
	Node *node = (Node*)malloc(sizeof(Node));
	node->value = v;
	node->next = *ppFirst;
	*ppFirst = node;

}

//头插
void Test(){
	Node *first;
	SListInit(&first);

	SListPushFront(&first, 1);
	//1->NULL
	SListPushFront(&first, 1);
	//2->1->NULL
	SListPushFront(&first, 1);
	//3->2->1->NULL
	SListPushFront(&first, 1);
	//4->3->2->1->NULL
}

//头删
void SListPopFront(Node **ppFirst){
	assert(*ppFirst != NULL);//一个结点都没有的话,无法进行删除
	Node *next = (*ppFirst)->next;//找一个地方存放1的地址,防止释放丢失
	free(*ppFirst);
	*ppFirst = next;
}

//尾插
void SListPushBack(Node **ppfirst,int v){
	//申请新空间
	Node *node = (Node*)malloc(sizeof(Node));
	node->value = v;
	node->next = NULL;//node是新的最后一个结点,所以next=NULL
	if (*ppfirst==NULL){
		*ppfirst = node;
		//链表为空,没有任何结点
		*ppfirst = node;	
	}
	else
	{
	//找最后一个结点,最后一个结点的next一定是NULL
	Node *cur = *ppfirst;
	while(cur->next!=NULL){
		cur = cur->next;
	}
	//cur就是最后一个结点
	Node *node = (Node*)malloc(sizeof(Node));
	node ->value = v;
	node->next = NULL;
	//让原来最后一个结点的next=新的节点
	cur ->next = node;

	}
}

//尾删
void SListPopBack(Node **ppFirst){
	//当空链表时,无法进行尾删操作,退出
	assert(*ppFirst != NULL);
	//当链表只有一个结点时的情况
	if ((*ppFirst)->next==NULL){
		free(*ppFirst);
		*ppFirst = NULL;
		return;
	}
	//当链表的结点数大于1时的情况
	//找到倒数第二个结点
	//即为cur->next->next == NULL
	Node *cur = *ppFirst;
	while (cur->next->next==NULL){
		cur = cur->next;
	}
	//释放最后一个结点
	free(cur->next);
	cur->next = NULL;
}

//查找
Node * SListFind(const Node *first,int v){
	for (Node*cur = first; cur != NULL;cur=cur->next){
		if (cur->value==v){
			return cur;
		}
	}
	return NULL;
}

//释放
void SListDestroy(Node *first){
	Node *next;
	for (Node *cur = first; cur != NULL;cur=next){
		next = cur->next;
		free(cur);
	}
}

//pos一定是链表中的结点
//在指定位置pos后面做插入
void SListInsertAfter(Node *pos,int v){
	Node *node = (Node*)mallloc(sizeof(Node));
	node->value = v;
	node->next = pos->next;
	pos->next = node;
}

//pos一定是链表中的结点
//在指定位置pos后面做删除
void SListEraseAfter(Node *pos){
	Node *next = pos->next;
	pos->next = pos->next->next;
	free(next);
}

