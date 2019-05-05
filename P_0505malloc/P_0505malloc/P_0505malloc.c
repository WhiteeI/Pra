#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int main() {
	char* p = (char*)malloc(100);
	if (p == NULL) {
		assert(0);
	}
	char* c = (char*)calloc(1, 100);
	if (c == NULL) {
		assert(0);
	}
	free(p);
	free(c);
	system("pause");
	return 0;
}
