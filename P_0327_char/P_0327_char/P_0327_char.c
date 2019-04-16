#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
	printf("ÇëÊäÈë×Ö·û\n");
	char a[] = { 0 };
	scanf("%s", a);
	for (int i = 0; a[i]!='\0'; ++i) {
		if (a[i] >= 'a' && a[i] <= 'z') {
			a[i] -= 32;
			printf("%c", a[i]);
		}
		else if (a[i] >= 'A' && a[i] <= 'Z') {
			a[i] += 32;
			printf("%c", a[i]);
		}
		else {
			continue;
		}
	}
	
	system("pause");
	return 0;
}