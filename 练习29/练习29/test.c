//有一个字符串开头或结尾含有n个空格（”   abcdefgdddd    ”），欲去掉前后空格，返回一个新字符串。
//
//要求1：请自己定义一个接口（函数），并实现功能；70分
//
//要求2：编写测试用例。30分
//#include <stdio.h>
//#include <string.h>
//
////先去掉前面的空格，再去掉后面的空格
//int trimSpace(char *inbuf, char *outbuf){
//	char *p = inbuf;
//	//查看有多少个空格
//	int len = 0;
//	while (p[len] == ' '){
//		len++;
//	}
//
//	//将字符串进行前移
//	int i = len;
//	while (p[i]){
//		p[i - len] = p[i];
//		i++;
//	}
//	p[i - len] = '\0';
//
//	//去掉后面的字符串
//	for (int j = 0; j < strlen(p); j++){
//		if (p[j] == ' '){
//			p[j] = '\0';
//			outbuf = p;
//			return 1;
//		}
//	}
//
//	return 0;
//}
//
//
//int main(){
//	char str[] = "        abcdefgdddd        ";
//	char *outbuf = NULL;
//
//	if (trimSpace(str, outbuf)){
//		printf("start.%s.end", str);
//	}
//	else{
//		printf("No need for trim.");
//	}
//
//}
//

//有一个字符串”1a2b3d4z”, ；
//
//要求写一个函数实现如下功能，
//
//功能1：把偶数位字符挑选出来，组成一个字符串1。valude；20分
//
//功能2：把奇数位字符挑选出来，组成一个字符串2，valude 20
//
//功能3：把字符串1和字符串2，通过函数参数，传送给main，并打印。
//
//功能4：主函数能测试通过。
#include <stdio.h>
#include <string.h>

//输入字符串，输出两个截取之后的字符串
int getStr1Str2(char *str, char *buf1, char *buf2){
	char *p = str;
	int temp1 = 0;
	int temp2 = 0;

	if (p == NULL){
		return -1;
	}

	for (int i = 0; i < strlen(p); i++){
		if (i % 2 == 0){
			buf1[temp1] = p[i];
			temp1++;
		}
		else{
			buf2[temp2] = p[i];
			temp2++;
		}
	}

	return 1;
}

int main(){
	char str[] = "1a2b3d4z";
	char buf1[10] = { 0 };
	char buf2[10] = { 0 };

	if (getStr1Str2(str, buf1, buf2)){
		printf("buf1 = %s, buf2 = %s\n", buf1, buf2);
	}
	else{
		printf("Error!");
	}
}
