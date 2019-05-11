#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include "SeqTable.h"
//初始化
void SeqListInit(PSeq ps, int capacity) {
	if (ps == NULL) {
		return;
	}
	ps->array = (DateType*)malloc(capacity*sizeof(DateType));
	ps->size = 0;
	ps->capacity = capacity;
}

//尾插
void SeqListPushBack(PSeq ps, DateType date) {
	if (ps == NULL) {
		return;
	}
	ps->array[ps->size] = date;
	++ps->size;
}

//头插
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

//头删
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

//尾删
void SeqListPopBack(PSeq ps) {
	if (ps == NULL || ps->size == 0) {
		return;
	}
	--ps->size;
}

//在pos位置插入元素
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

//删除pos位置元素
void SeqListErase(PSeq ps, int pos) {
	if (ps == NULL || pos < 0 || pos >= ps->size) {
		return;
	}
	for (int i = pos; i < ps->size - 1; ++i) {
		ps->array[i] = ps->array[i + 1];
	}
	--ps->size;
}

//查找值为date的值，找到返回下标，否则返回-1
int SeqListFind(PSeq ps, DateType date) {
	for (int i = 0; i < ps->size; ++i) {
		if (ps->array[i] == date) {
			return i;
		}
	}
	return -1;
}

//判断顺序表是否为空，如果为空返回0，否则返回非0
int SeqListEmpty(PSeq ps) {
	assert(ps);
	if (ps->size == 0) {
		return 0;
	}
	else {
		return 1;
	}
}

//返回顺序表的有效元素个数
int SeqListSize(PSeq ps) {
	assert(ps);
	return  ps->size;
}

//返回顺序表的容量大小
int SeqListCapacity(PSeq ps) {
	assert(ps);
	return ps->capacity;
}

//将顺序表中的元素清空
void SeqListClear(PSeq ps) {
	assert(ps);
	ps->size = 0;
}

//删除顺序表中第一个值为date的元素
void SeqListRemove(PSeq ps, DateType date) {
	assert(ps);
	for (int i = 0; i < ps->size; ++i) {
		if (ps->array[i] == date) {
			SeqListErase(ps, i); //此处不用再减size，因为函数中已经减过size了
			return;
		}
	}
}

//销毁顺序表
void SeqListDestory(PSeq ps) {
	free(ps);
	ps = NULL;
}

//扩容顺序表
void CheckCapacity(PSeq ps) {
	assert(ps);
	ps->array = (DateType*)realloc(ps, ps->capacity * 2);
}





//测试
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
	printf("判空：%d\n", empty1);
	//SeqListClear(&Seq);
	int empty2 = SeqListEmpty(&Seq);
	printf("判空：%d\n", empty2);
	SeqListRemove(&Seq, 3);

	int size = SeqListSize(&Seq);
	printf("有效元素：%d\n", size);
	printf("---------------\n");
	for (int i = 0; i < Seq.size; ++i) {
		printf("%d\n", Seq.array[i]);
	}
}
