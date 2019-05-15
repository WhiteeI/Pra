#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void StackInit(Stack* s) {
	s->capacity = 10;
	s->date = (DateType*)malloc(sizeof(DateType)*s->capacity);	
	s->size = 0;
}
void StackPush(Stack* s, DateType date) {
	if (s->size == s->capacity) {
		s->date = (DateType*)realloc(s->date, 2 * s->capacity);
	}
	s->date[s->size] = date;
	++s->size;
}
void StackPop(Stack* s) {
	if (s->size == 0) {
		return;
	}
	--s->size;
}
DateType StackTop(Stack* s) {
	if (s->size == 0) {
		return NULL;
	}
	return s->date[s->size - 1];
}
int StackSize(Stack* s) {
	return s->size;
}
int StackEmpty(Stack* s) {
	return s->size != 0;
}
void StackDestory(Stack* s) {
	free(s->date);
	s->capacity = 0;
	s->size = 0;
}

void test1() {
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	StackPop(&s);
	DateType top=StackTop(&s);
	printf("top:%d\n", top);
	int size = StackSize(&s);
	printf("size:%d\n", size);
	int empty = StackEmpty(&s);
	printf("empty:%d\n", empty);
	for (int i = 0; i < s.size; ++i) {
		printf("%d\n", s.date[i]);
	}
}