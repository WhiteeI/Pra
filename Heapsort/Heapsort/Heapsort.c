#include <stdio.h>
#include <stdlib.h>
void swap(int a[], int i, int k) {
	int temp = a[i];
	a[i] = a[k];
	a[k] = temp;
}
void adjust_heap(int a[], int i, int length) {
	int temp = a[i];
	for (int k = 2 * i + 1; k < length; k = 2 * k + 1) {
		if (k + 1 < length&&a[k] < a[k + 1]) {
			++k;
		}
		if (a[k] > temp) {
			swap(a, i, k);
			i = k;
		}
		else {
			break;
		}
	}
}
void heapsort(int a[],int n) {
	for (int i = n / 2 - 1; i >= 0; --i) {
		adjust_heap(a, i, n);
	}
	for (int j = n - 1; j > 0; --j) {
		swap(a, 0, j);
		adjust_heap(a, 0, j);
	}
}


int main() {
	int a[] = { 2, 1, 4, 3, 6, 5, 8, 7 };
	heapsort(a,8);
	for (int i = 0; i < 8; ++i) {
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}
