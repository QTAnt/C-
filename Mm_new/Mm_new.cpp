#include <iostream>

// C/C++内存分布
//int globalVar = 1;                             //全局、局部变量存储在数据段
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
////1. 选择题：
////选项 : A.栈 B.堆 C.数据段 D.代码段
////	 globalVar在哪里？__C__ staticGlobalVar在哪里？__C__
////	 staticVar在哪里？__C__ localVar在哪里？__A__
////	 num1 在哪里？__A__
////
////	 char2在哪里？__A__    *char2在哪里？__A__
////	 pChar3在哪里？__A__   *pChar3在哪里？__D(常量区)__
////	 ptr1在哪里？__A__     *ptr1在哪里？__B__

////2. 填空题：
////sizeof(num1) = __40__;
////sizeof(char2) = __5(会算上'\0')__;     strlen(char2) = __4__;
////sizeof(pChar3) = __4/8（32/48平台）_;  strlen(pChar3) = __4(遇'\0'结束)__;
////sizeof(ptr1) = __4/8__;



//**************************************************************************
//C语言中动态内存管理方式   malloc/calloc/realloc和free
//
//int main()
//{
//
//	int* p1 = (int*)malloc(sizeof(int));
//	free(p1);
//
//	// 1.malloc / calloc / realloc的区别是什么？
//	int* p2 = (int*)calloc(4, sizeof (int));         //初始化
//	int* p3 = (int*)realloc(p2, sizeof(int)* 1000);   //扩容，扩容空间比较多时，realloc很难实现原地扩容
//
//	//**判断是否缩容？？？？地址没变，表示缩容了
//	//int* p2 = (int*)calloc(4, sizeof (int)* 10);         //初始化
//	//int* p3 = (int*)realloc(p2, sizeof(int));
//
//	std::cout << p2 << std::endl;    //00EA5C50
//	std::cout << p3 << std::endl;    //00EA5C50(原地扩容)
//
//	// 这里需要free(p2)吗？不需要
//	//p3对p2进行扩容，扩容有两种情况：<1>原地扩容p2 = p3;<2>重新开空间p2 != p3 (p2扩容较大时（即原内存不够，需要重新开辟空间）)
//	free(p3);
//
//	system("pause");
//	return 0;
//}



//***************************************************************************
//new和delete操作自定义类型
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
//	//内置类型
//	int* p1 = new int;
//	int* p2 = (int*)malloc(sizeof(int*));
//
//	delete p1;
//	free(p2);
//
//	//自定义类型
//	Date* p3 = new Date;    // 开空间+（调用默认构造函数完成）初始化
//	Date* p4 = (Date*)malloc(sizeof(Date));  //只开空间
//	Date* p5 = new Date(2019, 3, 3);    // 开空间+初始化
//
//	delete p3;  //析构(清理)+释放空间    ~Date()
//	delete p5;  //  ~Date() 
//	free(p4);   //释放空间
//
//	Date* p6 = new Date[10];
//
//	//delete[]p6;
//	free(p6);//不能混着用，否则会报错——> “Mm_new.exe 已触发了一个断点”
//
//	system("pause");
//	return 0;
//}



//******************************************************************************
//operator new与operator delete函数
//int main()
//{
//	///int* p1 = (int*)operator new (sizeof(int));
//	//operator delete(p1);*/
//
//
//
//	//<<<<<<<<<<<<<<<<<<<<<<有误，不是很清楚>>>>>>>>>>>>>>>>>>>
//	////try
//	////{
//	////	//失败——>抛异常
//	////	char* p1 = (char*)operator new (0x7ffffffff);
//
//	////	//失败——>返回0（null）
//	////	char* p2 = (char*)malloc(0x7ffffffff);
//
//	////	std::cout << (void*)p2 << std::endl;
//	////}
//
//	//////抛异常（有问题）
//	////catch (exception e)
//	////{
//	////	std::cout << e.what() << std::endl;
//	////}
//
//	//失败——>抛异常
//	char* p1 = (char*)operator new (0x7ffffffff);
//
//	//失败——>返回0（NULL）
//	char* p2 = (char*)malloc(0x7ffffffff);
//
//	std::cout << (void*)p2 << std::endl;
//
//
//
//	//int* p1 = new int ; operator new (malloc+异常)+构造函数
//	//int* p2 = (int)malloc(4);
//
//	//1、用法的区别
//	//2、初始化和清理
//	//3、处理错误方式的泣别
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