#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	int x, y, z, t;
	scanf("%d %d %d", &x, &y, &z);
	//���xС��y������x��y��ֵ
	if (x < y) {
		t = x;
		x = y;
		y = t;
	}
	//���yС��z������y��z��ֵ
	if (y < z) {
		t = y;
		y = z;
		z = t;
	}
	//���xС��y������x��y��ֵ
	if (x < y) {
		t = x;
		x = y;
		y = t;
	}
	printf("%d>%d>%d", x, y, z);
	system("pause");
	return 0;
}