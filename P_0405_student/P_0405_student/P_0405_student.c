#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Allexchange(char* str) {
	int len = strlen(str) - 1;
	if (*str == '\0') {
		return;
	}
	char temp;
	temp = str[0];
	str[0] = str[len];
	str[len] = '\0';
	Allexchange(str + 1);
	str[len] = temp;
}
void Swap(char* begin, char* end) {
	while (begin < end) {
		char tmp;
		tmp = *begin;
		*begin = *end;
		*end = tmp;
		begin++;
		end--;
	}
}
void Partexchange(char* str) {
	char* begin = str;
	char* end = str;
	while (*str != '\0'){
		end = str;
		++str;
		if (*str == ' ' || *str == '\0'){
			Swap(begin, end);
			++str;
			begin = str;
		}
	}
}
int main() {
	char test[] = "student a am i";
	Allexchange(test);
	printf("%s\n", test);
	Partexchange(test);
	printf("%s\n", test);
	system("pause");
	return 0;
}
