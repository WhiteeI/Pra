#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void* Mymemmove(void* dest, const void* src, size_t num) {
	if (dest == NULL || src == NULL) {
		return NULL;
	}
	if (dest<src || (char*)dest>((const char*)src) + num) {
		char* temp = dest;
		const char* ret = src;
		while (num--) {
			*temp++ = *ret++;
		}
		return dest;
	}
	else {
		char* temp = dest;
		const char* ret = src;
		while (num--) {
			*(temp + num) = *(ret + num);
		}
		return dest;
	}
}

int main() {
	char str[] = "abcdef";
	char* p = (char*)Mymemmove(str+2, str, 3);
	printf("%s\n", p);
	system("pause");
	return 0;
}
