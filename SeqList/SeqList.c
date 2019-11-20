#include "SeqList.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//初始化
void SeqListInit(SeqList* ps)    //传结构体指针,否则会有“传值错误”
{
	assert(ps);  //断言:如果传一个空指针，会提示第几行有问题，可以控制，反之会崩溃，很难解决

	ps->_array = NULL;
	ps->_size = 0;
	ps->_capacity = 0;
}

//销毁
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

//插入
void SeqListCheckCapacity(SeqList* ps)
{
	assert(ps);

	//满了的话会增容
	if (ps->_size == ps->_capacity)
	{
		size_t newcapacity = (ps->_capacity == 0) ? 4 : ps->_capacity * 2;

		//ps->_array = realloc(ps->_array, newcapacity);  //会越界(可能因为空间开少了)
		ps->_array = realloc(ps->_array, sizeof(DataType)*newcapacity);

		//realloc的第一个参数如果为空的话，相当于malloc
		ps->_capacity = newcapacity;
	}
}

void SeqListPushBack(SeqList* ps, DataType x)
{
	//assert(ps);

	////增容
	//SeqListCheckCapacity(ps);

	//ps->_array[ps->_size] = x;
	//ps->_size++;

	SeqListInsert(ps, ps->_size, x);
}

//头插:时间复杂度为O(N)：如果要插入n个数据，则为n^2 ,一般插入情况很多，不建议使用
//将顺序表里原有的数据，从后往前依次往后挪一个位置，最终在第一个位置插入新数据即可
//记最后一个位置为end(为size)，前一个位置为end-1，把end-1挪到end
void SeqListPushFront(SeqList* ps, DataType x)
{
	//assert(ps);

	//size_t end = ps->_size;     //最后一个位置
	//while (end > 0)
	//{
	//	ps->_array[end] = ps->_array[end - 1];
	//	--end;
	//}
	//ps->_array[0] = x;   //插入新的数据
	//ps->_size++;

	SeqListInsert(ps, 0, x);
}

//尾删
void SeqListPopBack(SeqList* ps)
{
	assert(ps && ps->_size > 0);
	--ps->_size;

	//SeqListErase(ps, ps->_size - 1);    //我这个SeqListErase在SeqListPopBack里面调用为啥删不掉呢 T^T
}

//头删
//把数据从第二个(下标为1)到最后一个位置一次往前覆盖一个即可
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

//某个位置插入一个数据：pos位置插入一个x，要考虑增容的问题
//先把数据从后往前依次往后挪一位，直至挪到pos的位置，然后在pos位置插入数据
void SeqListInsert(SeqList* ps, size_t pos, DataType x)   //O(N),建议少用
{
	assert(ps && pos <= ps->_size);

	SeqListCheckCapacity(ps);

	////越界（无符号数的--时，要特别注意）
    //截断:char ch = 1:不会有任何影响，右边是整形，左边是字符，也是4个字节，前3个字节都是0，是0001，截断的话保留低位的字节赋值，高位的字节丢失，该情况毫无影响；char ch = 300:先把300的二进制数写出来(若为负数，存储它的补码；正数：源码和补码是一样的)，再把低位的一个字节赋值给ch,假设给过去是数符号位是1，说明ch是一个负数，此时通过源补码的规则最终才能确定数值到底为多少   
	//整形提升(隐式转化提升)，一般发生在比较阶段：int i = ch;  ch是一个字节；int是四个字节，提升成整形，高位补东西（此时要看高位是什么，高位是0(1)，全补0(1)）），一般发生在赋值阶段或者比较的时候(比较时通常是提升) 
	//size_t end = ps->_size - 1;
	//while (end >= pos)     //比较隐藏，pos为0的时候有问题
	//{
	//	ps->_array[end + 1] = ps->_array[end];
	//	end--;
	//}
	//ps->_array[pos] = x;
	//ps->_size++;


	//int end = ps->_size - 1;
	//while (end >= (int)pos)    //end是int型，有符号，pos是无符号；类型不一样时往表示范围大的类型提升（比如：char和int，char—>int转）//这里会先隐式的转为int型
	//{
	//	ps->_array[end + 1] = ps->_array[end];
	//	end--;
	//}

	size_t end = ps->_size;
	while (end > pos)    //end是int型，有符号，pos是无符号；类型不一样时往表示范围大是类型提升（比如：char和int，char—>int转）//这里会先隐式的转为int型
	{
		ps->_array[end] = ps->_array[end-1];
		end--;
	}
	ps->_array[pos] = x;
	ps->_size++;
}

void SeqListErase(SeqList* ps, size_t pos)	   //O(N),建议少用
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

//pos位置的值，可以用来访问数据
DataType SeqListAt(SeqList* ps, size_t pos)
{
	assert(ps);
	return ps->_array[pos];
}

//冒泡排序
void SeqListBubbleSort(SeqList* ps)
{
	assert(ps);

	size_t end = ps->_size;
	//多趟冒泡的结束条件
	while (end > 1)
	{
		int exchange = 0;
		//单趟冒泡
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
		//优化
		if (exchange = 0)
		{
			break;
		}
		--end;
	}
}

//二分查找
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
			begin = mid + 1;    //闭
		}
		else if(x < ps->_array[mid])
		{
			end = mid;			//开
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