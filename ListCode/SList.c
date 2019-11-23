#include "SList.h"

void SListInit(SList* plt)
{
	assert(plt);

	plt->_head = NULL;
}

//β��:�ȿ���һ���µĿռ�洢��Ҫ����Ľڵ㣨newnode����Ȼ���жϴ�����Ľڵ�(plt)�Ƿ�Ϊ�գ���Ϊ��,�ҵ�һ���ڵ�_head��ֱ�Ӱ�plt->_headָ���½ڵ㼴�ɣ�����Ϊ�գ������һ���ڵ㣬����ڵ�cur��curȥ������plt�����һ���ڵ㣬û�ҵ�֮ǰ��cur���������ң�cur = cur->_next ;ֱ��cur->_next == NULLʱ���ҵ������һ���ڵ㣬�ٰ����Ľڵ�ָ���½ڵ�(newnode)����
void SListPushBack(SList* plt, SLTDateType x)
{
	assert(plt);

	//�������ڴ�ռ�,����ṹ���С
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;

	//1.Ϊ��
	if (plt->_head == NULL)
	{
		plt->_head = x;
	}
	//2.��Ϊ��
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

//ͷ��
//ע������½ڵ��ʱ�򣬲���ֱ����ͷָ���½ڵ㣬�����ô�ɵĻ�����ôͷ�ڵ���ԭ�ȴ洢�ĵ�һ���ڵ�ĵ�ַ���Ҳ����ˣ����ͷ��ʱһ��Ҫע����һ�㣡����
//�Ƚ��½ڵ��_nextָ��ԭ���ĵ�һ���ڵ�ĵ�ַ(ͷ�ڵ��ľ���ԭ���ĵ�һ���ڵ�ĵ�ַ)���ڰ�ͷ�ڵ�ָ���½ڵ㼴��
void SListPushFront(SList* plt, SLTDateType x)
{
	assert(plt);

	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;

	//�ղ��վ����
	newnode->_next = plt->_head;    //��һ���ڵ�ĵ�ַ�洢��ͷ��(plt->_head)
	plt->_head = newnode;
}

//ͷɾ
//��curָ���һ���ڵ㡢cur->_nextָ��ڶ����ڵ㣻��_headָ��ڶ����ڵ�(cur->_next)���ѵ�һ���ڵ�ɾ������
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

//βɾ
//��β��cur->_next->_next == NULL ������ֱ�ӽ����һ����Ϊ�գ������������ԭ�������ڶ����ڵ��_next����Ұָ������⣩
//�������Ϊ�գ���ûʲô��ɾ�ģ�ֱ�ӷ��ؼ��ɣ� 
//�������ֻ��һ���ڵ�,��ɾ������ڵ㼴�ɣ�Ȼ���plt->_next��Ϊ�գ���ֹҰָ�� 
//����ж���ڵ㣬����Խ���cur->_next->_next�ҵ����һ���ڵ㣬ɾ�����һ���ڵ㣬�ٰѵ����ڶ����ڵ��_next��Ϊ�գ���ֹҰָ��
void SListPopBack(SList* plt, SLTDateType x)
{
	assert(plt);

	SListNode* cur = plt->_head;
	//Ϊ�սڵ㣬û��ʲô����ɾ
	if (cur == NULL)
	{
		return;
	}
	//ֻ��һ���ڵ㣬�պ�ɾ����
	else if (cur->_next == NULL)
	{
		free(cur);
		plt->_head = NULL;
	}
	//����ڵ�
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

//���ⲽ�裺
//1���Ȼ�ͼ�������ǳ������
//2���ٻ�ͼ�������Ƿǳ���������߽�������

//C++���˫������-list/������-forward_list
//�������ͷ��ͷɾʱ�临�ӶȾ�ΪO(1),���ǳ��õģ������ϣ�����Ӧ��
//������ȱ��ƫ�࣬������Ŀ�Ƚ϶࣬�����һЩ 
//ͷ����˫����������׽���������������ڽڵ�ĺ������
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

//newnode����ָ��pos����һ��λ�ã�Ȼ��pos��ָ��newnode
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

//ɾ��Ŀ��ֵ
void SListRemove(SList* plt, SLTDateType x)
{
	assert(plt);

	SListNode* prev = NULL;
	SListNode* cur = plt->_head;
	while (cur != NULL)
	{
		if (cur->_data == x)
		{
			if (prev == NULL)	//ͷɾ(cur->_data == x)
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


