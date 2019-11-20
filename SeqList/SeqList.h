# pragma once		//��ֹ��������Σ����չ��
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
////��̬˳���(����������)
//#define N 100
//typedef int DataType;
//
//struct SeqList
//{
//	DataType _array[N];
//	size_t _size;
//	size_t _capacity;
//};


typedef int DataType;
typedef struct SeqList
{
	DataType* _array;
	size_t _size;
	size_t _capacity;
}SeqList;

void SeqListInit(SeqList* ps);
void SeqListDestory(SeqList* ps);
void SeqListPushBack(SeqList* ps, DataType x);
void SeqListPushFront(SeqList* ps, DataType x);
void SeqListPopBack(SeqList* ps, DataType x);
void SeqListPopFront(SeqList* ps, DataType x);
void SeqListInsert(SeqList* ps, size_t pos, DataType x);   //O(N),��������
void SeqListErase(SeqList* ps, size_t pos);	   //O(N),��������
size_t SeqListSize(SeqList* ps);
size_t SeqListFind(SeqList* ps);
DataType SeqListAt(SeqList* ps, size_t pos);  //posλ�õ�ֵ

void SeqListBubbleSort(SeqList* ps);
int SeqListBinaryFind(SeqList* ps, DataType x);
void SeqListRemoveAll(SeqList* ps, DataType x);
