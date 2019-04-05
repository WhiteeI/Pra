#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
unsigned int  reverse_bit(unsigned int value) {
	unsigned int sum = 0;
	for (int i = 0; i < 32; i++) {
		sum += (value >> i & 1)<<(31-i);
	}
	return sum;
}
int main() {
	int value = 0, sum = 0;
	scanf("%d", &value);
	sum = reverse_bit(value);
	printf("%u\n", sum);
	system("pause");
	return 0;
}
