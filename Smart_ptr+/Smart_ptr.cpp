#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>   //���ṩ���̰߳�ȫ

using namespace std;

//void Func()
//{
//	//������ڳ�ª��Ӧ��RAII˼��Ľ�����Դ��������ȥ����
//	int n;
//	cin >> n;
//	int* p1 = new int;
//	int* p2 = new int[n];
//
//	delete p1;
//	delete[] p2;
//}

//RAII˼��ԭ��
//RAII�Ѳ��õ���Դ��ʾ�ͷ�
//template<class T>
//class SmartPtr
//{
//public:
//	SmartPtr(T* ptr)           //ָ���á�*��
//		:_ptr(ptr)
//	{}
//
//	~SmartPtr()
//	{
//		cout << "delete1��" << _ptr << endl;   //����Ƿ��ͷ�
//		delete[] _ptr;
//	}
//
//private:
//	T* _ptr;   //���Ǳ��̳еĻ�����protect
//};
//
//void Func()
//{
//
//	int* p1 = new int;
//	SmartPtr<int> sp1(p1);//����Ҫ���ͷ��ڴ��ˣ���Ϊ����Դ������sp1���������,����RAII����˼��ָ�룩���쳣������ֱ������������������������ͷ���Դ
//	//�����ڴ�й©���⣺�ͺ󡪡�>������ͨ����⹤�߽������ǰ����>��ȷӦ������ָ�����
//
//	//vector<int> v;
//	//v.at(0) = 10;        //at���൱��[]��,�˴��Ჶ���쳣
//	////v.[0] = 10;        //���ֱ��ʹ��[],ֱ�ӻ�assert������ֱ����ֹ��
//
//	vector<int> v(10);    //����һ���ܴ��10���ڴ�Ķ��󣨸�һ����Χ�ڵ����������ͷţ���
//	size_t pos;
//	cin >> pos;
//	v.at(pos) = 10;
//
//	//cout << "delete2��" << p1 << endl;  //����Ƿ��ͷţ�����ֻ�����쳣
//	//delete p1;
//}
//
//template<class T>
//class SmartLock
//{
//public:
//	SmartLock(T& lock)     //�����á�&��
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
//mutex mtx;              //����һ��Ҫ�󣺱�����ͬһ����()����>����Ϊȫ�ֵ�
//
//void Add(size_t n, int* value)  //ִ��һ��ָ��(����һ��)��ԭ�ӵ�
//{
//	//SmartLock<mutex> smtlock(mtx);         //����ѭ�������ܱȽϵͣ��൱��ͬһ���߳�ֻ�����һ�Σ�ִ�������еĹ����ٽ�����ֻ����1�Σ�  
//	std::unique_lock<std::mutex> lock(mutex);   //�������������������߳�
//
//	for (size_t i = 0; i < n; ++i)
//	{
//		//SmartLock<mutex> smtlock(mtx);   //����ѭ����Ҳ���ԣ��������ܱȽϵͣ��൱��ͬһ���߳�ִ�е�ÿһ����Ҫ���������� ����Ӧ����������
//		++(*value);   //cas(��������������(����ѭ������Ļ�Ӧ����������Ӧ�����������Ƚ�С))
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
//	/*try         //�����쳣,�Ƿ��Ӳ��� : v.at(0) = 10;        at���൱��[]��
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
//����ָ���ԭ��
//����ָ��߱������㣺1.RAII 2.��ָ��һ������Ϊ
//template<class T>
//class SmartPtr {
//public:
//	//1.RAII(���ֵ��ǹ���(������Դ)������(�Զ�������Դ))
//	SmartPtr(T* ptr = nullptr)
//		: _ptr(ptr)
//	{}
//	~SmartPtr()
//	{
//		if (_ptr)
//			delete _ptr;
//	}
//	
//	//2.��ָ��һ������Ϊ(����operator*������operator->)
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
//	//sp1.operator*() = 111;//ʵ�ʵ��ã��Ѷ����ַ����ȥ���õ����������ָ�룬Ȼ���ٷ���ָ��(sp1.operator*())ָ��ֵ(*_ptr)�ı������Ϳ��԰�ָ��ָ���ֵ�޸���
//	
//	cout << *sp1 << endl;
//
//	//**************************************
//
//	SmartPtr<A> sp2(new A);
//	(*sp2)._a1 = 100;
//	sp2->_a2 = 200;   //sp2->->_a2 = 20;  �﷨��Ϊ�˿ɶ���,ʡ����һ��->
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
//���ϴ������⣬ʵ�ʲ�������ʹ��
//C++98
//����Ȩת��(���Ǻ���):����ȱ�ݵ�������ƣ��Ͻ�ʹ�ã���������
//auto_ptr�����˼·�ǹ���Ȩת�ƣ�������ֵ����ǰ���󣬽��Լ��ÿգ���һ��������ƣ�ȱ�ݣ�����ʱԭ�������գ�������ʱ���������
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
//		//����Ȩת��(���Ǻ���)
//		//ap1(ap2) this:ap1 | ap:ap2
//		auto_ptr(auto_ptr<T>& ap)
//			:_ptr(ap._ptr)
//		{
//			_ptr = nullptr;//��û����һ�䣬���������β��ұ���
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
//	//*ap1 = 10; //����
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
// ģ��ʵ�ּ򵥵�AutoPtr          **********************        (ժ����������)
//auto_ptr��ʵ��ԭ������Ȩת�Ƶ�˼�룬�����ģ��ʵ����һ��AutoPtr���˽�����ԭ��
// C++���е�����ָ�붼������memory���ͷ�ļ���
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
//	// auto_ptr�����⣺�����󿽱����߸�ֵ��ǰ��Ķ����������
//	// C++98����Ƶ�auto_ptr�����Ƿǳ����Եģ�����ʵ���кܶ๫˾��ȷ�涨�˲���ʹ��auto_ptr
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
//	// һ�������������ͽ�ap����Դת�Ƶ���ǰ�����У�Ȼ����ap������������Դ�Ͽ���ϵ��
//	// �����ͽ����һ��ռ䱻�������ʹ�ö���ɳ���������
//	AutoPtr(AutoPtr<T>& ap)
//		: _ptr(ap._ptr)
//	{
//		ap._ptr = NULL;
//	}
//
//	AutoPtr<T>& operator=(AutoPtr<T>& ap)
//	{
//		// ����Ƿ�Ϊ�Լ����Լ���ֵ
//		if (this != &ap)
//		{
//			// �ͷŵ�ǰ��������Դ
//			if (_ptr)
//				delete _ptr;
//			// ת��ap����Դ����ǰ������
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
//	// �����ٴ�ʵ��ԭ����������ᷢ�֣����������ap�����ָ�븳���ˣ�����ap��������
//	// ͨ��ap���������Դʱ�ͻ�������⡣
//	AutoPtr<Date> copy(ap);
//	ap->_year = 2019;
//
//	system("pause");
//	return 0;
//}
//***********************************************************************************
////C++11 
////unique_ptr :�򵥴ֱ�����������Ч�ʸߣ����ܲ�ȫ������ѡ��ʹ��!!!!!!!!!
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
//		//C++98 ֻ��������ʵ�֣��������Ļ���ϵͳ���Զ����ɣ�
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
//share_ptr:����ȫ��֧�ֿ��������ü���(���һ���������ĲŻ��ͷ���)����Ƹ��ӣ�ѭ������
//share_ptr�������̰߳�ȫ�ģ�����ָ��Ķ������̰߳�ȫ��

namespace zcc
{
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr)
			:_ptr(ptr)
			, _pcount(new int(1))  //()��ʼ�� ��[]����    ���ﲻ��Ҫ�������ڲŴ�����ʱ��
			, _pmtx(new std::mutex)
		{}

		//��������
		shared_ptr(const shared_ptr<T>& sp)    //C++98 ֻ��������ʵ�֣��������Ļ���ϵͳ���Զ����ɣ�
			:_ptr(sp._ptr)
			, _pcount(sp._pcount)
			, _pmtx(sp._pmtx)               
		{
			//++(*_pcount);
			AddRef();//�����Ĳ���
		}

		//��ֵ sp1=sp3�����ͷ�sp1�Ŀռ䣩
		shared_ptr<T>& operator=(const shared_ptr<T>& sp)    //C++98 ֻ��������ʵ�֣��������Ļ���ϵͳ���Զ����ɣ�
		{
			if (this != &sp)  //��ֹ�Լ����Լ�����//this,sp������ͬһ��ָ��
			//if (_ptr != &sp._ptr)     //�������(�ܱ�֤�Ƕ����ͬ������)ָ��ָ��ͬһ���ռ�Ļ��������ѭ��
			{
				Release();

				_ptr = sp._ptr;
				_pcount = sp._pcount;
				_pmtx = sp._pmtx;

				AddRef();
			}
			return *this;
		}

		
		~shared_ptr()     //Խ�粻һ������
		{
			/*if (--(*_pcount) == 0)
			{
				cout << "delete:" << _ptr << endl;
				delete _ptr;
				delete _pcount;
			}*/
			Release();
		}

		//����̰߳�ȫ����:����(��ͬһ����)
		void AddRef()
		{
			_pmtx->lock();
			++(*_pcount);
			_pmtx->unlock();
		}

		void Release()   //����0Ҫ�ͷ�
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


			////�����̰߳�ȫ�ģ����·������� ��ʱ��Ƭ����֮�������ǰ�г�(ͬһ�ռ�����ͷ�����)
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
		int* _pcount;  //Ӧ��ͬһ�����ü���(����Ӧ��static);�����Ϊ���ü������ſռ���(��̬����)������һ���ռ���һ�����ü�������ÿ������ָ�붼���õ������ü���
		std::mutex* _pmtx;   //ͬ��һ�У���*Ŀ����ȷ��ָ��ͬһ����
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
		std::shared_ptr<int> copy(sp);  //������̰߳�ȫ��

		//std::unique_lock<std::mutex> lock(_pmtx);    //���˱���֮�����̰߳�ȫ��
		//++(*copy);         //���䲻���̰߳�ȫ��(�н�ǿ�������)
	}
}

//++/-- �����̰߳�ȫ����(����̶߳�ͬһ�����ݽ����޸ģ��������)
void test_shared_ptr_safe()
{
	std::shared_ptr<int> sp(new int);

	//�����߳�ͬʱ������n�Σ�����С�������ͷţ��������ͷų���
	std::thread t1(test_multi_thread_copy, sp, 10);
	std::thread t2(test_multi_thread_copy, sp, 10);

	t1.join();
	t2.join();

	cout << sp.use_count() << endl; //use_count������0�Ļ������
	cout << *sp << endl; //use_count������0�Ļ������
}

//shared_ptr��ѭ������***************************************************************
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
	////shared_ptr������explicit:������������ǿת
	//std::shared_ptr<ListNode> cur(new ListNode);
	//std::shared_ptr<ListNode> next(new ListNode);
	std::shared_ptr<ListNode> cur(new ListNode);
	std::shared_ptr<ListNode> next(new ListNode);

	//ѭ������
	cur->_next = next;
	cur->_prev = cur;

}

//����ɾ����*************************************************************************
template<class T>
struct DeleteArray
{
	void operator()(T* ptr)//�º�����������()
	{
		delete[] ptr;
	}
};
struct test//����һ�����ڲ��Ե���
{
	~test()
	{
		cout << "~test()" << endl;
	}
};
void test_shared_ptr_delete()//���Եĺ���
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