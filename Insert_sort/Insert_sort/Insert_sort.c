#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void insert_sort(int a[], int n) {
	for (int i = 1; i < n; ++i) {
		int temp = a[i];
		int j = i-1;
		while (j>=0 && temp < a[j]) {
			a[j+1] = a[j];
			--j;
		}
		a[j+1] = temp;
	}
}
int main() {
	int a[] = { 8, 5, 9, 6, 7, 1, 4, 2, 3, 0 };
	insert_sort(a, 10);
	for (int i = 0; i < 10; ++i) {
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}
