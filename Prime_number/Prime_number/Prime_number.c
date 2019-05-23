

#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i,j;
	for (i = 10000; i <= 20000; i++)
	{
		for (j = 2; j < i; j++)
		{
			if (i%j == 0)
				 break;
		}
		if (i == j)
			printf("%d\t", i);
	}
	system("pause");
	return 0;
}