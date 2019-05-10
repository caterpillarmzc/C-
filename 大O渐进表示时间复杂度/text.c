void Func(int n){
	int count = 0;
	for (int i = 0; i < n;++i){
		for (int j = 0; j < n;++j){
			++count;
		}
	}
	for (int k = 0; k < 2 * n;++k){
		++count;
	}
	int m = 10;
	while (m--){
		++count;
	}
	printf("%d\n", count);
}


int *a = (int*)malloc(n);//堆上开辟和n相关的空间
int a[n];//栈上开辟空间
//递归函数,调用栈时占用空间和n的关系

long long Fib(int n){
	if (n<2){
		return n;
	}
	return Fib(n - 1) + Fib(n - 2);
}
