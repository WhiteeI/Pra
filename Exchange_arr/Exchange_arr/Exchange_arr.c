#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void Exchange_arr(int a[10],int b[10]){
	for (int i = 0; i < 10; ++i) {
		int t;
		t = a[i];
		a[i] = b[i];
		b[i] = t;
	}
	
}

int main() {	
	int  a[10];
	int  b[10];
	printf("请输入a数组的值:\n");
	for (int i = 0; i < 10; ++i) {
		int num;
		scanf("%d",&num);
		a[i] = num;
	}
	printf("请输入b数组的值:\n");
	for (int i = 0; i < 10; ++i) {
		int num;
		scanf("%d",&num);
		b[i] = num;
	}
	Exchange_arr(a, b);
	printf("交换后a数组的值为:\n");
	for (int i = 0; i < 10; ++i) {
		printf("%d\t", a[i]);
	}
	printf("\n交换后b数组的值为:\n");
	for (int i = 0; i < 10; ++i) {
		printf("%d\t", b[i]);
	}
	system("pause");
	return 0;
}