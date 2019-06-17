//编写一个函数，实现顺序表的就地逆置，也就是说利用原表的存储空间将顺序表（a1,a2…an）,逆置为（an,an-1…a1)
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10//静态顺序表的最大空间

typedef struct
{
	int *base;
	int length;
}Sqlist;//顺序表


void reverseSQ(Sqlist *l)
{   //实现顺序表l的就地逆置
	int low = 0, high = l->length - 1;
	int buf, i;


	for (int i = 0; i < l->length / 2; i++)
	{   //循环l->length/2次
		buf = l->base[low];
		l->base[low] = l->base[high];
		l->base[high] = buf;
		low++;
		high--;
	}
}
int main(int argc, char const *argv[])
{
	Sqlist l;
	int i, data;

	l.base = (int*)malloc(sizeof(int)* MAXSIZE);
	l.length = 0;//创建顺序表
	if (!l.base)
	{   //分配内存失败
		printf("error!\n");
	}

	//输入数据

	for (i = 0; i < MAXSIZE; i++)
	{
		scanf("%d", &l.base[i]);
		l.length++;
	}

	//输出数据

	for (i = 0; i < l.length; i++)
	{
		printf("%d ", l.base[i]);
	}
	printf("\n");

	reverseSQ(&l);//就地逆置

	for (i = 0; i < l.length; i++)
	{
		printf("%d ", l.base[i]);
	}

	system("pause");
	return 0;
}

//从键盘上输入任意个整数，以0作为结束标志，对这个整数序列从小到大排序，并输出排序后的结构
#include <stdio.h>
#include <stdlib.h>

//定义链表的结点类型
typedef struct node
{
	int data;
	struct node *next;
}LNode, *LinkList;

//创建一个长度为n的链表
LinkList creatList(int n)
{
	LinkList p, q, list = NULL;
	int elem, i;

	for (i = 0; i < n; i++)
	{
		scanf("%d", &elem);
		p = (LinkList)malloc(sizeof(LNode));
		if (!p)
		{
			return NULL;
		}
		p->data = elem;
		p->next = NULL;
		if (list == NULL)
		{
			list = p;//第一个结点
		}
		else
		{
			q->next = p;
		}
		q = p;
	}
	return list;
}

//向链表中插入结点，并向该结点的数据域中存放数据
void insertList(LinkList *list, LinkList q, int elem)
{
	LinkList p;
	p = (LinkList)malloc(sizeof(LNode));
	if (!p)
	{
		return;
	}
	p->data = elem;
	if (!*list)
	{   //如果首结点为空
		*list = p;
		p->next == NULL;
	}
	else
	{   //向后插入
		p->next = q->next;
		q->next = p;
	}
}

//基于链表冒泡排序
void bubbleSort(LinkList list)
{
	LinkList p = list;
	int temp, i, j, k = 0;

	while (p)
	{
		k++;
		p = p->next;
	}//k为链表元素个数

	p = list;
	for (i = 0; i < k - 1; i++)
	{
		for (j = 0; j < k - 1 - i; j++)
		{
			if (p->data > p->next->data)
			{   //与下一个位置进行比较
				temp = p->data;
				p->data = p->next->data;
				p->next->data = temp;
			}
			p = p->next;
		}
		p = list;//指针重新指向开头
	}
}

//打印出排序后的新链表
void print(LinkList list)
{
	while (list)
	{
		printf("%d ", list->data);
		list = list->next;
	}
}

int main(int argc, char const *argv[])
{
	LinkList q, r;
	int elem;

	q = r = creatList(1);//创建一个链表结点，q和r都指向这个结点

	scanf("%d", &elem);
	while (elem)
	{   //循环输入数据同时插入结点
		insertList(&q, r, elem);
		r = r->next;
		scanf("%d", &elem);
	}

	bubbleSort(q);
	print(q);

	system("pause");
	return 0;
}

//有两个按元素值递增的有序排列的链表list1和list2，现需要将两个链表合
//并一个按元素值递增的有序链表list3。要求利用原表空间的结点空间构造新表。
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}LNode, *LinkList;

//创建一个长度为n的链表
LinkList creatLinkList(int n)
{
	LinkList p, r, list = NULL;
	int elem, i;

	for (i = 0; i < n; i++)
	{
		scanf("%d", &elem);
		p = (LinkList)malloc(sizeof(LNode));
		if (!p)
		{
			return NULL;
		}
		p->data = elem;
		p->next = NULL;
		if (!list)
		{
			list = p;
		}
		else
		{
			r->next = p;
		}
	}
	return list;
}

//向链表中插入结点，并向该结点的数据域中存放数据
void insertList(LinkList *list, LinkList q, int elem)
{
	LinkList p;
	p = (LinkList)malloc(sizeof(LNode));
	p->data = elem;
	if (!p)
	{
		return;
	}
	if (!*list)
	{
		*list = p;
		p = p->next;
	}
	else
	{
		p->next = q->next;
		q->next = p;
	}
}

//将p指向的结点插入到q1,q2所指向的结点当中
void insertNode(LinkList *q1, LinkList *q2, LinkList *p, LinkList *l2)
{
	if (*q1 == *q2)
	{   //l1链表第一个结点内容小于来l2链表第一个结点内容，特判
		(*p)->next = *q2;
		*l2 = *q2 = *q1 = *p;
	}
	else
	{
		(*q2)->next = *p;
		(*p)->next = *q1;
		(*q2) = (*q2)->next;
	}
}

//将l1,l2原空间有序归并，用l3返回
void mergeLink(LinkList l1, LinkList l2, LinkList *l3)
{
	LinkList p, q1, q2;
	q1 = q2 = l2;//q1, q2指向l2链表
	p = l1;//p指向l1链表
	while (p && q1)
	{
		if (p->data >= q1->data)
		{
			q2 = q1;
			q1 = q1->next;
		}
		else
		{
			l1 = l1->next;
			insertNode(&q1, &q2, &p, &l2);
			p = l1;
		}
		/*
		p指向l1链表，q1,q2指向l2链表，q2始终在q1后一个位置
		比较p->data 和 q1->data ,
		1.如果p->data >= q1->data, q1,q2指向其下一个位置
		2.如果p->data < q1->data, 将p插入q1,q2之间
		直到某一链表为空结束
		*/
	}
	if (!q1)
	{
		q2->next = p;
	}
	/*
	如果l1链表为空，那么l1已经完全插入合并到l2中
	如果l2链表为空，则讲l2尾指针指向l1连接
	*/
	*l3 = l2;//l2首结点赋给l3
}

//打印链表
void print(LinkList list)
{
	while (list)
	{
		printf("%d ", list->data);
		list = list->next;
	}
}

int main(void)
{
	LinkList l1, l2, l3, q;
	int elem;

	//创建链表l1
	q = l1 = creatLinkList(1);
	scanf("%d", &elem);
	while (elem)
	{
		insertList(&l1, q, elem);
		q = q->next;
		scanf("%d", &elem);
	}

	//创建链表l2
	q = l2 = creatLinkList(1);
	scanf("%d", &elem);
	while (elem)
	{
		insertList(&l2, q, elem);
		q = q->next;
		scanf("%d", &elem);
	}

	//归并链表
	mergeLink(l1, l2, &l3);
	//打印合并链表
	print(l3);

	system("pause");
	return 0;
}
