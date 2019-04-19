#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int Mystrcmp(char* str1, char* str2) {
	assert(*str1);
	assert(*str2);
	while (*str1 != '\0') {
		if (*str1 > *str2) {
			return 1;
		}
		else if (*str1 < *str2) {
			return -1;
		}
		else {
			++str1;
			++str2;
		}
	}
	if (*str2 != '\0') {
		return -1;
	}
	else {
		return 0;
	}
}

int main() {
	char str1[] = "abcdef";
	char str2[] = "abcdef";
	int result = Mystrcmp(str1, str2);
	printf("%d\n", result);
	system("pause");
	return 0;
}
