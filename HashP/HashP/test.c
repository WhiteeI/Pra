#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <memory.h>
#include <string.h>

#include "zsha256.h"

int main(int argc, char* argv[])
{
	uint8_t* src = NULL;
	uint32_t len = 0;
	uint32_t sha[8];
	int i = 0;

	/*if (argc == 1) {
		printf("no input data!\n");
		system("pause");
		return 0;
	}*/

	/*src = (uint8_t*)argv[1];
	len = strlen(argv[1]);*/
	src = "yang";
	len = 4;
	printf("len=%d\n", len);
	//printf("src=%s\n", argv[1]);
	printf("src=%s\n", src);
	zsha256(src, len, sha);

	printf("sha=");
	for (i = 0; i<8; i++) {
		printf("%08x", sha[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
