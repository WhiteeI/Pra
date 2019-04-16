#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void table(int row) {
	for (int i = 1; i <= row; ++i) {
		for (int j = 1; j <= i; ++j) {
			printf("%d*%d=%d\t", j, i, i*j);
		}
		printf("\n");
	}
}
int main() {
	int row;
	printf("输入乘法表的行数\n");
	scanf("%d", &row);
	table(row);

	system("pause");
	return 0;

}