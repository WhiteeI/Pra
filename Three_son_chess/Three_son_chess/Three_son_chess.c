#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Max_Row 15 //使用宏定义，以便以后修改棋盘大小
#define Max_Col 15 //使用宏定义，以便以后修改棋盘大小

char ChessBoard[Max_Row][Max_Col]; //定义棋盘

//初始化棋盘,把数组每个元素都设为空格,玩家落子为o,电脑落子为x
void Init() {     
	for (int row = 0; row < Max_Row; ++row) {
		for (int col = 0; col < Max_Col; ++col) {
			ChessBoard[row][col] =' ';
		}
	}
}

//打印棋盘
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

//电脑对战：玩家落子
void PlayerMove() {
	printf("到您落子了\n");
	while (1) {
		printf("请输入您想要落子的坐标\n");
		int row, col;
		scanf("%d %d", &row, &col);
		//如果行数或者列数不合法，继续下一次循环
		if (row >= Max_Row || col >= Max_Col || row<0 || col<0) {
			printf("您的输入无效!\n");
			continue;
		}
		//如果落子的位置不是空格，提示玩家已落子，继续下一次循环
		if (ChessBoard[row][col] != ' ') {
			printf("您输入的位置已落子\n");
			continue;
		}
		ChessBoard[row][col] = 'o';
		break;
	}	
}
//电脑对战：电脑落子
void ComputerMove() {
	printf("电脑落子\n");
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
//玩家对战：玩家1落子
void PlayerMove1() {
	printf("到玩家1落子了\n");
	while (1) {
		printf("请输入玩家1想要落子的坐标\n");
		int row, col;
		scanf("%d %d", &row, &col);
		//如果行数或者列数不合法，继续下一次循环
		if (row >= Max_Row || col >= Max_Col || row<0 || col<0) {
			printf("您的输入无效!\n");
			continue;
		}
		//如果落子的位置不是空格，提示玩家已落子，继续下一次循环
		if (ChessBoard[row][col] != ' ') {
			printf("您输入的位置已落子\n");
			continue;
		}
		ChessBoard[row][col] = 'o';
		break;
	}
}
//玩家对战：玩家2落子
void PlayerMove2() {
	printf("到玩家2落子了\n");
	while (1) {
		printf("请输入玩家2想要落子的坐标\n");
		int row, col;
		scanf("%d %d", &row, &col);
		//如果行数或者列数不合法，继续下一次循环
		if (row >= Max_Row || col >= Max_Col || row<0 || col<0) {
			printf("您的输入无效!\n");
			continue;
		}
		//如果落子的位置不是空格，提示玩家已落子，继续下一次循环
		if (ChessBoard[row][col] != ' ') {
			printf("您输入的位置已落子\n");
			continue;
		}
		ChessBoard[row][col] = 'x';
		break;
	}
}

//判断比赛胜负
char JudgeWinner() {
	//先判断横着胜利的
    //遍历到倒数第五个格子，要判断和最后的四个格子是否相同，
	//所以为最大格数减4
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
	//向右斜着胜利的
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
	//判断竖着胜利的
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
		//判断向左斜着胜利的
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
	//1.初始化棋盘
	Init();
	char winner = ' ';
	while (1) {
		//2.打印棋盘
		Print();
		//3.玩家落子
		PlayerMove();
		//4.检测胜负
		winner=JudgeWinner();
		if (winner != ' ') {
			break;
		}
		//5.电脑落子
		ComputerMove();
		//6.检测胜负
		winner = JudgeWinner();
		if (winner != ' ') {
			break;
		}
	}
	Print();
	if (winner == 'o') {
		printf("您赢了\n");
	}
	if (winner == 'x') {
		printf("您输了\n");
	}
}
void GamePlayer() {
	//1.初始化棋盘
	Init();
	//2.打印棋盘
	Print();
	char winner = ' ';
	while (1) {
		//3.玩家1落子
		PlayerMove1();
		Print();
		//4.检测胜负
		winner = JudgeWinner();
		if (winner != ' ') {
			break;
		}
		//5.玩家2落子
		PlayerMove2();
		Print();
		//6.检测胜负
		winner = JudgeWinner();
		if (winner != ' ') {
			break;
		}
	}
	if (winner == 'o') {
		printf("玩家1赢了\n");
	}
	if (winner == 'x') {
		printf("玩家2赢了\n");
	}
}

int  Menu() {
	printf("欢迎来到五子棋！\n");
	printf("--------------------\n");
	printf("1.电脑对战\n");
	printf("2.玩家对战\n");
	printf("0.结束游戏\n");
	printf("--------------------\n");
	printf("请输入您的选择\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}


int main() {
	
	while (1) {
		int choice=Menu();
		if (choice == 1) {
		printf("电脑对战\n");
		GameComputer();
		}
		else if (choice == 2) {
		printf("玩家对战\n");
		GamePlayer();
		}
		else if (choice == 0) {
		printf("下次再见\n");
		break;
		}
		else {
		printf("请输入1或0\n");
		}
	}
	
	system("pause");
	return 0;
}

