#include <iostream>
using namespace std;

void SelectSort(int k[], int len) {
	int temp, min;
	for (int i = 0; i < len - 1; i++) {
		min = i;
		for (int j = i + 1; j < len; j++) {
			if (k[j] < k[min])
				min = j;
		}

		if (min != i) {
			temp = k[min];
			k[min] = k[i];
			k[i] = temp;
		}
	}
}

int main() {
	int i;
	int arr[10] = { 1, 3, 15, 2, 4, 17, 8, 6, 9, 0 };
	SelectSort(arr, 10);
	cout << "after sort: arr =  " << endl;
	for (i = 0; i < 10; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;

	return 0;
}
