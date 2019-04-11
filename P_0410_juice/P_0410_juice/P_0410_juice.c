#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
	int money = 20;
	int bottle = 0;
	while (money != 0) {
		bottle += money;
		money /= 2;
	}
	printf("%d\n", bottle + 1);
	system("pause");
	return 0;
}
