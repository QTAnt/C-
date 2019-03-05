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



//2019/3/3
//*******************************************************************************
////请设计一个类，该类只能在堆上创建对象
////
////方法一：构造函数私有化
////1. 将类的构造函数私有( C++ 98 )，拷贝构造声明成私有。防止别人调用拷贝在栈上生成对象。
////2. 提供一个静态的成员函数，在该静态成员函数中完成堆对象的创建
////
////只在栈上创建
//class HeapOnly
//{
//public:
//	static HeapOnly* GetHeapObj()
//	{
//		return new HeapOnly;
//	}
//	//2、delete函数 C++11（没有缺陷）
//	HeapOnly(const HeapOnly&) = delete;
//
//private:
//
//	HeapOnly()//创建对象调用构造函数
//	{}
//
//	//1. 将类的构造函数私有( C++ 98 )，拷贝构造声明成私有。防止别人调用拷贝在栈上生成对象。
//	//缺陷：友元函数可突破，如果是友元函数的话，仍然能够调用
//	//HeapOnly(const HeapOnly&);//拷贝构造只声明，不实现，声明成私有
//	
//};
//
//class StackOnly
//{
//public:
//	static StackOnly GetStackObj()
//	{
//		return StackOnly();
//	}
//
//private:
//	StackOnly()
//	{ }
//};
//
//class StackOnly
//{
//public:
//	StackOnly()
//		{}
//private:
//
//	//只能在栈上创建对象，即不能在堆上创建，因此只要将new的功能屏蔽掉即可，即屏蔽掉operator new和定位new表达式，注意：屏蔽了operator new，实际也将定位new屏蔽掉  
//	//缺陷：没有屏蔽掉全局的
//	void* operator new(size_t size);
//	void operator delete(void* p);
//};
//
//int main()
//{
//	//HeapOnly obj1;   //栈上创建
//	//HeapOnly* pobj = new HeapOnly;  //堆上也不行，HeapOnly要调用构造函数
//
//	HeapOnly* pobj = HeapOnly::GetHeapObj();
//	//HeapOnly copy(*pobj);   //copy在栈上
//
//	//StackOnly stpobj = StackOnly::GetStackObj();
//	StackOnly stobj;
//	
//
//	system("pause");
//	return 0;
//}



//************************************************************************
//单例模式(设计模式)
//3个条件：1>.构造一个私有的函数 2>.公有的GetInstance 3>.一个静态的对象
////
////饿汉模式(一上来就吃，先创建好)
////class ConfigSingleton
////{
////public:
////	//2.公有的 GetInstance()
////	static ConfigSingleton* GetInstance()
////	{
////		return &_sinst;
////	}
////	
////	void Print()
////	{
////		std::cout << _ip << std::endl;
////		std::cout << _port << std::endl;
////	}
////private:
////	//1.构造函数私有
////	ConfigSingleton(const char* ip,int port)
////		:_ip(ip)
////		,_port(port)
////	{
////		//初始化
////	}
////
////	ConfigSingleton(const ConfigSingleton&) = delete;
////
////	//配置信息：IP、端口
////	const char* _ip;
////	int _port;
////
////	//3.写一个静态的对象 —— 声明；类外定义
////	static ConfigSingleton _sinst;  //保证全局只有唯一一个实例（在自己类里面定义一个类对象）；静态的相当于全局的，放在private里面受类域的限制
////};
////ConfigSingleton ConfigSingleton::_sinst("127.0.0.1", 80);
////
////int main()
////{
////	ConfigSingleton::GetInstance()->Print();
////	//ConfigSingleton copy(*ConfigSingleton::GetInstance());   //为避免此类情况发生，需要应用delete
////	ConfigSingleton& operator=(const ConfigSingleton&) = delete;   //封锁运算符重载，以免干扰
////	
////	system("pause");
////	return 0;
////}
//****************************************************************************************
//【自己敲一下啦】真的有发现问题呢！定义初始化忘记写啦，自己对该部分代码理解不透彻，但是，还好已经解决了，算是一种进步嘞，继续加油啦 (づ｡◕ᴗᴗ◕｡)づ
//class ConfigSingleton
//{
//public:
//	//static ConfigSingleton& GetInstance()
//	//{
//	//	return _sinst;
//	//}
//
//	static ConfigSingleton* GetInstance()
//	{
//		return &_sinst;
//	}
//
//	void Print()
//	{
//		std::cout << _ip << std::endl;
//		std::cout << _port << std::endl;
//	}
//
//private:
//	const char* _ip;
//	int _port;
//	ConfigSingleton(const char* ip, int port)
//		:_ip(ip)
//		, _port(port)
//	{}
//
//   //防拷贝
//	ConfigSingleton(const ConfigSingleton&) = delete;
//	ConfigSingleton& operator=(const ConfigSingleton&) = delete;   //封锁运算符重载，以免干扰
//
//	static ConfigSingleton _sinst;
//};
////定义初始化
//ConfigSingleton ConfigSingleton::_sinst("127.0.0.1", 80);
//
//int main()
//{
//	//ConfigSingleton::GetInstance().Print();
//	ConfigSingleton::GetInstance()->Print();
//
//	system("pause");
//	return 0;
//}

////********************************************************************************
//////懒汉模式：
//#include <thread>
//#include <mutex>
//
//class ConfigSingleton
//{
//public:
//	//饿的不行了再吃
//	static ConfigSingleton* GetInstance()
//	{
//		// t1
//		// t2
//		//return new ConfigSingleton();//不能这样写；直接这样写，程序可以跑过，但是不是单例的（调一次，创建一个）
//		//double check ：双检查加锁，保证效率和线程安全
//		if (_psinst == nullptr)  
//		{
//			//t1
//			//t2
//			//两个线程进第一层循环，遇锁先进一个线程，加锁，if判断为空，创建一个对象，然后解锁；第二个线程进来，加锁，if判断不为空，直接返回（保证只调用一次构造）
//			_mtx.lock();  //加锁（多线程下体现）
//	
//			if (_psinst == nullptr)
//			{
//				_psinst = new ConfigSingleton;
//
//			}
//
//			_mtx.unlock();  //解锁
//		}
//		return _psinst;
//	}
//
//	class GC
//	{
//	public:
//		~GC()
//		{
//			delete _psinst;
//		}
//	};
//
//	void Print()
//	{
//		std::cout << _ip << std::endl;
//		std::cout << _port << std::endl;
//	}
//
//private:
//	//1.构造函数私有
//	ConfigSingleton(const char* ip = "127.0.0.1", int port = 80)
//		:_ip(ip)
//		, _port(port)
//	{
//		//初始化
//		std::cout << "ConfigSingleton()" << std::endl;//两个线程同时运行
//	}
//
//	// 实现一个内嵌垃圾回收类 （完成数据库关闭，链接等问题）
//	~ConfigSingleton()      //只写析构的话发现：不会直接调用析构函数，为保证调用析构函数，就要定义一个内部类
//	{
//		std::cout << "~ConfigSingleton()" << std::endl;
//	}
//
//	//防拷贝，重载
//	ConfigSingleton(const ConfigSingleton&) = delete;
//	ConfigSingleton operator=(const ConfigSingleton&) = delete;
//
//	//配置信息
//	const char* _ip;
//	int _port;
//
//	//static ConfigSingleton _sinst;   //错：不能一上来就创建对象
//	static ConfigSingleton* _psinst;   //饿的快要跪了的时候再吃
//	static std::mutex _mtx;
//	static ConfigSingleton::GC _gc;
//};
//
//ConfigSingleton* ConfigSingleton::_psinst = nullptr;
//std::mutex ConfigSingleton::_mtx;
//ConfigSingleton::GC ConfigSingleton:: _gc;
//
//void func(int n)
//{
//	std::cout << ConfigSingleton::GetInstance() << std::endl;
//}
//
//int main()
//{
//	ConfigSingleton::GetInstance()->Print();
//
//	std::thread t1(func, 10);
//	std::thread t2(func, 10);
//	t1.join();
//	t2.join();
//
//	//system("pause");
//	return 0;
//}

//**********************************************************************************

//
////检验进程的并发和并行
//#include <thread>
//void func(int n)
//{
//	//std::cout << Singleton::GetInstance() << std::endl;
//	for (int i = 0; i < n; ++i)
//	{
//		std::cout << i << std::endl;
//	}
//}
//
//int main()
//{
//	////串行（一条执行完了执行下一条）——>0123456789
//	//func(10);
//	//func(10);
//
//	//并行（同时执行）——>00112233445566778899 (可能会有提前换行,随机性)
//	std::thread t1(func, 10);
//	std::thread t2(func, 10);
//	t1.join();
//	t2.join();
//
//	system("pause");
//	return 0;
//}



