#pragma once
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
//��������ṹ��Ļ�����Ҫ��ָ���ָ�룬�Ƚ��鷳
//���򲻴�ͷ��ѭ��
typedef int SLTDateType;
//typedef int SListNode;

//����Ľṹ��
typedef struct SListNode{
	SLTDateType _data;
	struct SListNode* _next;
}SListNode;

//���������һ��ͷָ�루ָ������ĵ�һ���ڵ㣩
//_head��洢����������ṹ���ָ��
typedef struct SList{
	SListNode* _head;
}SList;

void SListInit(SList* plt);
void SListPushBack(SList* plt, SLTDateType x);
void SListPushFront(SList* plt, SLTDateType x);
void SListPopBack(SList* plt, SLTDateType x);
void SListPopFront(SList* plt, SLTDateType x);

void SListDestroy(SList* plt);  //���ṹ���ָ��

void TestSList1();



