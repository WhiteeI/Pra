#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int average(int a,int b) {
	int aver = 0;
	aver=(a&b)+((a^b)>>1);
	return aver;
}
int main() {
	int a = 0, b = 0,aver=0;
	scanf("%d %d", &a, &b);
	aver = average(a, b);
	printf("%d\n", aver);
	system("pause");
	return 0;
}
