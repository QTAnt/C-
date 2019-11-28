#pragma once
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef STDataType ;
struct Stack{
	STDataType* _array;
	size_t _top;
	size_t _capacity;
};

typedef struct Stack Stack;

void StackInit(Stack* ps);
void StackDestroy(Stack* ps);
void StackPush(Stack* ps, STDataType x);
void StackPop(Stack* ps);
STDataType StackTop(Stack* ps);
size_t StackSize(Stack* ps);
bool StackEmpty(Stack* ps);


