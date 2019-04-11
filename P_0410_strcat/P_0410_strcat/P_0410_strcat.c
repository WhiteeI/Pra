#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
char* mystrcat(char* str1,char* str2) {
	assert(*str1);
	assert(*str2);
	char* p = str1;
	while (*str1 != '\0') {
		++str1;
	}
	while (*str1++ = *str2++);
	return p;
	
}
int main() {
	char str1[100] = "abc";
	char str2[100] = "def";
	char* p = mystrcat(str1, str2);
	printf("%s\n", p);
	system("pause");
	return 0;
}
