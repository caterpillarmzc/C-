#include<stdio.h>
#include<Windows.h>
#include<assert.h>

void find_data(int arr[], int size){
	int i = 0, j = 0;
	int flag = 0;
	printf("data is : ");
	for (; i < size; i++){
		flag = 0;
		for (j = 0; j < size; j++){
			if (arr[j] == arr[i] && i != j)
				flag = 1;
		}
		if (0 == flag)
			printf(" %d  ", arr[i]);

	}
	printf("\n");
}


int main(){
	int arr[] = { 1, 2, 4, 3, 1, 5, 2, 3 };
	int len = 0;
	len = sizeof(arr) / sizeof(arr[0]);
	find_data(arr, len);
	system("pause");
	return 0;
}