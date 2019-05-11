#pragma once

typedef int DateType;
typedef struct SeqList {
	DateType* array;
	int capacity;//˳�����ܴ�С
	int size;//˳������ЧԪ�ظ���
}SeqList,*PSeq;
void SeqListInit(PSeq ps,int capacity); //��ʼ��
void SeqListPushBack(PSeq ps,DateType date); //β��
void SeqListPushFront(PSeq ps, DateType date); //ͷ��
void SeqListPopFront(PSeq ps);//ͷɾ
void SeqListPopBack(PSeq ps);//βɾ
void SeqListInsert(PSeq ps,int pos, DateType date);//��posλ�ò���Ԫ��
void SeqListErase(PSeq ps, int pos);//ɾ��posλ��Ԫ��
int SeqListFind(PSeq ps, DateType date);//����ֵΪdate��Ԫ�أ��ҵ������±꣬���򷵻�-1
int SeqListEmpty(PSeq ps);//�ж�˳����Ƿ�Ϊ�գ�����շ��ط�0ֵ���շ���0
int SeqListSize(PSeq ps);//����˳�������ЧԪ�صĸ���
int SeqListCapacity(PSeq ps);//����˳����������С
void SeqListClear(PSeq ps);//��˳����е�Ԫ�����
void SeqListRemove(PSeq ps,DateType date);//ɾ��˳����е�һ��ֵΪdate��Ԫ��
void SeqListDestory(PSeq ps);//����˳���
void CheckCapacity(PSeq ps);//����˳���
void test1();