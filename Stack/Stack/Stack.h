#pragma once 

typedef int DateType;
typedef struct Stack {
	int* date;
	int capacity;
	int size;
}Stack;

void StackInit(Stack* s);
void StackPush(Stack* s, DateType date);
void StackPop(Stack* s);
DateType StackTop(Stack* s);
int StackSize(Stack* s);
int StackEmpty(Stack* s);
void StackDestory(Stack* s);
void test1();