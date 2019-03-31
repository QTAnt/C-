#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
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
template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr)           //指针用‘*’
		:_ptr(ptr)
	{}

	~SmartPtr()
	{
		cout << "delete1：" << _ptr << endl;   //检查是否释放
		delete[] _ptr;
	}

private:
	T* _ptr;
};

void Func()
{
	
	int* p1 = new int;
	SmartPtr<int> sp1(p1);//不需要再释放内存了（因为把资源交给了sp1对象管理了,符合RAII智能思想指针）抛异常或者是直接正常结束，都会调析构，释放资源
	//处理内存泄漏问题：释后——>分析、通过检测工具解决；释前——>正确应用智能指针管理

	//vector<int> v;
	//v.at(0) = 10;        //at‘相当于[]’,此处会捕获异常
	////v.[0] = 10;        //如果直接使用[],直接会assert（程序直接终止）

	vector<int> v(10);    //创建一个能存放10个内存的对象
	size_t pos;
	cin >> pos;
	v.at(pos) = 10;

	//cout << "delete2：" << p1 << endl;  //检查是否释放；错误：只会抛异常
	//delete p1;
}

template<class T>
class SmartLock
{
public:
	SmartLock(T& lock)     //对象用‘&’
		:_lock(lock)
	{
		_lock.lock();
	}

	~SmartLock()
	{
		//cout << "unlock:" << &_lock << endl;
		_lock.unlock();
	}

private:
	T& _lock;
};

mutex mtx;              //锁有一个要求：必须是同一把锁()——>定义为全局的

void Add(size_t n, int* value)  //执行一句指令(不是一行)是原子的
{
	SmartLock<mutex> smtlock(mtx);         //放在循环外性能比较低；相当于同一个线程只需加锁一次，执行完所有的工作再解锁（只消耗1次）  

	for (size_t i = 0 ; i < n; ++i)
	{
		//SmartLock<mutex> smtlock(mtx);   //放在循环里也可以，但是性能比较低；相当于同一个线程执行的每一步都要加锁、解锁 （可应用自旋锁）
		++(*value);   //cas(互斥锁、自旋锁)
	}
}

int main()
{
	int x = 0;
	std::thread t1(Add, 100000, &x);
	std::thread t2(Add, 100000, &x);

	t1.join();
	t2.join();

	cout << x << endl;
	/*try
	{
		Func();
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}*/

	system("pause");
	return 0;
}