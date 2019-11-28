#include "Stack.h"

void StackInit(Stack* ps)
{
	assert(ps);

	ps->_array = NULL;
	ps->_top = 0;
	ps->_capacity = 0;
}

void StackDestroy(Stack* ps)
{
	assert(ps);

	if (ps->_array != NULL)
	{
		free(ps->_array);
		ps->_array = NULL;
		ps->_top = ps->_capacity = 0;
	}
}

//插入数据
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);

	//如果栈顶等于容量，表示已经满了
	if (ps->_top == ps->_capacity)  
	{
		//2倍增容
		size_t newcapacity = ps->_capacity == 0 ? 2 : ps->_capacity * 2;
		ps->_array = realloc(ps->_array, newcapacity*sizeof(STDataType));//如果realloc的第一个参数为空，相当于malloc；如果有足够的空间realloc会直接扩容，然后拷贝下来，再释放之前的空间
		ps->_capacity = newcapacity;
	}
	ps->_array[ps->_top] = x;
	ps->_top++;
}

//删除数据
void StackPop(Stack* ps)
{
	assert(ps && ps->_top > 0);

	ps->_top--;
	//对top进行--，如果有符号的话会变为--，如果无符号会成为整形的最大值(全1)
}


STDataType StackTop(Stack* ps)
{
	assert(ps && ps->_top > 0);

	return ps->_array[ps->_top - 1];
}

size_t StackSize(Stack* ps)
{
	assert(ps);

	return ps->_top;
}


bool StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->_top == 0;
}

void TestStack()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);

	while (!StackEmpty(&s))
	{
		printf("%d", StackTop(&s));
		StackPop(&s);
	}

	StackDestroy(&s);
}

int main()
{
	TestStack();

	system("pause");
	return 0;
}