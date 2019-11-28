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

//��������
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);

	//���ջ��������������ʾ�Ѿ�����
	if (ps->_top == ps->_capacity)  
	{
		//2������
		size_t newcapacity = ps->_capacity == 0 ? 2 : ps->_capacity * 2;
		ps->_array = realloc(ps->_array, newcapacity*sizeof(STDataType));//���realloc�ĵ�һ������Ϊ�գ��൱��malloc��������㹻�Ŀռ�realloc��ֱ�����ݣ�Ȼ�󿽱����������ͷ�֮ǰ�Ŀռ�
		ps->_capacity = newcapacity;
	}
	ps->_array[ps->_top] = x;
	ps->_top++;
}

//ɾ������
void StackPop(Stack* ps)
{
	assert(ps && ps->_top > 0);

	ps->_top--;
	//��top����--������з��ŵĻ����Ϊ--������޷��Ż��Ϊ���ε����ֵ(ȫ1)
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