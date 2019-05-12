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
void SListInit(PSList s);//链表初始化
void SListPushBack(PSList s, DateType date);//尾插
void SListPushFront(PSList s, DateType date);//头插
void SListPopBack(PSList s);//尾删
void SListPopFront(PSList s);//头删
void SListInsert(PNode pos, DateType date);//在pos位置后插入值为date的元素
void SListErase(PSList s, PNode pos);//删除pos位置的元素
PNode SListFind(PSList s, DateType date);//查找值为date的节点，找到返回地址，否则返回NULL
int SListSize(PSList s);//获取链表中有效节点的个数
int SListEmpty(PSList s);//判空，空返回0，非空返回非0
void SListClear(PSList s);//清空链表
void SListDestory(PSList s);//销毁链表
void test1();
