#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void FindNum(int arr[], int len) {
	for (int i = 0; i < len; ++i) {
		int j = 0;
		for (; j < len; ++j) {
			if (arr[i] == arr[j] && i != j) {
				break;
			}
		}
		if (j == len) {
			printf("%d\n", arr[i]);
		}
	}
}

int main() {
	int arr[10] = { 1, 6, 7, 3, 4, 5, 3, 4, 6, 1 };
	FindNum(arr, 10);
	system("pause");
	return 0;
}
