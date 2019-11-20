#include "SeqList.h"

void TestSeqList1()
{
	SeqList s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4); 
	SeqListPushFront(&s1, 0);
	SeqListPopFront(&s1,1);
	//SeqListPopBack(&s1,4);

	for (size_t i = 0; i < SeqListSize(&s1); ++i)   //����
	{
		printf("%d ", SeqListAt(&s1, i));
	}
	printf("\n");


	//SeqListDestroy(&s1);
}

void TestSeqList2()
{
	//SeqList s2;
	//SeqListInit(&s2);
	//SeqListPushBack(&s2, 1);
	//SeqListPushBack(&s2, 2);
	//SeqListPushBack(&s2, 3);
	//SeqListPushBack(&s2, 4);
	//SeqListInsert(&s2, 1, 11);
	//SeqListInsert(&s2, 3, 33);


	//for (size_t i = 0; i < SeqListSize(&s2); ++i)   //����
	//{
	//	printf("%d ", SeqListAt(&s2, i));
	//}
	//printf("\n");

	//SeqListErase(&s2, 1);
	//SeqListErase(&s2, 2);
	//for (size_t i = 0; i < SeqListSize(&s2); ++i)   //����
	//{
	//	printf("%d ", SeqListAt(&s2, i));
	//}
	//printf("\n");

	SeqList s3;
	SeqListInit(&s3);
	SeqListPushBack(&s3, 5);
	SeqListPushBack(&s3, 2);
	SeqListPushBack(&s3, 4);
	SeqListPushBack(&s3, 1);
	SeqListPushBack(&s3, 3);
	SeqListPushBack(&s3, 6);
	SeqListPushBack(&s3, 0);

	SeqListBubbleSort(&s3);

	for (size_t i = 0; i < SeqListSize(&s3); ++i)   //����
	{
		printf("%d ", SeqListAt(&s3, i));
	}
	printf("\n");

	printf("%d\n", SeqListBinaryFind(&s3, 0));
	printf("%d\n", SeqListBinaryFind(&s3, 1));
	printf("%d\n", SeqListBinaryFind(&s3, 2));
	printf("%d\n", SeqListBinaryFind(&s3, 3));
	printf("%d\n", SeqListBinaryFind(&s3, 4));
	printf("%d\n", SeqListBinaryFind(&s3, 5));
	printf("%d\n", SeqListBinaryFind(&s3, 6));
	printf("%d\n", SeqListBinaryFind(&s3, 7));
	printf("%d\n", SeqListBinaryFind(&s3, 8));
}
	
//���TestSeqlist3() Ϊɶһֱ��LNK2019�Ĵ��󣿣���������������������������������
//void TestSeqlist3()
//{
//	SeqList s3;
//	SeqListInit(&s3);
//	SeqListPushBack(&s3, 5);
//	SeqListPushBack(&s3, 2);
//	SeqListPushBack(&s3, 4);
//	SeqListPushBack(&s3, 1);
//	SeqListPushBack(&s3, 3);
//	SeqListPushBack(&s3, 6);
//	SeqListPushBack(&s3, 0);
//
//	SeqListBubbleSort(&s3);
//
//	for (size_t i = 0; i < SeqListSize(&s3); ++i)   //����
//	{
//		printf("%d ", SeqListAt(&s3, i));
//	}
//	printf("\n");
//}

int main()
{
	//TestSeqList1();
	TestSeqList2();
	//TestSeqList3();

	system("pause");
	return 0;
}

//�ڴ�黹��
//1���黹��ʱ���ڴ�Ҫ����(�������ڴ�Ĵ�С����ʼλ��)
//2���ͷ�ʱ�����⣨free�����⣩��
//	<1>��ͨ������ΪԽ�硢�ͷ���λ�ò��Ե����⵼�µ�
//	<2>��ͬһ���ڴ��ͷ����Σ�ͬһ���ڴ治���ͷ�����(������Ϊ��һ���ͷ�֮���ڴ��Ѿ��黹������ϵͳ��ͬʱ�ֱ������ȥ�ˣ�����һ����ռ�õ�״̬����ʱ����ٴ��ͷŵĻ���ѱ�������ʹ�õ��Ƿŵ����������������Ĳ���)

//Խ��:1������Խ��2���ռ俪С��

//˼����1 2 2 3 3 4 4 4 4 5 ����  ���ȥ�أ����������ǰ���£�
//<1>ʱ�临�Ӷ�ΪO(N^2) ���ӵ�һ��λ��������������û����ͬ�ģ��еĻ���ɾ����Ȼ��������ǰŲһ����û�еĻ��ͼ�������������
//<2>ʱ�临�Ӷ�ΪO(N)���Կռ任ʱ�䣬��һ�����������飨Ӧ������ָ�룩
//<3>ʱ�临�Ӷ�ΪO(N)���ռ临�Ӷ�ΪO(1)��ԭ���鸲�ǡ���>Ӧ������ָ�루˼·ͬ�ڶ��֣�����ָ�벻ָ�������飬ָ��ָ��ͬһ˳���


//1 3 4 3 5 3 6 7 3  ����  ɾ�����е�3
//<1>ʱ�临�Ӷ�ΪO(N^2) ���ӵ�һ��λ��������������û����ͬ�ģ��еĻ���ɾ����Ȼ��������ǰŲһ����û�еĻ��ͼ�������������
//<2>ʱ�临�Ӷ�ΪO(N)���Կռ任ʱ�䣬��һ�����������飨Ӧ��һ��ָ�룩����ͷ���������жϣ�����3�Ļ���Ų���������棬��3������ԣ���������Ӽӣ�ֱ������
//<3>ʱ�临�Ӷ�ΪO(N)���ռ临�Ӷ�ΪO(1)��ԭ���鸲�ǡ���>Ӧ������ָ�루˼·ͬ�ڶ��֣�

//�޷��������ⲿ���� _TestSeqList3���÷����ں��� _main �б�����
//�����ͷ�ļ������Ԥ����ָ��, #pragma comment(lib, ��xxx.lib��), xxx����lib����·�����ļ�������Ӻ󣬳�����óɹ�������ͼ��ʾ��