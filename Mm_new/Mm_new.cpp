#include <iostream>

// C/C++�ڴ�ֲ�
//int globalVar = 1;                             //ȫ�֡��ֲ������洢�����ݶ�
//static int staticGlobalVar = 1;
//void Test()
//{
//	static int staticVar = 1;
//	int localVar = 1;
//
//	int num1[10] = { 1, 2, 3, 4 };
//	char char2[] = "abcd";
//	char* pChar3 = "abcd";
//	int* ptr1 = (int*)malloc(sizeof (int)* 4);
//	int* ptr2 = (int*)calloc(4, sizeof(int));
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int)* 4);
//	free(ptr1);
//	free(ptr3);
//}
//
////
////1. ѡ���⣺
////ѡ�� : A.ջ B.�� C.���ݶ� D.�����
////	 globalVar�����__C__ staticGlobalVar�����__C__
////	 staticVar�����__C__ localVar�����__A__
////	 num1 �����__A__
////
////	 char2�����__A__    *char2�����__A__
////	 pChar3�����__A__   *pChar3�����__D(������)__
////	 ptr1�����__A__     *ptr1�����__B__

////2. ����⣺
////sizeof(num1) = __40__;
////sizeof(char2) = __5(������'\0')__;     strlen(char2) = __4__;
////sizeof(pChar3) = __4/8��32/48ƽ̨��_;  strlen(pChar3) = __4(��'\0'����)__;
////sizeof(ptr1) = __4/8__;



//**************************************************************************
//C�����ж�̬�ڴ����ʽ   malloc/calloc/realloc��free
//
//int main()
//{
//
//	int* p1 = (int*)malloc(sizeof(int));
//	free(p1);
//
//	// 1.malloc / calloc / realloc��������ʲô��
//	int* p2 = (int*)calloc(4, sizeof (int));         //��ʼ��
//	int* p3 = (int*)realloc(p2, sizeof(int)* 1000);   //���ݣ����ݿռ�Ƚ϶�ʱ��realloc����ʵ��ԭ������
//
//	//**�ж��Ƿ����ݣ���������ַû�䣬��ʾ������
//	//int* p2 = (int*)calloc(4, sizeof (int)* 10);         //��ʼ��
//	//int* p3 = (int*)realloc(p2, sizeof(int));
//
//	std::cout << p2 << std::endl;    //00EA5C50
//	std::cout << p3 << std::endl;    //00EA5C50(ԭ������)
//
//	// ������Ҫfree(p2)�𣿲���Ҫ
//	//p3��p2�������ݣ����������������<1>ԭ������p2 = p3;<2>���¿��ռ�p2 != p3 (p2���ݽϴ�ʱ����ԭ�ڴ治������Ҫ���¿��ٿռ䣩)
//	free(p3);
//
//	system("pause");
//	return 0;
//}



//***************************************************************************
//new��delete�����Զ�������
//class Date
//{
//public:
//	/*Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(_day)
//		{}*/
//	Date(int year = 1900, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(_day)
//	{
//			std::cout << "Date(int year = 1900, int month = 1, int day = 1)" << std::endl;
//	}
//
//	~Date()
//	{
//		std::cout << "~Date()" << std::endl;
//	}
//	
//private:
//	int _year;
//	int _month;
//	int _day;
//
//};
//
//int main()
//{
//	//��������
//	int* p1 = new int;
//	int* p2 = (int*)malloc(sizeof(int*));
//
//	delete p1;
//	free(p2);
//
//	//�Զ�������
//	Date* p3 = new Date;    // ���ռ�+������Ĭ�Ϲ��캯����ɣ���ʼ��
//	Date* p4 = (Date*)malloc(sizeof(Date));  //ֻ���ռ�
//	Date* p5 = new Date(2019, 3, 3);    // ���ռ�+��ʼ��
//
//	delete p3;  //����(����)+�ͷſռ�    ~Date()
//	delete p5;  //  ~Date() 
//	free(p4);   //�ͷſռ�
//
//	Date* p6 = new Date[10];
//
//	//delete[]p6;
//	free(p6);//���ܻ����ã�����ᱨ����> ��Mm_new.exe �Ѵ�����һ���ϵ㡱
//
//	system("pause");
//	return 0;
//}



//******************************************************************************
//operator new��operator delete����
//int main()
//{
//	///int* p1 = (int*)operator new (sizeof(int));
//	//operator delete(p1);*/
//
//
//
//	//<<<<<<<<<<<<<<<<<<<<<<���󣬲��Ǻ����>>>>>>>>>>>>>>>>>>>
//	////try
//	////{
//	////	//ʧ�ܡ���>���쳣
//	////	char* p1 = (char*)operator new (0x7ffffffff);
//
//	////	//ʧ�ܡ���>����0��null��
//	////	char* p2 = (char*)malloc(0x7ffffffff);
//
//	////	std::cout << (void*)p2 << std::endl;
//	////}
//
//	//////���쳣�������⣩
//	////catch (exception e)
//	////{
//	////	std::cout << e.what() << std::endl;
//	////}
//
//	//ʧ�ܡ���>���쳣
//	char* p1 = (char*)operator new (0x7ffffffff);
//
//	//ʧ�ܡ���>����0��NULL��
//	char* p2 = (char*)malloc(0x7ffffffff);
//
//	std::cout << (void*)p2 << std::endl;
//
//
//
//	//int* p1 = new int ; operator new (malloc+�쳣)+���캯��
//	//int* p2 = (int)malloc(4);
//
//	//1���÷�������
//	//2����ʼ��������
//	//3���������ʽ������
//
//
//	system("pause");
//	return 0;
//}
//struct ListNode
//{
//	ListNode* _next;
//	ListNode* _prev;
//	int _data;
//	void* operator new(size_t n)
//	{
//		void* p = nullptr;
//		p = std::allocator<ListNode>().allocate(1);
//		std::cout << "memory pool allocate" << std::endl;
//		return p;
//	}
//	void operator delete(void* p)
//	{
//		std::allocator<ListNode>().deallocate((ListNode*)p, 1);
//		std::cout << "memory pool deallocate" << std::endl;
//	}
//};
//
//class List
//{
//public:
//	List()
//	{
//		_head = new ListNode;
//		_head->_next = _head;
//		_head->_prev = _head;
//	}
//	~List()
//	{
//		ListNode* cur = _head->_next;
//		while (cur != _head)
//		{
//			ListNode* next = cur->_next;
//			delete cur;
//			cur = next;
//		}
//		delete _head;
//		_head = nullptr;
//	}
//private:
//	ListNode* _head;
//};
//int main()
//{
//	List l;
//
//	system("pause");
//	return 0;
//}