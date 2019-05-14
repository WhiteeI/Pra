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

long long add(int n) {
	int array[100];
	array[1] = 1;
	array[2] = 2;
	int i = 3;
	/*if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 2;
	}*/
	while (i <= n) {
		array[i] = array[i - 1] + array[i - 2];
		++i;
	}
	return array[n];
}
long jumpStepByFor(int n){
	int result[] = { 0, 1, 2 };
	if (n < 3){
		return result[n];
	}
	long jumpCount1 = 1;
	long jumpCount2 = 2;
	long jumpCountn = 0;
	for (int i = 3; i <= n; ++i) {
		jumpCountn = jumpCount1 + jumpCount2;
		jumpCount1 = jumpCount2;
		jumpCount2 = jumpCountn;
	}
	return jumpCountn;
}
int main() {
	long long a = add(43);
	long b=jumpStepByFor(46);
	printf("%lld\n", a);
	printf("%ld\n", b);
	system("pause");
	return 0;
}
