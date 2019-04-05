#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void Pascal_Triangle(int n) {
	int arr[100][100] = { 0 };
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			arr[i][0] = 1;
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			arr[i][i] = 1;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
int main() {
	int n = 0;
	printf("请输入杨辉三角的行数\n");
	scanf("%d", &n);
	Pascal_Triangle(n);
	system("pause");
	return 0;
}
