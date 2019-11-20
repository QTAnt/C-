#include "SeqList.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//��ʼ��
void SeqListInit(SeqList* ps)    //���ṹ��ָ��,������С���ֵ����
{
	assert(ps);  //����:�����һ����ָ�룬����ʾ�ڼ��������⣬���Կ��ƣ���֮����������ѽ��

	ps->_array = NULL;
	ps->_size = 0;
	ps->_capacity = 0;
}

//����
void SeqListDestory(SeqList* ps)
{
	assert(ps);
	
	if (ps->_array)
	{
		free(ps->_array);
		ps->_array = NULL;
		ps->_size = ps->_capacity = 0;
	}
}

//����
void SeqListCheckCapacity(SeqList* ps)
{
	assert(ps);

	//���˵Ļ�������
	if (ps->_size == ps->_capacity)
	{
		size_t newcapacity = (ps->_capacity == 0) ? 4 : ps->_capacity * 2;

		//ps->_array = realloc(ps->_array, newcapacity);  //��Խ��(������Ϊ�ռ俪����)
		ps->_array = realloc(ps->_array, sizeof(DataType)*newcapacity);

		//realloc�ĵ�һ���������Ϊ�յĻ����൱��malloc
		ps->_capacity = newcapacity;
	}
}

void SeqListPushBack(SeqList* ps, DataType x)
{
	//assert(ps);

	////����
	//SeqListCheckCapacity(ps);

	//ps->_array[ps->_size] = x;
	//ps->_size++;

	SeqListInsert(ps, ps->_size, x);
}

//ͷ��:ʱ�临�Ӷ�ΪO(N)�����Ҫ����n�����ݣ���Ϊn^2 ,һ���������ܶ࣬������ʹ��
//��˳�����ԭ�е����ݣ��Ӻ���ǰ��������Ųһ��λ�ã������ڵ�һ��λ�ò��������ݼ���
//�����һ��λ��Ϊend(Ϊsize)��ǰһ��λ��Ϊend-1����end-1Ų��end
void SeqListPushFront(SeqList* ps, DataType x)
{
	//assert(ps);

	//size_t end = ps->_size;     //���һ��λ��
	//while (end > 0)
	//{
	//	ps->_array[end] = ps->_array[end - 1];
	//	--end;
	//}
	//ps->_array[0] = x;   //�����µ�����
	//ps->_size++;

	SeqListInsert(ps, 0, x);
}

//βɾ
void SeqListPopBack(SeqList* ps)
{
	assert(ps && ps->_size > 0);
	--ps->_size;

	//SeqListErase(ps, ps->_size - 1);    //�����SeqListErase��SeqListPopBack�������Ϊɶɾ������ T^T
}

//ͷɾ
//�����ݴӵڶ���(�±�Ϊ1)�����һ��λ��һ����ǰ����һ������
void SeqListPopFront(SeqList* ps)
{
	//assert(ps);

	///*size_t start = 0;
	//while (start < ps->_size-1)*/
	//size_t start = 1;
	//while (start < ps->_size)
	//{
	//	ps->_array[start - 1] = ps->_array[start];
	//	++start;
	//}
	//--ps->_size;

	SeqListErase(ps, 0);
}

//ĳ��λ�ò���һ�����ݣ�posλ�ò���һ��x��Ҫ�������ݵ�����
//�Ȱ����ݴӺ���ǰ��������Ųһλ��ֱ��Ų��pos��λ�ã�Ȼ����posλ�ò�������
void SeqListInsert(SeqList* ps, size_t pos, DataType x)   //O(N),��������
{
	assert(ps && pos <= ps->_size);

	SeqListCheckCapacity(ps);

	////Խ�磨�޷�������--ʱ��Ҫ�ر�ע�⣩
    //�ض�:char ch = 1:�������κ�Ӱ�죬�ұ������Σ�������ַ���Ҳ��4���ֽڣ�ǰ3���ֽڶ���0����0001���ضϵĻ�������λ���ֽڸ�ֵ����λ���ֽڶ�ʧ�����������Ӱ�죻char ch = 300:�Ȱ�300�Ķ�������д����(��Ϊ�������洢���Ĳ��룻������Դ��Ͳ�����һ����)���ٰѵ�λ��һ���ֽڸ�ֵ��ch,�������ȥ��������λ��1��˵��ch��һ����������ʱͨ��Դ����Ĺ������ղ���ȷ����ֵ����Ϊ����   
	//��������(��ʽת������)��һ�㷢���ڱȽϽ׶Σ�int i = ch;  ch��һ���ֽڣ�int���ĸ��ֽڣ����������Σ���λ����������ʱҪ����λ��ʲô����λ��0(1)��ȫ��0(1)������һ�㷢���ڸ�ֵ�׶λ��߱Ƚϵ�ʱ��(�Ƚ�ʱͨ��������) 
	//size_t end = ps->_size - 1;
	//while (end >= pos)     //�Ƚ����أ�posΪ0��ʱ��������
	//{
	//	ps->_array[end + 1] = ps->_array[end];
	//	end--;
	//}
	//ps->_array[pos] = x;
	//ps->_size++;


	//int end = ps->_size - 1;
	//while (end >= (int)pos)    //end��int�ͣ��з��ţ�pos���޷��ţ����Ͳ�һ��ʱ����ʾ��Χ����������������磺char��int��char��>intת��//���������ʽ��תΪint��
	//{
	//	ps->_array[end + 1] = ps->_array[end];
	//	end--;
	//}

	size_t end = ps->_size;
	while (end > pos)    //end��int�ͣ��з��ţ�pos���޷��ţ����Ͳ�һ��ʱ����ʾ��Χ�����������������磺char��int��char��>intת��//���������ʽ��תΪint��
	{
		ps->_array[end] = ps->_array[end-1];
		end--;
	}
	ps->_array[pos] = x;
	ps->_size++;
}

void SeqListErase(SeqList* ps, size_t pos)	   //O(N),��������
{
	assert(ps && pos < ps->_size);

	//size_t start = pos;
	//while (start < ps->_size-1)
	//{
	//	ps->_array[start] = ps->_array[start+1];
	//	start++;
	//}

	size_t start = pos+1;
	while (start < ps->_size)
	{
		ps->_array[start-1] = ps->_array[start];
		++start;
	}
}

size_t SeqListSize(SeqList* ps)
{
	assert(ps);
	return ps->_size;
}

size_t SeqListFind(SeqList* ps, DataType x)
{
	assert(ps);

	for (size_t i = 0; i < ps->_size; i++)
	{
		if (x = ps->_array[i])
		{
			return i;
		}
	}
	return -1;
}

//posλ�õ�ֵ������������������
DataType SeqListAt(SeqList* ps, size_t pos)
{
	assert(ps);
	return ps->_array[pos];
}

//ð������
void SeqListBubbleSort(SeqList* ps)
{
	assert(ps);

	size_t end = ps->_size;
	//����ð�ݵĽ�������
	while (end > 1)
	{
		int exchange = 0;
		//����ð��
		for (size_t i = 1; i < end; i++)
		{
			if (ps->_array[i - 1] > ps->_array[i])
			{
				DataType tmp = ps->_array[i - 1];
				ps->_array[i - 1] = ps->_array[i];
				ps->_array[i] = tmp;
				exchange = 1;
			}
		}
		//�Ż�
		if (exchange = 0)
		{
			break;
		}
		--end;
	}
}

//���ֲ���
int SeqListBinaryFind(SeqList* ps, DataType x)
{
	assert(ps);

	//[begin,end]:size_t begin = 0;size_t end = ps->_size-1;
	//[begin.end):size_t begin = 0;size_t end = ps->_size;
	size_t begin = 0;
	size_t end = ps->_size - 1;
	while (begin <= end)
	{
		size_t mid = begin + ((end - begin) >> 1);
		if (x > ps->_array[mid])
		{
			begin = mid + 1;    //��
		}
		else if(x < ps->_array[mid])
		{
			end = mid;			//��
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

void SeqListRemoveAll(SeqList* ps, DataType x)
{

}