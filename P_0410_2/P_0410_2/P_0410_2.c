#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void Find(int arr[][3], int num) {
	int row = 0;
	int col = 2;
	while (row < 3 && col >= 0) {
		if (num < arr[row][col]) {
			--col;
		}
		else if (num>arr[row][col]) {
			++row;
		}
		else {
			printf("找到了\n");
			return;
		}
	}
	printf("没找到\n");
}
int main() {
	int arr[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	Find(arr, 7);
	Find(arr, 11);
	system("pause");
	return 0;
}
