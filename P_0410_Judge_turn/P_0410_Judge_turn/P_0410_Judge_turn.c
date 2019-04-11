#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
void Judge_turn(char* p1, char* p2) {
	assert(*p1);
	assert(*p2);
	int len1 = strlen(p1);
	int len2 = strlen(p2);
	if (len1 != len2) {
		return;
	}
	for (int i = 0; i < len1; ++i) {
		char temp = p1[0];
		for (int j = 0; j < len1 - 1; ++j) {
			p1[j] = p1[j + 1];
		}
		p1[len1 - 1] = temp;
		if (strcmp(p1, p2) == 0) {
			printf("是旋转得到的\n");
			return;
		}
	}
	printf("不是旋转得到的\n");
}

int main() {
	char arr1[] = "abc";
	char arr2[] = "cab";
	Judge_turn(arr1, arr2);
	system("pause");
	return 0;
}
