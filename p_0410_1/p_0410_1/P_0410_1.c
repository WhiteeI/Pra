#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void Rank(int arr[], int length) {
	int left = 0;
	int right = length - 1;
	while (left < right) {
		if (arr[left] % 2 == 0) {
			int temp = arr[right];
			arr[right] = arr[left];
			arr[left] = temp;
			--right;
		}
		else{
			++left;
		}
	}
	
}
int main() {
	int arr[] = { 2, 3, 4, 6, 7, 0, 1, 3 };
	Rank(arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
		printf("%d\n", arr[i]);
	}

	system("pause");
	return 0;
}
