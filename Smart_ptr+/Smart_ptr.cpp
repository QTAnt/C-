#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>   //库提供，线程安全

using namespace std;

//void Func()
//{
//	//代码过于丑陋，应用RAII思想改进（资源交给对象去管理）
//	int n;
//	cin >> n;
//	int* p1 = new int;
//	int* p2 = new int[n];
//
//	delete p1;
//	delete[] p2;
//}

//RAII思想原型
//RAII把不用的资源显示释放
//template<class T>
//class SmartPtr
//{
//public:
//	SmartPtr(T* ptr)           //指针用‘*’
//		:_ptr(ptr)
//	{}
//
//	~SmartPtr()
//	{
//		cout << "delete1：" << _ptr << endl;   //检查是否释放
//		delete[] _ptr;
//	}
//
//private:
//	T* _ptr;   //考虑被继承的话，用protect
//};
//
//void Func()
//{
//
//	int* p1 = new int;
//	SmartPtr<int> sp1(p1);//不需要再释放内存了（因为把资源交给了sp1对象管理了,符合RAII智能思想指针）抛异常或者是直接正常结束，都会调析构，释放资源
//	//处理内存泄漏问题：释后——>分析、通过检测工具解决；释前——>正确应用智能指针管理
//
//	//vector<int> v;
//	//v.at(0) = 10;        //at‘相当于[]’,此处会捕获异常
//	////v.[0] = 10;        //如果直接使用[],直接会assert（程序直接终止）
//
//	vector<int> v(10);    //创建一个能存放10个内存的对象（给一个范围内的数，正常释放；）
//	size_t pos;
//	cin >> pos;
//	v.at(pos) = 10;
//
//	//cout << "delete2：" << p1 << endl;  //检查是否释放；错误：只会抛异常
//	//delete p1;
//}
//
//template<class T>
//class SmartLock
//{
//public:
//	SmartLock(T& lock)     //对象用‘&’
//		:_lock(lock)
//	{
//		_lock.lock();
//	}
//
//	~SmartLock()
//	{
//		//cout << "unlock:" << &_lock << endl;
//		_lock.unlock();
//	}
//
//private:
//	T& _lock;
//};
//
//mutex mtx;              //锁有一个要求：必须是同一把锁()——>定义为全局的
//
//void Add(size_t n, int* value)  //执行一句指令(不是一行)是原子的
//{
//	//SmartLock<mutex> smtlock(mtx);         //放在循环外性能比较低；相当于同一个线程只需加锁一次，执行完所有的工作再解锁（只消耗1次）  
//	std::unique_lock<std::mutex> lock(mutex);   //加锁、解锁的消耗在线程
//
//	for (size_t i = 0; i < n; ++i)
//	{
//		//SmartLock<mutex> smtlock(mtx);   //放在循环里也可以，但是性能比较低；相当于同一个线程执行的每一步都要加锁、解锁 （可应用自旋锁）
//		++(*value);   //cas(互斥锁、自旋锁(加在循环里面的话应用自旋锁，应用于锁的力度较小))
//	}
//}

//int main()
//{
//	int x = 0;
//	std::thread t1(Add, 100000, &x);
//	std::thread t2(Add, 100000, &x);
//
//	t1.join();
//	t2.join();
//
//	cout << x << endl;
//	
//	/*try         //捕获异常,非法子部分 : v.at(0) = 10;        at‘相当于[]’
//	{
//	Func();
//	}
//	catch (exception& e)
//	{
//	cout << e.what() << endl;
//	}*/
//
//	system("pause");
//	return 0;
//}

//***********************************************************************************
//智能指针的原理
//智能指针具备的两点：1.RAII 2.想指针一样的行为
//template<class T>
//class SmartPtr {
//public:
//	//1.RAII(体现的是构造(保存资源)和析构(自动析构资源))
//	SmartPtr(T* ptr = nullptr)
//		: _ptr(ptr)
//	{}
//	~SmartPtr()
//	{
//		if (_ptr)
//			delete _ptr;
//	}
//	
//	//2.想指针一样的行为(重载operator*和重载operator->)
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//
//private:
//	T* _ptr;
//};
//
//struct  A
//{
//	int _a1;
//	int _a2;
//};

//int main()
//{
//	int* p1 = new int;
//	SmartPtr<int> sp1(new int);
//
//	*p1 = 100;
//	*sp1 = 111;
//	//sp1.operator*() = 111;//实际调用，把对象地址传过去，拿到对象里面的指针，然后再返回指针(sp1.operator*())指向值(*_ptr)的别名，就可以把指针指向的值修改了
//	
//	cout << *sp1 << endl;
//
//	//**************************************
//
//	SmartPtr<A> sp2(new A);
//	(*sp2)._a1 = 100;
//	sp2->_a2 = 200;   //sp2->->_a2 = 20;  语法上为了可读性,省略了一个->
//	cout << sp2->_a2 <<endl;
//
//	system("pause");
//	return 0;
//}

//***********************************************************************************
//int main()
//{
//	SmartPtr<int> sp1(new int);
//	SmartPtr<int> sp2(sp1);
//
//	system("pause");
//	return 0;
//}
//以上存在问题，实际不能那样使用
//C++98
//管理权转移(不是很优):带有缺陷的早期设计，严禁使用，不可抛弃
//auto_ptr的设计思路是管理权转移，拷贝赋值给当前对象，将自己置空，是一种悬空设计；缺陷：拷贝时原对象悬空，解引用时会出现问题
//namespace zcc
//{
//	template<class T>
//	class auto_ptr
//	{
//	public:
//		auto_ptr(T* ptr)
//			:_ptr(ptr)
//		{}
//
//		~auto_ptr()
//		{
//			if (_ptr != nullptr)
//			{
//				cout << "delete:" << _ptr << endl;
//				delete _ptr;
//			}
//		}
//
//		//管理权转移(不是很优)
//		//ap1(ap2) this:ap1 | ap:ap2
//		auto_ptr(auto_ptr<T>& ap)
//			:_ptr(ap._ptr)
//		{
//			_ptr = nullptr;//若没有这一句，会析构两次并且报错
//		}
//
//		T& operator*()
//		{
//			return *_ptr;
//		}
//
//		T* operator->()
//		{
//			return _ptr;
//		}
//
//	private:
//		T* _ptr;
//	};
//}
//
//void test_auto_ptr()
//{
//	zcc::auto_ptr<int> ap1(new int);
//	zcc::auto_ptr<int> ap2(ap1);
//
//	//*ap1 = 10; //悬空
//	//*ap2 = 11;
//}
//
//int main()
//{
//	test_auto_ptr();
//
//	system("pause");
//	return 0;
//}

//***********************************************************************************
// 模拟实现简单的AutoPtr          **********************        (摘抄，有疑问)
//auto_ptr的实现原理：管理权转移的思想，下面简化模拟实现了一份AutoPtr来了解它的原理
// C++库中的智能指针都定义在memory这个头文件中
//#include <memory>
//class Date
//{
//public:
//	Date() { cout << "Date()" << endl; }
//	~Date(){ cout << "~Date()" << endl; }
//	int _year;
//	int _month;
//	int _day;
//};

//int main()
//{
//	auto_ptr<Date> ap(new Date);
//	auto_ptr<Date> copy(ap);
//	// auto_ptr的问题：当对象拷贝或者赋值后，前面的对象就悬空了
//	// C++98中设计的auto_ptr问题是非常明显的，所以实际中很多公司明确规定了不能使用auto_ptr
//	ap->_year = 2018;
//	return 0;
//}

//template<class T>
//class AutoPtr
//{
//public:
//	AutoPtr(T* ptr = NULL)
//		: _ptr(ptr)
//	{}
//
//	~AutoPtr()
//	{
//		if (_ptr)
//			delete _ptr;
//	}
//	// 一旦发生拷贝，就将ap中资源转移到当前对象中，然后另ap与其所管理资源断开联系，
//	// 这样就解决了一块空间被多个对象使用而造成程序奔溃问题
//	AutoPtr(AutoPtr<T>& ap)
//		: _ptr(ap._ptr)
//	{
//		ap._ptr = NULL;
//	}
//
//	AutoPtr<T>& operator=(AutoPtr<T>& ap)
//	{
//		// 检测是否为自己给自己赋值
//		if (this != &ap)
//		{
//			// 释放当前对象中资源
//			if (_ptr)
//				delete _ptr;
//			// 转移ap中资源到当前对象中
//			_ptr = ap._ptr;
//			ap._ptr = NULL;
//		}
//		return *this;
//	}
//
//	T& operator*()
//	{
//		return *_ptr;
//	}
//
//	T* operator->()
//	{
//		return _ptr;
//	}
//private:
//	T* _ptr;
//};
//
//int main()
//{
//	AutoPtr<Date> ap(new Date);
//	// 现在再从实现原理层来分析会发现，这里拷贝后把ap对象的指针赋空了，导致ap对象悬空
//	// 通过ap对象访问资源时就会出现问题。
//	AutoPtr<Date> copy(ap);
//	ap->_year = 2019;
//
//	system("pause");
//	return 0;
//}
//***********************************************************************************
////C++11 
////unique_ptr :简单粗暴，防拷贝；效率高，功能不全；优先选择使用!!!!!!!!!
//namespace zcc
//{
//	template<class T>
//	class unique_ptr
//	{
//	public:
//		unique_ptr(T* ptr)
//			:_ptr(ptr)
//		{}
//
//		~unique_ptr()
//		{
//			if (_ptr != nullptr)
//			{
//				cout << "delete:" << _ptr << endl;
//				delete _ptr;
//			}
//		}
//
//		unique_ptr(const unique_ptr<T>& ap) = delete;
//		unique_ptr<T>& operator=(const unique_ptr<T>& ap) = delete;
//		//C++98 只声明，不实现（不声明的话，系统会自动生成）
//
//		T& operator*()
//		{
//			return *_ptr;
//		}
//
//		T* operator->()
//		{
//			return _ptr;
//		}
//
//	private:
//		T* _ptr;
//	};
//}
//
//void test_unique_ptr()
//{
//	zcc::unique_ptr<int> up1(new int);
//	zcc::unique_ptr<int> up2(new int);
//}
//
//int main()
//{
//	test_unique_ptr();
//
//	system("pause");
//	return 0;
//}
//***********************************************************************************
//share_ptr:功能全，支持拷贝，引用计数(最后一个引用它的才会释放它)；设计复杂，循环引用
//share_ptr本身是线程安全的，但是指向的对象不是线程安全的

namespace zcc
{
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr)
			:_ptr(ptr)
			, _pcount(new int(1))  //()初始化 ；[]数组    这里不需要加锁，在才创建的时候
			, _pmtx(new std::mutex)
		{}

		//拷贝构造
		shared_ptr(const shared_ptr<T>& sp)    //C++98 只声明，不实现（不声明的话，系统会自动生成）
			:_ptr(sp._ptr)
			, _pcount(sp._pcount)
			, _pmtx(sp._pmtx)               
		{
			//++(*_pcount);
			AddRef();//加锁的操作
		}

		//赋值 sp1=sp3（先释放sp1的空间）
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)    //C++98 只声明，不实现（不声明的话，系统会自动生成）
		{
			if (this != &sp)  //防止自己给自己拷贝//this,sp可能是同一个指针
			//if (_ptr != &sp._ptr)     //多个智能(能保证是多个不同的智能)指针指向同一个空间的话，不会进循环
			{
				Release();

				_ptr = sp._ptr;
				_pcount = sp._pcount;
				_pmtx = sp._pmtx;

				AddRef();
			}
			return *this;
		}

		
		~shared_ptr()     //越界不一定报错
		{
			/*if (--(*_pcount) == 0)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
				delete _pcount;
			}*/
			Release();
		}

		//解决线程安全问题:加锁(锁同一个锁)
		void AddRef()
		{
			_pmtx->lock();
			++(*_pcount);
			_pmtx->unlock();
		}

		void Release()   //减到0要释放
		{
			//<1>
			bool deleteflag = false;
			_pmtx->lock();
			if (--(*_pcount) == 0)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
				delete _pcount;
				deleteflag = true;
			}
			_pmtx->unlock();

			if (deleteflag == true)
				delete _pmtx;

			//<2>
			//_pmtx->lock();
			//if (--(*_pcount) == 0)
			//{
			//	cout << "delete:" << _ptr << endl;
			//	delete _ptr;
			//	delete _pcount;
			//	_pmtx->unlock();
			//	delete _pmtx;
			//	return;
			//}
			//_pmtx->unlock();


			////不是线程安全的，以下方法出错 ；时间片到了之后可能提前切出(同一空间可能释放两次)
			//_pmtx->lock();
			//--(*_pcount);
			//_pmtx->unlock();

			//if (*_pcount == 0)
			//{
			//	delete _ptr;
			//	delete _pcount;
			//	delete _pmtx;
			//}
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
		int use_count()
		{
			return *_pcount;
		}

	private:
		T* _ptr;
		int* _pcount;  //应用同一个引用计数(不能应用static);可设计为引用计数跟着空间走(动态开辟)，创建一个空间有一个引用计数；且每个智能指针都能拿到该引用计数
		std::mutex* _pmtx;   //同上一行，加*目的是确保指向同一个锁
	};
}

void test_shared_ptr()
{
	std::shared_ptr<int> sp1(new int);
	std::shared_ptr<int> sp2(sp1);

	std::shared_ptr<int> sp3(new int);
	sp1 = sp3;
}

void test_multi_thread_copy(std::shared_ptr<int>& sp, size_t n)
{
	for (size_t i = 0; i < n; ++i)
	{
		std::shared_ptr<int> copy(sp);  //本句的线程安全的

		//std::unique_lock<std::mutex> lock(_pmtx);    //加了本句之后是线程安全的
		//++(*copy);         //本句不是线程安全的(有较强的随机性)
	}
}

//++/-- 存在线程安全问题(多个线程对同一份数据进行修改，结果不对)
void test_shared_ptr_safe()
{
	std::shared_ptr<int> sp(new int);

	//两个线程同时被调用n次（次数小，正常释放；次数大，释放出错）
	std::thread t1(test_multi_thread_copy, sp, 10);
	std::thread t2(test_multi_thread_copy, sp, 10);

	t1.join();
	t2.join();

	cout << sp.use_count() << endl; //use_count不等于0的话则出错
	cout << *sp << endl; //use_count不等于0的话则出错
}

//shared_ptr的循环引用***************************************************************
struct ListNode
{
	std::weak_ptr<ListNode> _next;
	std::weak_ptr<ListNode> _prev;

	~ListNode()
	{
		cout << "~ListNode()" << endl;
	}
};

void test_shared_ptr_cycle()
{
	////shared_ptr库里有explicit:不允许单参数的强转
	//std::shared_ptr<ListNode> cur(new ListNode);
	//std::shared_ptr<ListNode> next(new ListNode);
	std::shared_ptr<ListNode> cur(new ListNode);
	std::shared_ptr<ListNode> next(new ListNode);

	//循环引用
	cur->_next = next;
	cur->_prev = cur;

}

//定制删除器*************************************************************************
template<class T>
struct DeleteArray
{
	void operator()(T* ptr)//仿函数：重载了()
	{
		delete[] ptr;
	}
};
struct test//定义一个用于测试的类
{
	~test()
	{
		cout << "~test()" << endl;
	}
};
void test_shared_ptr_delete()//测试的函数
{
	DeleteArray<test> del;
	std::shared_ptr<test> ptr(new test[10], del);
}


int main()
{
	//test_shared_ptr_cycle();
	test_shared_ptr_delete();
	system("pause");
	return 0;
}