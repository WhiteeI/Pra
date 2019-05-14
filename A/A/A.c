#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
//long long* Fibonacci(size_t n) {
//	if (n == 0) {
//		return NULL;
//	}
//	long long* fibarray = (long long*)malloc(n * 8 + 1);
//	fibarray[0] = 0;
//	fibarray[1] = 1;
//	for (size_t i = 2; i < n; ++i) {
//		fibarray[i] = fibarray[i - 1] + fibarray[i - 2];
//	}
//	return fibarray;
//}
//
//long long add(int n) {
//	int array[100];
//	array[1] = 1;
//	array[2] = 2;
//	int i = 3;
//	/*if (n == 1) {
//		return 1;
//		}
//		if (n == 2) {
//		return 2;
//		}*/
//	while (i <= n) {
//		array[i] = array[i - 1] + array[i - 2];
//		++i;
//	}
//	return array[n];
//}
//long jumpStepByFor(int n){
//	int result[] = { 0, 1, 2 };
//	if (n < 3){
//		return result[n];
//	}
//	long jumpCount1 = 1;
//	long jumpCount2 = 2;
//	long jumpCountn = 0;
//	for (int i = 3; i <= n; ++i) {
//		jumpCountn = jumpCount1 + jumpCount2;
//		jumpCount1 = jumpCount2;
//		jumpCount2 = jumpCountn;
//	}
//	return jumpCountn;
//}
//typedef struct GERMANY {
//	char Head[1024];
//	int Height;
//	char Hobby[1024];
//}GERMANY;
//char MyChoice() {
//	GERMANY Germany;
//	strcpy(Germany.Head, "Flat");
//	Germany.Height = 150;
//	strcpy(Germany.Hobby, "Risk");
//	char* array = "ABCD";
//	//A.Hot Pot
//	//B.Rice With Cooking
//	//C.Self-Help
//	//D.Old Lan
//	for (char choice = 'A'; choice <= 'D'; ++choice) {
//		if (choice == 'A' || choice == 'C') {
//			printf("All people Who choose %c is %s\n",choice, Germany.Head);
//			continue;
//		}
//		printf("Who choose %c dosen't like %s\n",choice,Germany.Hobby);
//	}
//	srand((unsigned int)time(0));
//	int mychoice=rand() % 2;
//	if (mychoice) {
//		return array[3];
//	}
//	else {
//		return array[1];
//	}
//}

typedef struct Node {
	int val;
	struct Node* next;
	struct Node* random;
}Node;
Node* BuyNode(int val) {
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->val = val;
	NewNode->next = NULL;
	NewNode->random = NULL;
	return NewNode;
}
void NodePushInsert(Node** PNode, int val) {
	Node* NewNode = BuyNode(val);
	NewNode->next = (*PNode)->next;
	(*PNode)->next = NewNode;
}
Node* copyRandomList(Node* head) {
	if (head == NULL) {
		return head;
	}
	Node* PCur = head;
	while (PCur) {
		Node* P = PCur;
		PCur = PCur->next;
		NodePushInsert(&P, P->val);
	}
	PCur = head;
	while (PCur&&PCur->next) {
		if (PCur->random == NULL) {
			PCur->next->random = PCur->random;
		}
		else {
			PCur->next->random = PCur->random->next;
		}
		PCur = PCur->next->next;
	}
	head = head->next;
	PCur = head;
	while (PCur&&PCur->next) {
		PCur->next = PCur->next->next;
		PCur = PCur->next;
	}
	PCur->next = NULL;
	return head;
}





int main() {
	Node* N1 = BuyNode(1);
	Node* N2 = BuyNode(2);
	Node* N3 = BuyNode(3);
	Node* N4 = BuyNode(4);
	N1->next = N2;
	N2->next = N3;
	N3->next = N4;
	N4->next = NULL;
	N1->random = N3;
	N2->random = N1;
	N3->random = N3;
	N4->random = NULL;
	Node* head = N1;
	Node* NewHead=copyRandomList(head);
	Node* PCur = NewHead;
	while (PCur) {
		printf("%d ", PCur->val);
		if (PCur->random == NULL) {
			printf("NULL\n");
		}
		else {
			printf("%d\n", PCur->random->val);
		}		
		PCur = PCur->next;
	}
	system("pause");
	return 0;
}
