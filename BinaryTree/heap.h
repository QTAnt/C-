#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
//typedef int BTDataType;
//
//typedef struct BinaryTreeNode
//{
//	struct BinaryTreeNode* _left;
//	struct BinaryTreeNode* _right;
//	BTDataType* _data;
//}BinaryTreeNode;

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* _array;
	size_t _size;
	size_t _capacity;
}Heap;

void HeapInit(Heap* hp, HPDataType* a, size_t n);
void HeapDestroy(Heap* hp);
void HeapPush(Heap* hp, HPDataType x);
void HeapPop(Heap* hp);
HPDataType HeapTop(Heap* hp);
size_t HeapSize(Heap* hp);
size_t HeapEmpty(Heap* hp);

void HeapTest();

