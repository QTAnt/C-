#pragma once
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
//如果不传结构体的话，就要传指针的指针，比较麻烦
//单向不带头不循环
typedef int SLTDateType;
//typedef int SListNode;

//链表的结构体
typedef struct SListNode{
	SLTDateType _data;
	struct SListNode* _next;
}SListNode;

//单链表里给一个头指针（指向链表的第一个节点）
//_head里存储了上面链表结构体的指针
typedef struct SList{
	SListNode* _head;
}SList;

void SListInit(SList* plt);
void SListPushBack(SList* plt, SLTDateType x);
void SListPushFront(SList* plt, SLTDateType x);
void SListPopBack(SList* plt, SLTDateType x);
void SListPopFront(SList* plt, SLTDateType x);

void SListDestroy(SList* plt);  //传结构体的指针

void TestSList1();



