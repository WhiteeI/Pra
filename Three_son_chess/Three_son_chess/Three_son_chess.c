#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Max_Row 15 //ʹ�ú궨�壬�Ա��Ժ��޸����̴�С
#define Max_Col 15 //ʹ�ú궨�壬�Ա��Ժ��޸����̴�С

char ChessBoard[Max_Row][Max_Col]; //��������

//��ʼ������,������ÿ��Ԫ�ض���Ϊ�ո�,�������Ϊo,��������Ϊx
void Init() {     
	for (int row = 0; row < Max_Row; ++row) {
		for (int col = 0; col < Max_Col; ++col) {
			ChessBoard[row][col] =' ';
		}
	}
}

//��ӡ����
void Print() {
	printf("  0   1   2   3   4   5   6   7   8   9   10  11  12  13  14\n");
	for (int row = 0; row < Max_Row; ++row) {
		printf("| %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |%d\n",
			ChessBoard[row][0],ChessBoard[row][1], ChessBoard[row][2],
			ChessBoard[row][3],ChessBoard[row][4],ChessBoard[row][5],
			ChessBoard[row][6],ChessBoard[row][7],ChessBoard[row][8],
			ChessBoard[row][9], ChessBoard[row][10], ChessBoard[row][11],
			ChessBoard[row][12], ChessBoard[row][13], ChessBoard[row][14], row);
		printf("|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n",row);
	}
}

//���Զ�ս���������
void PlayerMove() {
	printf("����������\n");
	while (1) {
		printf("����������Ҫ���ӵ�����\n");
		int row, col;
		scanf("%d %d", &row, &col);
		//������������������Ϸ���������һ��ѭ��
		if (row >= Max_Row || col >= Max_Col || row<0 || col<0) {
			printf("����������Ч!\n");
			continue;
		}
		//������ӵ�λ�ò��ǿո���ʾ��������ӣ�������һ��ѭ��
		if (ChessBoard[row][col] != ' ') {
			printf("�������λ��������\n");
			continue;
		}
		ChessBoard[row][col] = 'o';
		break;
	}	
}
//���Զ�ս����������
void ComputerMove() {
	printf("��������\n");
	while (1) {	
			int row, col;
			srand((unsigned int)time(0));
			row = rand() % 15;
			col = rand() % 15;
			if (ChessBoard[row][col] == ' ') {
				ChessBoard[row][col] = 'x';
				break;
			}
		}			
}
//��Ҷ�ս�����1����
void PlayerMove1() {
	printf("�����1������\n");
	while (1) {
		printf("���������1��Ҫ���ӵ�����\n");
		int row, col;
		scanf("%d %d", &row, &col);
		//������������������Ϸ���������һ��ѭ��
		if (row >= Max_Row || col >= Max_Col || row<0 || col<0) {
			printf("����������Ч!\n");
			continue;
		}
		//������ӵ�λ�ò��ǿո���ʾ��������ӣ�������һ��ѭ��
		if (ChessBoard[row][col] != ' ') {
			printf("�������λ��������\n");
			continue;
		}
		ChessBoard[row][col] = 'o';
		break;
	}
}
//��Ҷ�ս�����2����
void PlayerMove2() {
	printf("�����2������\n");
	while (1) {
		printf("���������2��Ҫ���ӵ�����\n");
		int row, col;
		scanf("%d %d", &row, &col);
		//������������������Ϸ���������һ��ѭ��
		if (row >= Max_Row || col >= Max_Col || row<0 || col<0) {
			printf("����������Ч!\n");
			continue;
		}
		//������ӵ�λ�ò��ǿո���ʾ��������ӣ�������һ��ѭ��
		if (ChessBoard[row][col] != ' ') {
			printf("�������λ��������\n");
			continue;
		}
		ChessBoard[row][col] = 'x';
		break;
	}
}

//�жϱ���ʤ��
char JudgeWinner() {
	//���жϺ���ʤ����
    //������������������ӣ�Ҫ�жϺ������ĸ������Ƿ���ͬ��
	//����Ϊ��������4
	for (int row = 0; row < Max_Row; ++row) {
		for (int col = 0; col < (Max_Col - 4); ++col) {
			if (ChessBoard[row][col] != ' ') {
				if (ChessBoard[row][col] == ChessBoard[row][col + 1] &&
					ChessBoard[row][col] == ChessBoard[row][col + 2] &&
					ChessBoard[row][col] == ChessBoard[row][col + 3] &&
					ChessBoard[row][col] == ChessBoard[row][col + 4]) {
					return ChessBoard[row][col];
				}
			}	
		}
	}
	//����б��ʤ����
	for (int row = 0; row<(Max_Row-4); ++row) {
		for (int col = 0; col < (Max_Col-4); ++col) {
			if (ChessBoard[row][col] != ' ') {
				if (ChessBoard[row][col] == ChessBoard[row + 1][col + 1] &&
					ChessBoard[row][col] == ChessBoard[row + 2][col + 2] &&
					ChessBoard[row][col] == ChessBoard[row + 3][col + 3] &&
					ChessBoard[row][col] == ChessBoard[row + 4][col + 4]) {
					return ChessBoard[row][col];
				}
			}	
		}
	}
	//�ж�����ʤ����
	for (int row = 0; row < (Max_Row - 4); ++row) {
		for (int col = 0; col < Max_Col; ++col) {
			if (ChessBoard[row][col] != ' ') {
				if (ChessBoard[row][col] == ChessBoard[row + 1][col] &&
					ChessBoard[row][col] == ChessBoard[row + 2][col] &&
					ChessBoard[row][col] == ChessBoard[row + 3][col] &&
					ChessBoard[row][col] == ChessBoard[row + 4][col]) {
					return ChessBoard[row][col];
				}
			}	
		}
	}
		//�ж�����б��ʤ����
	for (int row = 0; row < (Max_Row - 4); ++row) {
		for (int col = 4; col < Max_Col; ++col) {
			if (ChessBoard[row][col] != ' ') {
				if (ChessBoard[row][col] == ChessBoard[row + 1][col - 1] &&
					ChessBoard[row][col] == ChessBoard[row + 2][col - 2] &&
					ChessBoard[row][col] == ChessBoard[row + 3][col - 3] &&
					ChessBoard[row][col] == ChessBoard[row + 4][col - 4]) {
					return ChessBoard[row][col];
				}
			}	
		}
	}
	return ' ';
}


void GameComputer() {
	//1.��ʼ������
	Init();
	char winner = ' ';
	while (1) {
		//2.��ӡ����
		Print();
		//3.�������
		PlayerMove();
		//4.���ʤ��
		winner=JudgeWinner();
		if (winner != ' ') {
			break;
		}
		//5.��������
		ComputerMove();
		//6.���ʤ��
		winner = JudgeWinner();
		if (winner != ' ') {
			break;
		}
	}
	Print();
	if (winner == 'o') {
		printf("��Ӯ��\n");
	}
	if (winner == 'x') {
		printf("������\n");
	}
}
void GamePlayer() {
	//1.��ʼ������
	Init();
	//2.��ӡ����
	Print();
	char winner = ' ';
	while (1) {
		//3.���1����
		PlayerMove1();
		Print();
		//4.���ʤ��
		winner = JudgeWinner();
		if (winner != ' ') {
			break;
		}
		//5.���2����
		PlayerMove2();
		Print();
		//6.���ʤ��
		winner = JudgeWinner();
		if (winner != ' ') {
			break;
		}
	}
	if (winner == 'o') {
		printf("���1Ӯ��\n");
	}
	if (winner == 'x') {
		printf("���2Ӯ��\n");
	}
}

int  Menu() {
	printf("��ӭ���������壡\n");
	printf("--------------------\n");
	printf("1.���Զ�ս\n");
	printf("2.��Ҷ�ս\n");
	printf("0.������Ϸ\n");
	printf("--------------------\n");
	printf("����������ѡ��\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}


int main() {
	
	while (1) {
		int choice=Menu();
		if (choice == 1) {
		printf("���Զ�ս\n");
		GameComputer();
		}
		else if (choice == 2) {
		printf("��Ҷ�ս\n");
		GamePlayer();
		}
		else if (choice == 0) {
		printf("�´��ټ�\n");
		break;
		}
		else {
		printf("������1��0\n");
		}
	}
	
	system("pause");
	return 0;
}

