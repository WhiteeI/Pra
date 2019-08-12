#include <stdio.h>
#include <stdlib.h>
void Bubble_sort(int a[],int n) {
	int right = n;
	while (right > 0) {
		for (int i = 0; i < right-1; ++i) {
			if (a[i]>a[i + 1]) {
				int temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
		}
		--right;
	}
}
int main() {
	int a[] = { 10, 1, 35, 61, 89, 36, 55 };
	Bubble_sort(a, 7);
	for (int i = 0; i < 7; ++i) {
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}
