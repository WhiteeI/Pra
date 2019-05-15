#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
QNode* QueueBuyNode(DataType data) {
	QNode* NewNode = (QNode*)malloc(sizeof(QNode));
	if (NewNode == NULL) {
		return NULL;
	}
	NewNode->data = data;
	NewNode->pnext = NULL;
	return NewNode;
}
void QueueInit(Queue* q) {
	q->front = NULL;
	q->back = NULL;
}
void QueuePush(Queue* q,DataType data) {
	QNode* NewNode = QueueBuyNode(data);
	if (q->front == NULL) {
		NewNode->pnext = q->back;
		q->back = NewNode;
		q->front = NewNode;
	}
	else {
		NewNode->pnext = NULL;
		q->back->pnext = NewNode;
		q->back = NewNode;
	}
}
void QueuePop(Queue* q) {
	QNode* P = q->front;
	q->front = q->front->pnext;
	free(P);
}
DataType QueueFront(Queue* q) {
	if (q->front == NULL) {
		return -1;
	}
	return q->front->data;
}
DataType QueueBack(Queue* q) {
	if (q->front == NULL) {
		return -1;
	}
	return q->back->data;
}
int QueueSize(Queue* q) {
	QNode* PCur = q->front;
	int size = 0;
	while (PCur) {
		++size;
	}
	return size;
}
int QueueEmpty(Queue* q) {
	return q->front != NULL;
}
void QueueDestroy(Queue* q) {
	QNode* PCur = q->front;
	while (PCur) {
		QNode* P = PCur;
		PCur = PCur->pnext;
		free(P);
	}
}
void test1() {
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePop(&q);
	int front = QueueFront(&q);
	printf("front:%d\n", front);
	int back = QueueBack(&q);
	printf("back:%d\n", back);
	int empty = QueueEmpty(&q);
	printf("empty:%d\n", empty);
	QNode* PCur = q.front;
	while (PCur) {
		printf("%d\n", PCur->data);
		PCur = PCur->pnext;
	}
}