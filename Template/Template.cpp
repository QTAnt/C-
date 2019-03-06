#include <iostream>
using namespace std;

//函数模板格式  template<typename T1, typename T2,......,typename Tn>

//void Swap(char& left, char& right)
//{
//	char temp = left;
//	left = right;
//	right = temp;
//}

//template<typename T>
//void Swap(T& left, T& right)
//{
//	T temp = left;
//	left = right;
//	right = temp;
//}
//
//int main()
//{
//	int a = 1, b = 2;
//	char c = '0', d = '9';
//	Swap(a, b); 
//	Swap(c, d);
//	cout << a << " " << b << endl;
//	cout << c << " " << d << endl;
//
//	system("pause");
//	return 0;
//}

//*************************************************************************************
////函数模板实例化(隐式)
//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//
//int main()
//{
//	int a1 = 10, a2 = 20;
//	double d1 = 10.0, d2 = 20.0;
//	//Add(a1,d1);
//	//Add(a2, d2);
//
//	/*
//	该语句不能通过编译，因为在编译期间，当编译器看到该实例化时，需要推演其实参类型
//	通过实参a1将T推演为int，通过实参d1将T推演为double类型，但模板参数列表中只有一个T，
//	编译器无法确定此处到底该将T确定为int 或者 double类型而报错
//	注意：在模板中，编译器一般不会进行类型转换操作，因为一旦转化出问题，编译器就需要背黑锅
//	Add(a1, d1);
//	*/
//
//	// 此时有两种处理方式：1. 用户自己来强制转化 
//	//Add(a1, (int)d1);
//
//	//2. 使用显式实例化
//	//Add<int>(a2, d2)
//
//	//输出
//	//cout << Add(a1, (int)d1) << endl;
//	//cout << Add<int>(a2, d2) << endl;
//	system("pause");
//	return 0;
//}


////函数模板显示实例化
//int main(void)
//{
// int a = 10;
// double b = 20.0;
// 
// // 显式实例化
// cout<< Add<int>(a, b) <<endl;
// system("pause");
// return 0;
//}

//*************************************************************************************
//模板参数的匹配原则：有现成的就优先使用现成的

//int Add(int left, int right)
//{
//	return left + right;
//}

 //通用加法函数
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//
//int Add(int left, int right)
//{
//	return left + right;
//}

//int main()
//{
//	Add(1, 2); // 与非模板函数匹配，编译器不需要特化
//	cout << Add(1, 2) << endl;
//	//cout << Add<int>(1, 2) << endl; // 调用编译器特化的Add版本
//
//	system("pause");
//	return 0;
//}

//*************************************************************************************
// 专门处理int的加法函数
//int Add(int left, int right)
//{
//	return left + right;
//}
//// 通用加法函数
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//
//int main()
//{
//	Add(1, 2); // 与非函数模板类型完全匹配，不需要函数模板实例化
//	cout << Add(1, 2.0) << endl; // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函数
//	system("pause");
//	return 0;
//}
//
//
//************************************************************************************* 
//template<class T1, class T2, ..., class Tn>
//class 类模板名
//{
//	// 类内成员定义
//}; 
//
////动态顺序表
#include <assert.h>
template<class T>   //模板参数
class Vector
{
public:
	Vector(size_t capacity = 10)
		: _array(new T[capacity])   //数据类型不确定，用T；()括号是初始化，[]是数组
		, _size(0)
		, _capacity(capacity)
	{}

	// 使用析构函数演示：在类中声明，在类外定义。
	~Vector()
	{
		if (_array)
		{
			delete[] _array;
			_array = nullptr;
			_size = _capacity = 0;
		}
	}

	//插入数据
	//void PushBack(SeqList* ps, DataType x);   //C语言
	void PushBack(const T& x)    //隐式的this指针 void PushBack(Vector<int>* this,const T& x)
	{
		//增容
		_array[_size] = x;
		++_size;
	}
	size_t Size()
	{
		return _size;
	}

	//T operator[](size_t pos)   
	//{
	//	assert(pos < _size);   //防止越界
	//	return _array[pos];
	//}

	T& operator[](size_t pos)
	{
		assert(pos < _size);   //防止越界
		return _array[pos];
	}

private:
	T* _array;
	size_t _size;
	size_t _capacity;
};

void Func(Vector<int>& v)//不能加const，const不能调用const
{
	for (size_t i = 0; i < v.Size(); ++i)
	{
		cout << v[i] << " ";
	}
}
int main()
{
	Vector<int> v1;   //不用推类型

	//PushBack(&s1, 1);   //C语言
	v1.PushBack(1);     //v1.PushBack(&v1,1);
	v1.PushBack(2);    
	v1.PushBack(3);     
	v1.PushBack(4);     

	Func(v1);

	for (size_t i = 0; i < v1.Size(); ++i)
	{
		//偶数乘以2倍
		if (v1[i] % 2 == 0)
		{
			v1[i] *= 2;   //运算符重载被编译器简化的一种写法
			v1.operator[](i) *= 2;//函数调用(赋给返回值)
		}
	}

	for (size_t i = 0; i < v1.Size(); ++i)
	{
		cout << v1[i] << " ";
		cout << v1.operator[](i) << " ";
	}

	cout << endl;

	Vector<char> v2;
	v2.PushBack('a');   
	v2.PushBack('b');
	v2.PushBack('c');
	v2.PushBack('d');

	for (size_t i = 0; i < v2.Size(); ++i)
	{
		cout << v2[i] << " ";
		/*cout << v2.operator[](i) << " ";*/
	}
	cout << endl;


	system("pause");
	return 0;
}
// 注意：类模板中函数放在类外进行定义时，需要加模板参数列表

////***********************************************************************************
////类模板的实例化
////类模板实例化与函数模板实例化不同，类模板实例化需要在类模板名字后跟<>，然后将实例化的类型放在<>中即可，类模板名字不是真正的类，而实例化的结果才是真正的类。
//
////// Vector类名，Vector<int>才是类型
//Vector<int> s1;
//s1.PushBack(1);
//s1.PushBack(2);
//s1.PushBack(3);
//Vector<double> s2;
//s2.PushBack(1.0);
//s2.PushBack(2.0);
//s2.PushBack(3.0);
//for (size_t i = 0; i < s1.Size(); ++i)
//{
//	cout << s1[i] << " ";
//}
//cout << endl;
//for (size_t i = 0; i < s2.Size(); ++i)
//{
//	cout << s2[i] << " ";
//}
//cout << endl;
