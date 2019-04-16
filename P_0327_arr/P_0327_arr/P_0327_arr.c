#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void Init(int arr[]) {
	for (int i = 0; i < 10; ++i) {
		scanf("%d", &arr[i]);
	}
}
void Empty(int arr[]) {
	for (int i = 0; i < 10; ++i) {
		arr[i] = 0;
	}
}
void Reverse(int arr[]) {
	int temp;
	for (int i = 0; i < 5; ++i) {
	    temp = arr[i];
		arr[i] = arr[9 - i];
		arr[9 - i] = temp;
	}
}
int main() {
	int arr[10];
	Init(arr);
	Reverse(arr);
	for (int i = 0; i < 10; ++i) {
		printf("%d\t", arr[i]);
	}
	printf("\n");
	Empty(arr);
	for (int i = 0; i < 10; ++i) {
		printf("%d\t", arr[i]);
	}
	system("pause");
	return 0;
}