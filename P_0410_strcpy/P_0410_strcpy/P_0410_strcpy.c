#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
char* mystrcpy(char* str1, char* str2) {
	assert(*str1);
	assert(*str2);
	for (int i = 0; str1[i] != '\0'; ++i) {
		str1[i] = str2[i];
	}
	return str1;
}

int main() {
	char str1[] = "abc";
	char str2[] = "cba";
	char* str3=mystrcpy(str1, str2);
	printf("%s\n", str3);
	system("pause");
	return 0;
}
