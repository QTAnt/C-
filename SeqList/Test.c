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

	for (size_t i = 0; i < SeqListSize(&s1); ++i)   //遍历
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


	//for (size_t i = 0; i < SeqListSize(&s2); ++i)   //遍历
	//{
	//	printf("%d ", SeqListAt(&s2, i));
	//}
	//printf("\n");

	//SeqListErase(&s2, 1);
	//SeqListErase(&s2, 2);
	//for (size_t i = 0; i < SeqListSize(&s2); ++i)   //遍历
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

	for (size_t i = 0; i < SeqListSize(&s3); ++i)   //遍历
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
	
//这个TestSeqlist3() 为啥一直包LNK2019的错误？？？？？？？？？？？？？？？？？？
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
//	for (size_t i = 0; i < SeqListSize(&s3); ++i)   //遍历
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

//内存归还：
//1、归还的时候，内存要完整(体现在内存的大小，起始位置)
//2、释放时出问题（free出问题）：
//	<1>、通常是因为越界、释放是位置不对等问题导致的
//	<2>、同一块内存释放两次：同一块内存不能释放两次(可能因为第一次释放之后，内存已经归还给操作系统，同时又被分配出去了，处于一个被占用的状态，此时如果再次释放的话会把别人正在使用的是放掉，不允许有这样的操作)

//越界:1、访问越界2、空间开小了

//思考：1 2 2 3 3 4 4 4 4 5 ——  如何去重？？（有序的前提下）
//<1>时间复杂度为O(N^2) ：从第一个位置往后依次找有没有相同的，有的话就删除，然后整体往前挪一个，没有的话就继续继续往下找
//<2>时间复杂度为O(N)：以空间换时间，开一个第三方数组（应用三个指针）
//<3>时间复杂度为O(N)、空间复杂度为O(1)：原数组覆盖——>应用三个指针（思路同第二种，但是指针不指向新数组，指针指向同一顺序表）


//1 3 4 3 5 3 6 7 3  ——  删除所有的3
//<1>时间复杂度为O(N^2) ：从第一个位置往后依次找有没有相同的，有的话就删除，然后整体往前挪一个，没有的话就继续继续往下找
//<2>时间复杂度为O(N)：以空间换时间，开一个第三方数组（应用一个指针），从头往后，依次判断，不是3的话，挪到数组里面，是3，则忽略，继续往后加加，直至结束
//<3>时间复杂度为O(N)、空间复杂度为O(1)：原数组覆盖——>应用两个指针（思路同第二种）

//无法解析的外部符号 _TestSeqList3，该符号在函数 _main 中被引用
//在添加头文件处添加预处理指令, #pragma comment(lib, “xxx.lib”), xxx代表lib所在路径及文件名，添加后，程序调用成功，如下图所示，