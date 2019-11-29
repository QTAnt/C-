#pragma once
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//队列用链式结构实现
typedef QUDataType;
typedef struct QueueNode{
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode;

typedef struct Queue{
	QUDataType* _front;
	QUDataType* _tail;
}Queue;


void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
QueueNode* BuyQueueNode(QUDataType x);
void QueuePush(Queue* pq, QUDataType x);
void QueuePop(Queue* pq);
QUDataType QueueFront(Queue* pq);
QUDataType QueueBack(Queue* pq);
bool QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);
