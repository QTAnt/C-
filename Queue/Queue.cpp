#include "Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);

	pq->_front = pq->_tail = NULL;
}

void QueueDestory(Queue* pq)
{
	QueueNode* cur = pq->_front;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	pq->_front = pq->_tail = NULL;
}

QueueNode* BuyQueueNode(QUDataType x)
{
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->_data = x;
	node->_next = NULL;

	return node;
}

void QueuePush(Queue* pq, QUDataType x)
{
	assert(pq);

	QueueNode* newnode = BuyQueueNode(x);
	if (pq->_tail == NULL)
	{
		pq->_front = pq->_tail = newnode;
	}
	else
	{
		pq->_tail->_next = newnode;
		pq->_tail = newnode;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq && pq->_front != NULL);
	
	QueueNode* next = pq->_front->next;
	free(pq->_front);
	pq->_front = next;

	if (pq->_front == NULL)
	{
		pq->_tail == NULL;  //防止tail野指针，要考虑到头、尾的特殊情况
	}
}

QUDataType QueueFront(Queue* pq)
{
	assert(pq && pq->_front != NULL);

	return pq->_front->_data;
}

QUDataType QueueBack(Queue* pq)
{
	assert(pq && pq->_tail != NULL);

	return pq->_tail->_data;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->_front == NULL;
}

int QueueSize(Queue* pq)
{
	assert(pq);

	QueueNode* cur = pq->_front;
	size_t size = 0;
	while(cur)
	{
		size++;
		cur = cur->_next;
	}
	return size;
}

void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");
}

int main()
{
	TestQueue();
	system("pause");
	return 0;
}