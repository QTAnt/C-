#include "heap.h"

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
////向下调整算法（小堆）
//void AdjustDown(HPDataType* a, size_t n, int root)   //root是最后的那个下标
//{
//	int parent = root;
//	int child = parent * 2 + 1;//默认是左孩子
//
//	while (child < n)
//	{
//		//找左右孩子小的
//		if (child+1<n && a[child+1] < a[child]) //右孩子存在，且右孩子小于左孩子
//		{
//			child++;
//		}
//		if (a[child] < a[parent])
//		{
//			HPDataType tmp = a[child]; //交换的是数组里的值
//			a[child] = a[parent];
//			a[parent] = tmp;
//
//			//交换完了之后继续往下找
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}

//向上调整算法（大堆）
void AdjustDown(HPDataType* a, size_t n, int root)   //root是最后的那个下标
{
	int parent = root;
	int child = parent * 2 + 1;//默认是左孩子

	while (child < n)
	{
		//找左右孩子小的
		if (child + 1<n && a[child + 1] > a[child]) //右孩子存在，且右孩子小于左孩子
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			//HPDataType tmp = a[child]; //交换的是数组里的值
			//a[child] = a[parent];
			//a[parent] = tmp;
			Swap(&a[child], &a[parent]);

			//交换完了之后继续往下找
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
	
	//建堆 (hp->_size - 2)——>(hp->_size-1-1)
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
	//while (parent >= 0)   //可能会越界
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			/*HPDataType tmp = a[child];
			a[child] = a[parent];
			a[parent] = tmp;    */
			Swap(&a[child], &a[parent]);

			//上下完成交换之后，仍然需要向上继续换位调整比较
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;   //插入的比父亲小
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

	//增容
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity *= 2;
		hp->_array = (HPDataType*)realloc(hp->_array, hp->_capacity*sizeof(HPDataType));
		assert(hp->_array);
	}

	hp->_array[hp->_size] = x;   //在最后的下一个位置插入x
	hp->_size++;   //插入了一个新结点，size＋1

	//调堆(向上调堆)
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

//空返回0，非空返回1
size_t HeapEmpty(Heap* hp)
{
	assert(hp);
	return hp->_size == 0 ? 0 : 1;
}

//堆顶
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
//strcpy和memcpy主要有以下3方面的区别。
//复制的内容不同。strcpy只能复制字符串，而memcpy可以复制任意内容，例如字符数组、整型、结构体、类等。
//复制的方法不同。strcpy不需要指定长度，它遇到字符串结束符"\0"便结束。memcpy则是根据其第3个参数决定复制的长度。
//用途不同。通常在复制字符串时用strcpy，而需要复制其他类型数据时则一般用memcpy。