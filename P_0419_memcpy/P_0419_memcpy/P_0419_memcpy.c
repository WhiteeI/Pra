#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void* Mymemcpy(void* dest,const void* src,size_t num) {
	if (dest == NULL || src == NULL) {
		return NULL;
	}
	char* temp = dest;
	const char* ret = src;
	while (num--) {
		*temp++ = *ret++;
	}
	return dest;
}

int main() {
	char str1[] = "abcdefg";
	char str2[] = "qwerty";
	//int arr[] = { 1, 2, 3 };
	char* p = (char*)Mymemcpy(str1,str2, 4);
	printf("%s\n", p);
	system("pause");
	return 0;
}
