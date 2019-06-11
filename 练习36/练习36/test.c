#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1024
//找子串函数
int my_strncmp(char *s1, char *s2, int len)
{
	for (i = 0; i < len; i++)
	{
		if (*(s1 + i) != *(s2 + i))
		{
			return -1;
		}
	}
	return 0;

}


char *find_aim_str(char *head, char *tail, char *str)
{
	int len_h = strlen(head);
	int len_t = strlen(tail);
	char *temp;

	while (*str != '\0')
	{
		if (my_strncmp(head, str, len_h) == 0)//找到head
		{
			temp = str;
			str = str + len_h;
			if (my_strncmp(tail, str, len_h) == 0)//找到tail
			{
				*(str + len_t) = '\0';
				return temp;
			}
			return NULL;
		}

		str++;
		return NULL;
	}

}

int main()
{

	char str[MAX_SIZE];
	char head[MAX_SIZE];
	char tail[MAX_SIZE];

	printf("please input a string!\n");
	scanf("%s", str);

	printf("please input a head string!\n");
	scanf("%s", head);

	printf("please input a tail string!\n");
	scanf("%s", tail);

	char *result = find_aim_str(head, tail, str);

	printf("result is %s\n", result);

	return 0;
}