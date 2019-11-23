#include "SList.h"

void SListInit(SList* plt)
{
	assert(plt);

	plt->_head = NULL;
}

//尾插:先开辟一个新的空间存储将要插入的节点（newnode），然后判断待插入的节点(plt)是否为空，若为空,找第一个节点_head，直接把plt->_head指向新节点即可；若不为空，找最后一个节点，引入节点cur，cur去找链表plt的最后一个节点，没找到之前，cur依次往后找，cur = cur->_next ;直至cur->_next == NULL时就找到了最后一个节点，再把最后的节点指向新节点(newnode)即可
void SListPushBack(SList* plt, SLTDateType x)
{
	assert(plt);

	//先申请内存空间,申请结构体大小
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;

	//1.为空
	if (plt->_head == NULL)
	{
		plt->_head = x;
	}
	//2.不为空
	else
	{
		SListNode* cur = plt->_head;
		while (cur->_next != NULL)
		{
			cur = cur->_next;
		}
		cur->_next = newnode;
	}
}

//头插
//注意插入新节点的时候，不能直接用头指向新节点，如果这么干的话，那么头节点里原先存储的第一个节点的地址就找不到了，因此头插时一定要注意这一点！！！
//先将新节点的_next指向原来的第一个节点的地址(头节点存的就在原来的第一个节点的地址)；在把头节点指向新节点即可
void SListPushFront(SList* plt, SLTDateType x)
{
	assert(plt);

	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;

	//空不空均如此
	newnode->_next = plt->_head;    //第一个节点的地址存储在头里(plt->_head)
	plt->_head = newnode;
}

//头删
//设cur指向第一个节点、cur->_next指向第二个节点；将_head指向第二个节点(cur->_next)，把第一个节点删除即可
void SListPopFront(SList* plt, SLTDateType x)
{
	assert(plt);

	if (plt == NULL)
	{
		return;
	}
	else
	{
		SListNode* cur = plt->_head;
		plt->_head = cur->_next;
		free(cur);
		cur = NULL;
	}
}

//尾删
//找尾：cur->_next->_next == NULL （不能直接将最后一个置为空，这样容易造成原链表倒数第二个节点的_next存在野指针的问题）
//如果链表为空，则没什么可删的，直接返回即可； 
//如果链表只有一个节点,则删除这个节点即可，然后把plt->_next置为空，防止野指针 
//如果有多个节点，则可以借助cur->_next->_next找到最后一个节点，删除最后一个节点，再把倒数第二个节点的_next置为空，防止野指针
void SListPopBack(SList* plt, SLTDateType x)
{
	assert(plt);

	SListNode* cur = plt->_head;
	//为空节点，没有什么可以删
	if (cur == NULL)
	{
		return;
	}
	//只有一个节点，刚好删除它
	else if (cur->_next == NULL)
	{
		free(cur);
		plt->_head = NULL;
	}
	//多个节点
	else
	{
		while (cur->_next->_next != NULL)
		{
			cur = cur->_next;
		}
		free(cur->_next);
		cur->_next = NULL;
	}
}

//解题步骤：
//1、先画图分析考虑常规情况
//2、再画图分析考虑非常规情况（边界条件）

//C++库里，双向链表-list/单链表-forward_list
//单链表的头插头删时间复杂度均为O(1),这是常用的，比如哈希表里的应用
//单链表缺陷偏多，出的题目比较多，陷阱多一些 
//头插用双向链表更容易解决；单链表常用于在节点的后面插入
void SListFind(SList* plt, SLTDateType x)
{
	assert(plt);
	SListNode* cur = plt->_head;
	while (cur != NULL)
	{
		if (cur->_data = x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}

//newnode得先指向pos的下一个位置，然后pos再指向newnode
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);

	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;

	newnode->_next = pos->_next;
	pos->_next = newnode;
}

void SListEraseAfter(SListNode* pos)
{
	assert(0);

	if (pos->_next == NULL)
	{
		return;
	}
	else
	{
		SListNode* next = pos->_next;
		pos->_next = next->_next;
		free(next);
		next = NULL;
	}
}

//删除目标值
void SListRemove(SList* plt, SLTDateType x)
{
	assert(plt);

	SListNode* prev = NULL;
	SListNode* cur = plt->_head;
	while (cur != NULL)
	{
		if (cur->_data == x)
		{
			if (prev == NULL)	//头删(cur->_data == x)
			{
				plt->_head = cur->_next;
			}
			prev->_next = cur->_next;
			free(cur);
			cur = NULL;
			return;
		}
		else
		{
			prev = cur;
			cur = cur->_next;
		}
	}
}

void SListPrint(SList* plt)
{
	assert(plt);

	SListNode* cur = plt->_head;
	while(cur != NULL)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}


void SListDestroy(SList* plt);

void TestSList1()
{
	SList lt;
	SListInit(&lt);
	SListPushBack(&lt, 1);
	SListPushBack(&lt, 2);
	SListPushBack(&lt, 3);
	SListPushBack(&lt, 4);

	SListPrint(&lt);
}

void TestSList2()
{
	SList lt;
	SListInit(&lt);
	SListPushBack(&lt, 1);
	SListPushBack(&lt, 2);
	SListPushBack(&lt, 3);
	SListPushBack(&lt, 4);
	SListPrint(&lt);

	SListNode* pos = SListFind(&lt, 30);
	SListInsertAfter(pos, 30);
	SListPrint(&lt);
}


