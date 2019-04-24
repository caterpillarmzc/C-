//
////一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
////找出这两个数字，编程实现。
////思路:将数组中的数从头到尾依次异或，出现偶数次的数异或都为0，
////最终结果是两个只出现一次的数字异或的结果，由于这两个数字不同，
////异或的结果一定不为0，即其二进制表示形式中一定存在某一位为1，
////找到第一个为1的位，假设是第N位，那么在对应的这一位上，
////这两个数一个为0，一个为1，根据第N位是否为1，将原数组分成两个子数组，
////这两个子数组分中都只包含一个只出现了一次的数，其他的数都出现了两次，
////两个子数组中的元素分别异或，就得到了两个只出现一次的数
//#include <stdio.h>
//void search(int arr[], int len)
//{
//	int ret = 0;
//	int n = 0;
//	int num1 = 0;
//	int num2 = 0;
//	for (int i = 0; i < len; i++)
//	{
//		ret ^= arr[i];
//	}
//	//找ret最右边的1
//	n = ret - (ret&(ret - 1));
//	for (int i = 0; i < len; i++)
//	{//取出arr[i]的第n位
//		int a = (arr[i] >> (n - 1)) % 2;   
//		if (a == 0)
//		{
//			num1 ^= arr[i];
//		}
//		else
//		{
//			num2^= arr[i];
//		}
//	}
//	printf("%d, %d\n", num1, num2);
//}
//
//int main()
//{
//	int arr[] = { 1, 2, 3, 5, 6, 6, 1, 3, 5, 2, 8, 7 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	search(arr, len);
//
//	system("pause");
//	return 0;
//}

//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，
//给20元，可以多少汽水。编程实现。
//#include <stdio.h>
//int num(int n)
//{
//	int count = n;
//	while (n>1)
//	{
//		count = count + n / 2;
//		n = n / 2 + n % 2;
//	}
//	return count;
//}
//int main()
//{
//	int n = 20;
//	int ret = num(n);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}


//模拟实现strcpy 
//char* Strcpy(char* dest,const char* src)
//{
//	int i = 0;
//	//从src的第0号元素开始一个一个取元素,
//	for (; src[i] != '\0'; ++i)
//	{
//		dest[i] = src[i];
//	}
//	dest[i] = '\0';
//}
//#include <stdio.h>
//int main()
//{
//	char*p = "abcdef";
//	char str[1024] = { 0 };
//	Strcpy(str, p);
//	printf("%s\n", str);
//	system("pause");
//}

//实现strcat
#include <string.h>
#include <stdio.h>
char* Strcat(char* dest,const char* src)
{
	//现在dest中找到\0
	int i = 0;
	//循环结束后,i对应的元素就是\0
	for (; dest[i] != '\0'; ++i);
	//再把src中的字符一次赋值进去
	int j = 0;
	for (; src[j] != '\0'; ++i, ++j);
	{
		dest[i] = src[j];
	}
	dest[i] = '\0';
	return dest;
}

int main()
{
	char str1[1024] = "aaa";
	char str2[1024] = "bbb";
	Strcat(str1, str2);
	printf("%s\n", str1);
	printf("%s\n", str2);

	system("pause");
	return 0;
}