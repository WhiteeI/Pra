#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void Game() {
	srand( (unsigned int) time(0) );
	int num = rand() % 100 + 1;
	while (1){
		printf("���������µ���\n");
		int player = 0;
		scanf("%d", &player);
		if (player > num) {
			printf("�´���\n");
		}
		else if (player < num) {
			printf("��С��\n");
		}
		else {
			printf("�¶���\n");
			break;
		}
	}
}
int main() {
	while (1){
		printf("-------------------------------\n");
		printf("�Ƿ�ʼ��Ϸ\n");
		printf("1.��ʼ��Ϸ\n");
		printf("0.������Ϸ\n");
		printf("-------------------------------\n");
		int choice = 0;
		printf("����������ѡ��\n");
		scanf("%d", &choice);
		if (choice == 1) {
			printf("��Ϸ��ʼ\n");
			Game();
		}
		else if (choice == 0) {
			printf("��Ϸ����\n");
			break;
		}
		else {
			printf("������������,����������\n");
		}
	}
	system("pause");
	return 0;
}