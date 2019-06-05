#define  _CRT_SECURE_NO_WARNINGS
//编号1， 2， 3…n的n个人按顺时针方向坐一圈，每个人手中持有一个密码。
//开始时任选一个正整数作为报数的上限m，从第一个人开始按顺时针方向自1开始顺序表报数，
//报道m停止，报到m的人出列，将他手中的密码作为新的报数上限m，
//从顺时针方向上的下一个开始重新从1报数，如此报数下去，
//求最后剩下的那个人的最初编号是多少
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int number;//编号
	int psw;//个人密码
	struct node *next;
}LNode, *LinkLisk;

//向链表list中q指向结点后面插入一个新结点
void insertList(LinkLisk *list, LinkLisk q, int data1, int data2)
{
	LinkLisk p;
	p = (LinkLisk)malloc(sizeof(LNode));
	p->number = data1;
	p->psw = data2;
	if (!*list)
	{
		*list = p;
	}
	else
	{
		p->next = q->next;
		q->next = p;
	}
}

//创建一个约瑟夫环
void creatJoseph(LinkLisk *jsp, int n)
{
	LinkLisk q = NULL, list = NULL;
	int i, elem;

	for (i = 0; i < n; i++)
	{
		scanf("%d", &elem);
		insertList(&list, q, i + 1, elem);//向q指向的结点后插入新的结点
		if (i == 0)
		{
			q = list;
		}
		else
		{
			q = q->next;
		}
	}
	q->next = list;//形成循环链表
	*jsp = list;
}

//
void exJosph(LinkLisk *jsp, int m)
{
	LinkLisk p, q;
	int i;

	p = q = *jsp;
	while (q->next != p)
	{
		q = q->next;//q指向p的前一个结点
	}
	while (p->next != p)
	{
		for (i = 0; i < m - 1; i++)
		{   //p指向要删除的结点，q指向删除结点的前一个结点
			q = p;
			p = p->next;
		}
		q->next = p->next;//删除p指向的结点
		printf("%d ", p->number);//输出出列的数
		m = p->psw;//重置报数上限
		free(p);//释放p指向的结点
		p = q->next;//p指向q的后一个结点
	}
	printf("\nThe last person in the cicrle is %d\n", p->number);
}

int main(void)
{
	LinkLisk jsp;
	int n, m;


	scanf("%d", &n);//输入约瑟夫环人数
	creatJoseph(&jsp, n);


	scanf("%d", &m);//输入约瑟夫环报数上限
	exJosph(&jsp, m);

	system("pause");
	return 0;
}


