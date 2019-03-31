#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
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
template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr)           //ָ���á�*��
		:_ptr(ptr)
	{}

	~SmartPtr()
	{
		cout << "delete1��" << _ptr << endl;   //����Ƿ��ͷ�
		delete[] _ptr;
	}

private:
	T* _ptr;
};

void Func()
{
	
	int* p1 = new int;
	SmartPtr<int> sp1(p1);//����Ҫ���ͷ��ڴ��ˣ���Ϊ����Դ������sp1���������,����RAII����˼��ָ�룩���쳣������ֱ������������������������ͷ���Դ
	//�����ڴ�й©���⣺�ͺ󡪡�>������ͨ����⹤�߽������ǰ����>��ȷӦ������ָ�����

	//vector<int> v;
	//v.at(0) = 10;        //at���൱��[]��,�˴��Ჶ���쳣
	////v.[0] = 10;        //���ֱ��ʹ��[],ֱ�ӻ�assert������ֱ����ֹ��

	vector<int> v(10);    //����һ���ܴ��10���ڴ�Ķ���
	size_t pos;
	cin >> pos;
	v.at(pos) = 10;

	//cout << "delete2��" << p1 << endl;  //����Ƿ��ͷţ�����ֻ�����쳣
	//delete p1;
}

template<class T>
class SmartLock
{
public:
	SmartLock(T& lock)     //�����á�&��
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

mutex mtx;              //����һ��Ҫ�󣺱�����ͬһ����()����>����Ϊȫ�ֵ�

void Add(size_t n, int* value)  //ִ��һ��ָ��(����һ��)��ԭ�ӵ�
{
	SmartLock<mutex> smtlock(mtx);         //����ѭ�������ܱȽϵͣ��൱��ͬһ���߳�ֻ�����һ�Σ�ִ�������еĹ����ٽ�����ֻ����1�Σ�  

	for (size_t i = 0 ; i < n; ++i)
	{
		//SmartLock<mutex> smtlock(mtx);   //����ѭ����Ҳ���ԣ��������ܱȽϵͣ��൱��ͬһ���߳�ִ�е�ÿһ����Ҫ���������� ����Ӧ����������
		++(*value);   //cas(��������������)
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