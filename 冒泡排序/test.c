#include <iostream>
using namespace std;

void BubbleSortUp(int k[], int len) {
	int i, j, temp, count1 = 0, count2 = 0;
	for (i = 0; i < len - 1; i++) {
		for (j = 0; j < len - 1 - i; j++) {
			count1++;
			if (k[j] > k[j + 1]) {
				count2++;
				temp = k[j + 1];
				k[j + 1] = k[j];
				k[j] = temp;
			}
		}
	}
	cout << "总共进行了" << count1 << "次比较， " << count2 << "次移动" << endl;
}

int main() {
	int i;
	int arr[10] = { 1, 3, 15, 2, 4, 17, 8, 6, 9, 0 };
	BubbleSortUp(arr, 10);
	cout << "after sort: arr =  " << endl;
	for (i = 0; i < 10; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;

	return 0;
}
