#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>
void sort(int a[], int size) {
	int max = a[0],min=a[0];
	for (int i = 1; i < size; ++i) {
		if (a[i]>max) {
			max = a[i];
		}
		if (a[i] < min) {
			min = a[i];
		}
	}
	int* temp = (int*)malloc(sizeof(int)*(max - min + 1));
	for (int i = 0; i < max - min + 1; ++i) {
		temp[i] = 0;
	}
	for (int i = 0; i < size; ++i) {
		++temp[a[i]-min];
	}
	for (int i = 0, j = 0; i < max-min+1; ++i) {
		int sum = temp[i];
		while (sum) {
			a[j++] = i+min;
			--sum;
		}
	}
	free(temp);
}
int main() {
	int a[] = { 2, 1, 4, 3,3,3,3,3, 6, 5, 8,7 };
	sort(a, 12);
	for (int i = 0; i < 12; ++i) {
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}