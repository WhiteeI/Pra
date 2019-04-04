#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#define Max_row 9
#define Max_col 9
#define Mine_count 10
//初始化,1表示雷,x表示未翻开
void Init(char ShowMap[Max_row][Max_col], char MineMap[Max_row][Max_col]) {
	for (int row = 0; row < Max_row; ++row) {
		for (int col = 0; col < Max_col; ++col) {
			ShowMap[row][col] = 'x';
			MineMap[row][col] = '0';
		}
	}
	int n = Mine_count;
	while (n>0) {
		srand((unsigned int)time(0));
		int row = rand() % Max_row;
		int col = rand() % Max_col;
		if (MineMap[row][col] != '0') {
			continue;
		}
		MineMap[row][col] = '1';
		--n;
	}
}
//打印地图
void PrintMap(char map[Max_row][Max_col]) {
	printf("  | ");
	for (int col = 0; col < Max_col; ++col) {
		printf("%d ", col);
	}
	printf("\n");
	for (int row = 0; row < Max_row; ++row) {
		printf(" %d| ", row);
		for (int col = 0; col < Max_col; ++col) {
			printf("%c ", map[row][col]);
		}
		printf("\n");
	}
}
//判断周围雷的数量
int UpdateShowMap(char ShowMap[Max_row][Max_col],char MineMap[Max_row][Max_col], 
					int row, int col) {
	int count = 0;
	if (row - 1 >= 0 && col - 1 >= 0 
		&& row-1<Max_row && col-1<Max_col && 
		MineMap[row - 1][col - 1] == '1') {
		++count;
	}
	if (row - 1 >= 0 && col >= 0
		&& row - 1<Max_row && col <Max_col &&
		MineMap[row - 1][col] == '1') {
		++count;
	}
	if (row - 1 >= 0 && col + 1 >= 0
		&& row - 1<Max_row && col + 1 <Max_col &&
		MineMap[row - 1][col + 1] == '1') {
		++count;
	}
	if (row >= 0 && col - 1 >= 0
		&& row <Max_row && col - 1 <Max_col &&
		MineMap[row][col - 1] == '1') {
		++count;
	}
	if (row >= 0 && col + 1 >= 0
		&& row <Max_row && col + 1 <Max_col &&
		MineMap[row][col + 1] == '1') {
		++count;
	}
	if (row + 1 >= 0 && col -1 >= 0
		&& row + 1<Max_row && col -1 <Max_col &&
		MineMap[row + 1][col - 1] == '1') {
		++count;
	}
	if (row + 1 >= 0 && col >= 0
		&& row + 1<Max_row && col <Max_col &&
		MineMap[row + 1][col] == '1') {
		++count;
	}
	if (row + 1 >= 0 && col + 1 >= 0
		&& row + 1<Max_row && col + 1 <Max_col &&
		MineMap[row + 1][col + 1] == '1') {
		++count;
	}
	//ShowMap[row][col] = '0'+count;
	//if (count == 0) {
	//	ShowMap[row][col] = ' ';
	//	//int flag =0;
	//	if (col != 0) {
	//		//flag = 1;
	//		UpdateShowMap(ShowMap, MineMap, row, col - 1);
	//	}	
	//	/*count = 0;
	//	if (count == 0&&flag!=1) {
	//		ShowMap[row][col] = ' ';
	//		if (col != Max_col-1) {
	//			UpdateShowMap(ShowMap, MineMap, row, col+1);
	//		}
	//	}
	//	count = 1;*/
	//}
	return count;
}
//展开地图
void OpenMap(char ShowMap[Max_row][Max_col],char MineMap[Max_row][Max_col]
	         ,int row,int col) {
	int row_t = row;
	int col_t = col;
	while (row > 0 && col > 0) {
		if (MineMap[row_t - 1][col_t - 1] == '0' && row_t > 0 && col_t > 0) {
			ShowMap[row_t - 1][col_t - 1] = UpdateShowMap(ShowMap, MineMap, row_t - 1, col_t - 1) + '0';
			if (ShowMap[row_t - 1][col_t - 1] == '0') {
				--row_t;
				--col_t;
				continue;
			}
		}
		break;
	}

	 row_t = row;
	 col_t = col;
	 while (row > 0) {
		 if (MineMap[row_t - 1][col_t] == '0' && row_t > 0) {
			 ShowMap[row_t - 1][col_t] = UpdateShowMap(ShowMap, MineMap, row_t - 1, col_t) + '0';
			 if (ShowMap[row_t - 1][col_t] == '0') {
				 --row_t;
				 continue;
			 }
		 }
		 break;
	 }

	 row_t = row;
	 col_t = col;
	 while (row > 0 && col < Max_col - 1) {
		 if (MineMap[row_t - 1][col_t + 1] == '0' && row_t > 0 && col_t < Max_col - 1) {
			 ShowMap[row_t - 1][col_t + 1] = UpdateShowMap(ShowMap, MineMap, row_t - 1, col_t + 1) + '0';
			 if (ShowMap[row_t - 1][col_t + 1] == '0') {
				 --row_t;
				 ++col_t;
				 continue;
			 }
		 }
		 break;
	 }

	 row_t = row;
	 col_t = col;
	 while (col > 0) {
		 if (MineMap[row_t][col_t - 1] == '0' && col_t > 0) {
			 ShowMap[row_t][col_t - 1] = UpdateShowMap(ShowMap, MineMap, row_t, col_t - 1) + '0';
			 if (ShowMap[row_t][col_t - 1] == '0') {
				 --col_t;
				 continue;
			 }
		 }
		 break;
	 }

	 row_t = row;
	 col_t = col;
	 while (col < Max_col - 1) {
		 if (MineMap[row_t][col_t + 1] == '0' && col_t < Max_col - 1) {
			 ShowMap[row_t][col_t + 1] = UpdateShowMap(ShowMap, MineMap, row_t, col_t + 1) + '0';
			 if (ShowMap[row_t][col_t + 1] == '0') {
				 ++col_t;
				 continue;
			 }
		 }
		 break;
	 }

	 row_t = row;
	 col_t = col;
	 while (row < Max_row - 1 && col > 0) {
		 if (MineMap[row_t + 1][col_t - 1] == '0' && row_t < Max_row - 1 && col_t > 0) {
			 ShowMap[row_t + 1][col_t - 1] = UpdateShowMap(ShowMap, MineMap, row_t + 1, col_t - 1) + '0';
			 if (ShowMap[row_t + 1][col_t - 1] == '0') {
				 ++row_t;
				 --col_t;
				 continue;
			 }
		 }
		 break;
	 }

	 row_t = row;
	 col_t = col;
	 while (row < Max_row - 1) {
		 if (MineMap[row_t + 1][col_t] == '0' && row_t < Max_row - 1) {
			 ShowMap[row_t + 1][col_t] = UpdateShowMap(ShowMap, MineMap, row_t + 1, col_t) + '0';
			 if (ShowMap[row_t + 1][col_t] == '0') {
				 ++row_t;
				 continue;
			 }
		 }
		 break;
	 }

	 row_t = row;
	 col_t = col;
	 while (row < Max_row - 1 && col < Max_col - 1) {
		 if (MineMap[row_t + 1][col_t + 1] == '0' && row_t < Max_row - 1 && col_t < Max_col - 1) {
			 ShowMap[row_t + 1][col_t + 1] = UpdateShowMap(ShowMap, MineMap, row_t + 1, col_t + 1) + '0';
			 if (ShowMap[row_t + 1][col_t + 1] == '0') {
				 ++row_t;
				 ++col_t;
				 continue;
			 }
		 }
		 break;
	 }
}
void Game() {
	char ShowMap[Max_row][Max_col];
	char MineMap[Max_row][Max_col];
	//1.初始化
	Init(ShowMap, MineMap);
	while (1) {
		system("cls");
		//2.打印地图
		for (int row = 0; row < Max_row; ++row) {
			for (int col = 0; col < Max_col; ++col) {
				if (ShowMap[row][col] == '0') {
					ShowMap[row][col] = ' ';
				}
			}
		}
		PrintMap(ShowMap);
		//调试！TODO
		printf("\n");
		PrintMap(MineMap);
		int row = 0;
		int col = 0;
		while (1) {
			//3.输入坐标
			printf("请输入一个坐标");
			scanf("%d %d", &row, &col);
			if (row >= Max_row || row < 0 || col >= Max_col || col < 0) {
				printf("您的输入有误,请重新输入\n");
				continue;
			}
			if (ShowMap[row][col] != 'x') {
				printf("此位置已被翻开,请重新输入\n");
				continue;
			}
			break;
		}
		//4.判断胜负
		if (MineMap[row][col] == '1') {
			printf("您输了\n");
			PrintMap(MineMap);
			break;
		}
		int blank_count_not_show = 0;
		for (int i = 0; i < Max_row; ++i) {
			for (int j = 0; j < Max_col; ++j) {
				if (ShowMap[i][j] == 'x') {
					++blank_count_not_show;
				}
			}
		}
		if (blank_count_not_show == Mine_count + 1) {
			printf("您赢了\n");
			PrintMap(MineMap);
			break;
		}
		//5.判断周围雷的个数
		ShowMap[row][col]= UpdateShowMap(ShowMap,MineMap, row, col) + '0';
		if (ShowMap[row][col] == '0') {
			OpenMap(ShowMap, MineMap, row, col);
		}
		
	}

}
int Menu() {
	printf("---------------------\n");
	printf("欢迎来到扫雷！\n");
	printf("1.开始游戏\n");
	printf("0.结束游戏\n");
	printf("---------------------\n");
	printf("请输入您的选择\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;

}


int main() {
	while (1) {
		int choice = Menu();
		if (choice == 1) {
			printf("开始游戏\n");
			Game();
		}
		else if (choice == 0) {
			printf("下次再见\n");
		}
		else {
			printf("您的输入有误\n");
		}
	}
	system("pause");
	return 0;
}