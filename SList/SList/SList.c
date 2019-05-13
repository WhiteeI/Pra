#include <stdio.h>
#include <stdlib.h>
#include "SList.h"
#include <assert.h>
#include <malloc.h>
PNode SListBuyNode(DateType date) {
	PNode node = (PNode)malloc(sizeof(SListNode));
	if (node == NULL) {
		assert(0);
		return NULL;
	}
	node->date = date;
	node->pNext = NULL;
	return node;
}


//�����ʼ��
void SListInit(PSList s) {
	assert(s);
	s->head = NULL;
}
//β��
void SListPushBack(PSList s, DateType date) {
	assert(s);
	PNode newNode = SListBuyNode(date);
	if (s->head == NULL) {
		s->head = newNode;
	}
	else {
		PNode PCur = s->head;
		while (PCur->pNext) {
			PCur = PCur->pNext;
		}
		PCur->pNext = newNode;
	}
}

//ͷ��
void SListPushFront(PSList s, DateType date) {
	assert(s);
	PNode newNode = SListBuyNode(date);
	newNode->pNext = s->head;
	s->head = newNode;
}


//βɾ
void SListPopBack(PSList s) {
	assert(s);
	if (s->head == NULL) {
		return;
	}
	PNode PCur = s->head;
	PNode PPre = NULL;
	while (PCur->pNext) {
		PPre = PCur;
		PCur = PCur->pNext;
	}
	PPre->pNext = NULL;
	free(PCur);
}

//ͷɾ
void SListPopFront(PSList s) {
	assert(s);
	if (s->head == NULL) {
		return;
	}
	PNode PCur = s->head;
	s->head = s->head->pNext;
	free(PCur);
}

//posλ�ú����ֵΪdate��Ԫ��
void SListInsert(PNode pos, DateType date) {
	assert(pos);
	PNode newNode = SListBuyNode(date);
	newNode->pNext = pos->pNext;
	pos->pNext = newNode;
}

//ɾ��posλ�õ�Ԫ��
void SListErase(PSList s, PNode pos) {
	assert(s);
	assert(pos);
	PNode PCur = s->head;
	PNode PPre = NULL;
	while (PCur) {
		if (PCur != pos) {
			PPre = PCur;
			PCur = PCur->pNext;
		}
		else {
			break;
		}
	}
	if (PPre != NULL) {
		PPre->pNext = pos->pNext;
	}
	else {
		s->head = pos->pNext;
	}
	free(pos);
}

//����ֵΪdate�Ľڵ㣬�ҵ����ص�ַ�����򷵻�NULL
PNode SListFind(PSList s, DateType date) {
	assert(s);
	if (s->head == NULL) {
		return NULL;
	}
	PNode PCur = s->head;
	while (PCur) {
		if (PCur->date == date) {
			return PCur;
		}
		else {
			PCur = PCur->pNext;
		}
	}
	return NULL;
}

//��ȡ��������Ч�ڵ�ĸ���
int SListSize(PSList s) {
	assert(s);
	int size = 0;
	PNode PCur = s->head;
	while (PCur) {
		++size;
		PCur = PCur->pNext;
	}
	return size;
}

//�пգ��շ���0���ǿշ��ط�0
int SListEmpty(PSList s) {
	assert(s);
	if (s->head == NULL) {
		return 0;
	}
	else {
		return 1;
	}
}

//�������
void SListClear(PSList s) {
	assert(s);
	PNode PCur = s->head;
	while (PCur) {
		PNode p = PCur;
		PCur = PCur->pNext;
		free(p);
	}
	s->head = NULL;
}

//��������
void SListDestory(PSList s) {
	assert(s);
	PNode PCur = s->head;
	while (PCur) {
		free(PCur);
		PCur = PCur->pNext;
	}
}







void test1() {
	SList s;
	SListInit(&s);
	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushBack(&s, 4);
	SListPushFront(&s, 0);
	SListPopBack(&s);
	SListPopFront(&s);
	SListInsert(SListFind(&s, 1), 3);
	SListErase(&s, SListFind(&s, 3));
	SListClear(&s);
	SListDestory(&s);
	int size = SListSize(&s);
	printf("size:%d\n", size);
	int empty = SListEmpty(&s);
	printf("empty:%d\n", empty);
	PNode PCur = s.head;
	while (PCur) {
		printf("%d\n", PCur->date);
		PCur = PCur->pNext;
	}
}