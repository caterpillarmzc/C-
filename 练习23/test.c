//库函数的模拟实现
char *Strstr(const char* str1, const char* str2);{
	assert(str1);
	assert(str2);
	char *cp = (char*)str1;
	char *substr = (char*)str2;
	char *s1 = NULL;

	if(*str2=='\0'){
		return NULL;
	}
	while(*cp){
		s1 = cp;
		substr = str2;
		while(*s1&&*substr&&(*s1==*substr)){
			s1++;
			substr++;
		}
		if(*substr=='\0'){
			return cp;
		}
		cp++;
	}
}


char str1[1024] = "aaa";
char str2[1024] = "aaa";
int ret = strcmp(str1, str2);
if(ret>0){
	printf("str1>str2\n");
}
......

int Strcmp(const char*src,const *dst){
	int ret = 0;
	assert(src != NULL);
	assert(dest != NULL);
	while (!(ret = *(unsigned char*)src - *(unsigned char*)dst) && dst)
		++src, ++dst;
	if (ret < 0)
		ret = -1;
	else if (ret>0)
		ret = 1;
	return(ret);
}

#include<stdio.h>
#include<string.h>
int arr[4] = { 0 };
int arr[4] = { 1, 2, 3, 4 };
memcpy(arr1, arr2, 16);//若将16改为4,则只打印1(1000)
for (int i = 0;i<4,i++){
	printf("%d\n", arr[i]);
}

void*Memcpy(void*dst,const void*src,size_t count){
	void*ret = dst;
	assert(dst);
	assert(src);
	while(count--){
		*(char*)dst = *(char*)src;
		dst = (char*)dst + 1;
		src = (char*)src + 1;
	}
	return (ret);
}

