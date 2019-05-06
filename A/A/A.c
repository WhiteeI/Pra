#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
long long* Fibonacci(size_t n) {
	if (n == 0) {
		return NULL;
	}
	long long* fibarray = (long long*)malloc(n * 8 + 1);
	fibarray[0] = 0;
	fibarray[1] = 1;
	for (size_t i = 2; i < n; ++i) {
		fibarray[i] = fibarray[i - 1] + fibarray[i - 2];
	}
	return fibarray;
}

int main() {
	long long* fib = Fibonacci(10);
	printf("%d",fib[9]);
	free(fib);
	system("pause");
	return 0;
}
