#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include "SeqTable.h"
//��ʼ��
void SeqListInit(PSeq ps, int capacity) {
	if (ps == NULL) {
		return;
	}
	ps->array = (DateType*)malloc(capacity*sizeof(DateType));
	ps->size = 0;
	ps->capacity = capacity;
}

//β��
void SeqListPushBack(PSeq ps, DateType date) {
	if (ps == NULL) {
		return;
	}
	ps->array[ps->size] = date;
	++ps->size;
}

//ͷ��
void SeqListPushFront(PSeq ps, DateType date) {
	if (ps == NULL) {
		return;
	}
	for (int i = ps->size; i > 0; --i) {
		ps->array[i] = ps->array[i - 1];
	}
	ps->array[0] = date;
	++ps->size;
}

//ͷɾ
void SeqListPopFront(PSeq ps) {
	if (ps == NULL) {
		return;
	}
	if (ps->size == 0) {
		return;
	}
	for (int i = 0; i < ps->size - 1; ++i) {
		ps->array[i] = ps->array[i + 1];
	}
	--ps->size;
}

//βɾ
void SeqListPopBack(PSeq ps) {
	if (ps == NULL || ps->size == 0) {
		return;
	}
	--ps->size;
}

//��posλ�ò���Ԫ��
void SeqListInsert(PSeq ps, int pos, DateType date) {
	if (ps == NULL || pos < 0 || pos > ps->size) {
		return;
	}
	for (int i = ps->size - 1; i >= pos; --i) {
		ps->array[i + 1] = ps->array[i];
	}
	ps->array[pos] = date;
	++ps->size;
}

//ɾ��posλ��Ԫ��
void SeqListErase(PSeq ps, int pos) {
	if (ps == NULL || pos < 0 || pos >= ps->size) {
		return;
	}
	for (int i = pos; i < ps->size - 1; ++i) {
		ps->array[i] = ps->array[i + 1];
	}
	--ps->size;
}

//����ֵΪdate��ֵ���ҵ������±꣬���򷵻�-1
int SeqListFind(PSeq ps, DateType date) {
	for (int i = 0; i < ps->size; ++i) {
		if (ps->array[i] == date) {
			return i;
		}
	}
	return -1;
}

//�ж�˳����Ƿ�Ϊ�գ����Ϊ�շ���0�����򷵻ط�0
int SeqListEmpty(PSeq ps) {
	assert(ps);
	if (ps->size == 0) {
		return 0;
	}
	else {
		return 1;
	}
}

//����˳������ЧԪ�ظ���
int SeqListSize(PSeq ps) {
	assert(ps);
	return  ps->size;
}

//����˳����������С
int SeqListCapacity(PSeq ps) {
	assert(ps);
	return ps->capacity;
}

//��˳����е�Ԫ�����
void SeqListClear(PSeq ps) {
	assert(ps);
	ps->size = 0;
}

//ɾ��˳����е�һ��ֵΪdate��Ԫ��
void SeqListRemove(PSeq ps, DateType date) {
	assert(ps);
	for (int i = 0; i < ps->size; ++i) {
		if (ps->array[i] == date) {
			SeqListErase(ps, i); //�˴������ټ�size����Ϊ�������Ѿ�����size��
			return;
		}
	}
}

//����˳���
void SeqListDestory(PSeq ps) {
	free(ps);
	ps = NULL;
}

//����˳���
void CheckCapacity(PSeq ps) {
	assert(ps);
	ps->array = (DateType*)realloc(ps, ps->capacity * 2);
}





//����
void test1() {
	SeqList Seq;
	SeqListInit(&Seq, 10);
	SeqListPushBack(&Seq, 1);
	SeqListPushBack(&Seq, 2);
	SeqListPushBack(&Seq, 3);
	SeqListPushBack(&Seq, 4);
	SeqListPushFront(&Seq, 0);
	SeqListPopFront(&Seq);
	SeqListPopBack(&Seq);
	SeqListInsert(&Seq, 3, 4);
	SeqListErase(&Seq, 3);
	int empty1 = SeqListEmpty(&Seq);
	printf("�пգ�%d\n", empty1);
	//SeqListClear(&Seq);
	int empty2 = SeqListEmpty(&Seq);
	printf("�пգ�%d\n", empty2);
	SeqListRemove(&Seq, 3);

	int size = SeqListSize(&Seq);
	printf("��ЧԪ�أ�%d\n", size);
	printf("---------------\n");
	for (int i = 0; i < Seq.size; ++i) {
		printf("%d\n", Seq.array[i]);
	}
}
