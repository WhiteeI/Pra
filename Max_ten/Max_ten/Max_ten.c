#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int getMax(int a[10]) {
	int max=a[0];
	if (max < a[1]) {
		max = a[1];
	}
	if (max < a[2]) {
		max = a[2];
	}
	if (max < a[3]) {
		max = a[3];
	}
	if (max < a[4]) {
		max = a[4];
	}
	if (max < a[5]) {
		max = a[5];
	}
	if (max < a[6]) {
		max = a[6];
	}
	if (max < a[7]) {
		max = a[7];
	}
	if (max < a[8]) {
		max = a[8];
	}
	if (max < a[9]) {
		max = a[9];
	}
	return max;
}
int main() {
	int arr[10],max;
	int i = 0 , num;
	while (i <= 9) {
		scanf("%d",& num);
		arr[i] = num;
		i+=1;
	}
	max = getMax(arr);
	printf("最大值为:%d\n", max);
	system("pause");
	return 0;
}
