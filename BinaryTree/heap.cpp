#include "heap.h"

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
////���µ����㷨��С�ѣ�
//void AdjustDown(HPDataType* a, size_t n, int root)   //root�������Ǹ��±�
//{
//	int parent = root;
//	int child = parent * 2 + 1;//Ĭ��������
//
//	while (child < n)
//	{
//		//�����Һ���С��
//		if (child+1<n && a[child+1] < a[child]) //�Һ��Ӵ��ڣ����Һ���С������
//		{
//			child++;
//		}
//		if (a[child] < a[parent])
//		{
//			HPDataType tmp = a[child]; //���������������ֵ
//			a[child] = a[parent];
//			a[parent] = tmp;
//
//			//��������֮�����������
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}

//���ϵ����㷨����ѣ�
void AdjustDown(HPDataType* a, size_t n, int root)   //root�������Ǹ��±�
{
	int parent = root;
	int child = parent * 2 + 1;//Ĭ��������

	while (child < n)
	{
		//�����Һ���С��
		if (child + 1<n && a[child + 1] > a[child]) //�Һ��Ӵ��ڣ����Һ���С������
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			//HPDataType tmp = a[child]; //���������������ֵ
			//a[child] = a[parent];
			//a[parent] = tmp;
			Swap(&a[child], &a[parent]);

			//��������֮�����������
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}


void HeapInit(Heap* hp, HPDataType* a, size_t n)
{
	assert(hp && a);
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType));
	hp->_size = hp->_capacity = n;
	memcpy(hp->_array, a, sizeof(HPDataType)*n);
	
	//���� (hp->_size - 2)����>(hp->_size-1-1)
	int last = hp->_size - 1;
	for (int i = (last - 1) / 2; i >= 0; i--)
	//for (int i = (hp->_size - 2) / 2; i >= 0; i--)
	{
		AdjustDown(hp->_array, hp->_size, i);
	}
}


void AdjustUp(HPDataType* a, size_t n, size_t child)
{
	assert(a);

	size_t parent = (child - 1) / 2;
	//while (parent >= 0)   //���ܻ�Խ��
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			/*HPDataType tmp = a[child];
			a[child] = a[parent];
			a[parent] = tmp;    */
			Swap(&a[child], &a[parent]);

			//������ɽ���֮����Ȼ��Ҫ���ϼ�����λ�����Ƚ�
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;   //����ıȸ���С
		}
	}
}

void HeapDestroy(Heap* hp)
{
	assert(hp);
	free(hp->_array);
	hp->_array = NULL;
	hp->_size = hp->_capacity = 0;
}

void HeapPush(Heap* hp, HPDataType x)
{
	assert(hp);

	//����
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity *= 2;
		hp->_array = (HPDataType*)realloc(hp->_array, hp->_capacity*sizeof(HPDataType));
		assert(hp->_array);
	}

	hp->_array[hp->_size] = x;   //��������һ��λ�ò���x
	hp->_size++;   //������һ���½�㣬size��1

	//����(���ϵ���)
	AdjustUp(hp->_array, hp->_size, hp->_size - 1);
}

void HeapPop(Heap* hp)
{
	assert(hp);

	Swap(&hp->_array[0], &hp->_array[hp->_size-1]);
	hp->_size--;

	AdjustDown(hp->_array, hp->_size, 0);
}

void HeapPrint(Heap* hp)
{
	for (size_t i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_array[i]);
	}
	printf("\n");
}

size_t HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}

//�շ���0���ǿշ���1
size_t HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->_size == 0 ? 0 : 1;
}

//�Ѷ�
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	return hp->_array[0];
}

void HeapTest()
{
	int a[] = { 7, 4, 9, 6, 2, 4, 1, 7, 5 };
	Heap hp;
	HeapInit(&hp, a, sizeof(a) / sizeof(int));
	//HeapPush(&hp, 16);
	HeapPop(&hp);
	HeapPrint(&hp);
}

int main()
{
	HeapTest();
	system("pause");
	return 0;
}
//
//strcpy��memcpy��Ҫ������3���������
//���Ƶ����ݲ�ͬ��strcpyֻ�ܸ����ַ�������memcpy���Ը����������ݣ������ַ����顢���͡��ṹ�塢��ȡ�
//���Ƶķ�����ͬ��strcpy����Ҫָ�����ȣ��������ַ���������"\0"�������memcpy���Ǹ������3�������������Ƶĳ��ȡ�
//��;��ͬ��ͨ���ڸ����ַ���ʱ��strcpy������Ҫ����������������ʱ��һ����memcpy��