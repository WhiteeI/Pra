#include <stdio.h>
#include <stdlib.h>
int main() {
	int sum = 0;
	for (int i = 1; i <= 100; ++i) {
		if (i % 10 == 9 || i / 10 == 9) {
			sum+=1;
		}
	}
	printf("�ܹ�������%d��9\n", sum);
	system("pause");
	return 0;
	
}