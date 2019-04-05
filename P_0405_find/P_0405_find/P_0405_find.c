#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
	int arr[11] = {0};
	printf("ÊäÈë11¸öÊı×Ö\n");
	for (int i = 0; i < 11; ++i) {
		scanf("%d", &arr[i]);
	}
	int ret = 0;
	for (int i = 0; i < 11; i++) {
		ret = ret ^ arr[i];
	}
	printf("%d\n", ret);
	system("pause");
	return 0;
}
