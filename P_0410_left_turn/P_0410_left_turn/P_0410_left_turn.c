#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
void Left_turn(char* p, int k) {
	assert(*p);
	int len = strlen(p);
	for (int i = 0; i < k; ++i) {
		int j = 0;
		char temp = p[0];
		for (; j < len - 1; j++) {
			p[j] = p[j + 1];
		}
		p[len - 1] = temp;
	}
}

int main() {
	char arr[] = "abcd";
	Left_turn(arr, 2);
	printf("%s\n", arr);
	system("pause");
	return 0;
}
