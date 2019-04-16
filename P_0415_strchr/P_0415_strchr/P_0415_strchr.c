#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
char* Mystrchr(char* str, char c) {
	assert(*str);
	while (*str != '\0') {
		if (*str == c) {
			return str;
		}
		++str;
	}
	return NULL;
}
int main() {
	char str[] = "abcdef";
	char* temp = Mystrchr(str, 'f');
	if (!temp) {
		printf("这个字符不存在\n");
	}
	else {
		printf("%s\n", temp);
	}
	system("pause");
	return 0;
}
