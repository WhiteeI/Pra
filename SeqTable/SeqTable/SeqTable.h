#pragma once

typedef int DateType;
typedef struct SeqList {
	DateType* array;
	int capacity;//顺序表的总大小
	int size;//顺序表的有效元素个数
}SeqList,*PSeq;
void SeqListInit(PSeq ps,int capacity); //初始化
void SeqListPushBack(PSeq ps,DateType date); //尾插
void SeqListPushFront(PSeq ps, DateType date); //头插
void SeqListPopFront(PSeq ps);//头删
void SeqListPopBack(PSeq ps);//尾删
void SeqListInsert(PSeq ps,int pos, DateType date);//在pos位置插入元素
void SeqListErase(PSeq ps, int pos);//删除pos位置元素
int SeqListFind(PSeq ps, DateType date);//查找值为date的元素，找到返回下标，否则返回-1
int SeqListEmpty(PSeq ps);//判断顺序表是否为空，如果空返回非0值，空返回0
int SeqListSize(PSeq ps);//返回顺序表中有效元素的个数
int SeqListCapacity(PSeq ps);//返回顺序表的容量大小
void SeqListClear(PSeq ps);//将顺序表中的元素清空
void SeqListRemove(PSeq ps,DateType date);//删除顺序表中第一个值为date的元素
void SeqListDestory(PSeq ps);//销毁顺序表
void CheckCapacity(PSeq ps);//扩容顺序表
void test1();