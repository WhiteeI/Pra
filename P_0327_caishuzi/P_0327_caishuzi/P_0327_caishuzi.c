#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void Game() {
	srand( (unsigned int) time(0) );
	int num = rand() % 100 + 1;
	while (1){
		printf("请输入您猜的数\n");
		int player = 0;
		scanf("%d", &player);
		if (player > num) {
			printf("猜大了\n");
		}
		else if (player < num) {
			printf("猜小了\n");
		}
		else {
			printf("猜对了\n");
			break;
		}
	}
}
int main() {
	while (1){
		printf("-------------------------------\n");
		printf("是否开始游戏\n");
		printf("1.开始游戏\n");
		printf("0.结束游戏\n");
		printf("-------------------------------\n");
		int choice = 0;
		printf("请输入您的选择\n");
		scanf("%d", &choice);
		if (choice == 1) {
			printf("游戏开始\n");
			Game();
		}
		else if (choice == 0) {
			printf("游戏结束\n");
			break;
		}
		else {
			printf("您的输入有误,请重新输入\n");
		}
	}
	system("pause");
	return 0;
}