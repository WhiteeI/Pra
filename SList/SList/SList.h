#pragma once 

typedef int DateType;
typedef struct SListNode {
	DateType date;
	struct SListNode* pNext;
}SListNode, *PNode;

typedef struct SList {
	PNode head;
}SList, *PSList;

PNode SListBuyNode(DateType date);
void SListInit(PSList s);//�����ʼ��
void SListPushBack(PSList s, DateType date);//β��
void SListPushFront(PSList s, DateType date);//ͷ��
void SListPopBack(PSList s);//βɾ
void SListPopFront(PSList s);//ͷɾ
void SListInsert(PNode pos, DateType date);//��posλ�ú����ֵΪdate��Ԫ��
void SListErase(PSList s, PNode pos);//ɾ��posλ�õ�Ԫ��
PNode SListFind(PSList s, DateType date);//����ֵΪdate�Ľڵ㣬�ҵ����ص�ַ�����򷵻�NULL
int SListSize(PSList s);//��ȡ��������Ч�ڵ�ĸ���
int SListEmpty(PSList s);//�пգ��շ���0���ǿշ��ط�0
void SListClear(PSList s);//�������
void SListDestory(PSList s);//��������
void test1();
