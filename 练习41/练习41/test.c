#include<stdio.h>
#include<stdlib.h>
typedef int data_t;
typedef struct node
{
	data_t data;
	struct node * next;
}node;

//创建
node * creat_list()
{
	node * head = malloc(sizeof(node));
	if (head == NULL)
	{
		printf("申请空间失败！\n");
		return NULL;
	}
	head->next = NULL;
	return head;
}

//判空
int isnull(node * head)
{
	return head->next == NULL;
}

//头增
node * add_head(node * list, int data)
{
	node * p = malloc(sizeof(node));
	p->data = data;
	p->next = list->next;
	list->next = p;
	return 0;
}

//尾增
node * add_tail(node * list, int data)
{
	node * r;
	node * p;
	r = list;
	p = malloc(sizeof(node));
	while (r->next)
		r = r->next;
	p->data = data;
	r->next = p;
	r = p;
	r->next = NULL;
	return list;
}

//插入
int insert_list(node * list, int address, int data)
{
	node * p;
	int i = 1;
	p = list;
	while (address > i && p)
	{
		p = p->next;
		i++;
	}
	if (p == NULL)
	{
		printf("插入位置错误！\n");
		return -1;
	}
	node * s = malloc(sizeof(node));
	s->data = data;
	s->next = p->next;
	p->next = s;
	return 0;

}

//查询
int find_list(node * list, int data)
{
	if (isnull(list))
	{
		printf("表为空\n");
		return -1;
	}
	node * p = list->next;
	int i = 1;
	while (p)
	{
		if (p->data == data)
		{
			printf("数据%d在第%d位置！\n", data, i);
			return 0;
		}
		p = p->next;
		i++;
	}
	if (!p)
	{
		printf("无此数据！\n");
		return 0;
	}
}

//删除
int delete_list(node * list, int address)
{
	if (isnull(list))
	{
		printf("表为空\n");
		return -1;
	}
	node * p = list->next;
	node * q;
	int i = 1;
	while (address - 1 > i && p)
	{
		p = p->next;
		i++;
	}
	if (!p)
	{
		printf("位置错误！\n");
		return 0;
	}
	q = p->next;
	p->next = q->next;
	free(q);
	return 0;

}

//打印
int print_list(node * list)
{
	if (isnull(list))
	{
		printf("表为空！\n");
		return 0;
	}
	node * p;
	p = list->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	return 0;

}

//清空
int clean_list(node * list)
{
	node * p;
	node * q;
	p = list->next;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	list->next = NULL;
	return 0;
}

//销毁
int dis_list(node * list)
{
	clean_list(list);
	free(list);
	return 0;
}

int main(int argc, const char *argv[])
{
	node * list1 = creat_list();
	if (list1 == NULL)
		return -1;
	node * list2 = creat_list();
	if (list2 == NULL)
		return -1;
	int i;
	for (i = 0; i < 10; i++)
	{
		add_head(list1, i * 10);
	}
	print_list(list1);
	for (i = 0; i < 10; i++)
	{
		add_tail(list2, i * 10);
	}
	print_list(list2);
	insert_list(list1, 3, 100);
	print_list(list1);
	find_list(list1, 50);
	delete_list(list1, 8);
	print_list(list1);
	dis_list(list1);
	dis_list(list2);
	return 0;
}
