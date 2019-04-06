#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	int x, y, z, t;
	scanf("%d %d %d", &x, &y, &z);
	//如果x小于y，交换x和y的值
	if (x < y) {
		t = x;
		x = y;
		y = t;
	}
	//如果y小于z，交换y和z的值
	if (y < z) {
		t = y;
		y = z;
		z = t;
	}
	//如果x小于y，交换x和y的值
	if (x < y) {
		t = x;
		x = y;
		y = t;
	}
	printf("%d>%d>%d", x, y, z);
	system("pause");
	return 0;
}