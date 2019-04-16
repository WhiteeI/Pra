#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
char* Mystrstr(char* str1, char* str2) {
	assert(*str1);
	assert(*str2);
	char* temp1 = str1;
	char* temp2 = str2;
	int len = 0;
	while (*str2 != '\0') {
		++str2;
		++len;
	}
	str2 = temp2;
	while (*str1 != '\0') {
		if (*str1 == *str2) {
			temp1 = str1;
			int i = 0;
			for (; i < len; ++i) {
				if (str1[i] != str2[i]) {
					break;
				}
			}
			if (i == len) {
				return temp1;
			}
		}
		++str1;
	}
	return NULL;
}

int main() {
	char str1[] = "abcdefg";
	char str2[] = "bcd";
	char* temp = Mystrstr(str1, str2);
	//printf("%s", temp);
	if (!temp) {
		printf("不是子串\n");
	}
	else {
		printf("是子串\n");
	}
	system("pause");
	return 0;
}
