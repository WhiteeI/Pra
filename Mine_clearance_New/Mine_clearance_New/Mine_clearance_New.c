#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#define Max_row 9
#define Max_col 9
#define Mine_count 10
//��ʼ��,1��ʾ��,x��ʾδ����
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
//��ӡ��ͼ
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
//�ж���Χ�׵�����
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
//չ����ͼ
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
	//1.��ʼ��
	Init(ShowMap, MineMap);
	while (1) {
		system("cls");
		//2.��ӡ��ͼ
		for (int row = 0; row < Max_row; ++row) {
			for (int col = 0; col < Max_col; ++col) {
				if (ShowMap[row][col] == '0') {
					ShowMap[row][col] = ' ';
				}
			}
		}
		PrintMap(ShowMap);
		//���ԣ�TODO
		printf("\n");
		PrintMap(MineMap);
		int row = 0;
		int col = 0;
		while (1) {
			//3.��������
			printf("������һ������");
			scanf("%d %d", &row, &col);
			if (row >= Max_row || row < 0 || col >= Max_col || col < 0) {
				printf("������������,����������\n");
				continue;
			}
			if (ShowMap[row][col] != 'x') {
				printf("��λ���ѱ�����,����������\n");
				continue;
			}
			break;
		}
		//4.�ж�ʤ��
		if (MineMap[row][col] == '1') {
			printf("������\n");
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
			printf("��Ӯ��\n");
			PrintMap(MineMap);
			break;
		}
		//5.�ж���Χ�׵ĸ���
		ShowMap[row][col]= UpdateShowMap(ShowMap,MineMap, row, col) + '0';
		if (ShowMap[row][col] == '0') {
			OpenMap(ShowMap, MineMap, row, col);
		}
		
	}

}
int Menu() {
	printf("---------------------\n");
	printf("��ӭ����ɨ�ף�\n");
	printf("1.��ʼ��Ϸ\n");
	printf("0.������Ϸ\n");
	printf("---------------------\n");
	printf("����������ѡ��\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;

}


int main() {
	while (1) {
		int choice = Menu();
		if (choice == 1) {
			printf("��ʼ��Ϸ\n");
			Game();
		}
		else if (choice == 0) {
			printf("�´��ټ�\n");
		}
		else {
			printf("������������\n");
		}
	}
	system("pause");
	return 0;
}