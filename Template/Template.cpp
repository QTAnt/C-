#include <iostream>
using namespace std;

//����ģ���ʽ  template<typename T1, typename T2,......,typename Tn>

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
////����ģ��ʵ����(��ʽ)
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
//	����䲻��ͨ�����룬��Ϊ�ڱ����ڼ䣬��������������ʵ����ʱ����Ҫ������ʵ������
//	ͨ��ʵ��a1��T����Ϊint��ͨ��ʵ��d1��T����Ϊdouble���ͣ���ģ������б���ֻ��һ��T��
//	�������޷�ȷ���˴����׸ý�Tȷ��Ϊint ���� double���Ͷ�����
//	ע�⣺��ģ���У�������һ�㲻���������ת����������Ϊһ��ת�������⣬����������Ҫ���ڹ�
//	Add(a1, d1);
//	*/
//
//	// ��ʱ�����ִ���ʽ��1. �û��Լ���ǿ��ת�� 
//	//Add(a1, (int)d1);
//
//	//2. ʹ����ʽʵ����
//	//Add<int>(a2, d2)
//
//	//���
//	//cout << Add(a1, (int)d1) << endl;
//	//cout << Add<int>(a2, d2) << endl;
//	system("pause");
//	return 0;
//}


////����ģ����ʾʵ����
//int main(void)
//{
// int a = 10;
// double b = 20.0;
// 
// // ��ʽʵ����
// cout<< Add<int>(a, b) <<endl;
// system("pause");
// return 0;
//}

//*************************************************************************************
//ģ�������ƥ��ԭ�����ֳɵľ�����ʹ���ֳɵ�

//int Add(int left, int right)
//{
//	return left + right;
//}

 //ͨ�üӷ�����
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
//	Add(1, 2); // ���ģ�庯��ƥ�䣬����������Ҫ�ػ�
//	cout << Add(1, 2) << endl;
//	//cout << Add<int>(1, 2) << endl; // ���ñ������ػ���Add�汾
//
//	system("pause");
//	return 0;
//}

//*************************************************************************************
// ר�Ŵ���int�ļӷ�����
//int Add(int left, int right)
//{
//	return left + right;
//}
//// ͨ�üӷ�����
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//
//int main()
//{
//	Add(1, 2); // ��Ǻ���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ����
//	cout << Add(1, 2.0) << endl; // ģ�庯���������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���Add����
//	system("pause");
//	return 0;
//}
//
//
//************************************************************************************* 
//template<class T1, class T2, ..., class Tn>
//class ��ģ����
//{
//	// ���ڳ�Ա����
//}; 
//
////��̬˳���
#include <assert.h>
template<class T>   //ģ�����
class Vector
{
public:
	Vector(size_t capacity = 10)
		: _array(new T[capacity])   //�������Ͳ�ȷ������T��()�����ǳ�ʼ����[]������
		, _size(0)
		, _capacity(capacity)
	{}

	// ʹ������������ʾ�������������������ⶨ�塣
	~Vector()
	{
		if (_array)
		{
			delete[] _array;
			_array = nullptr;
			_size = _capacity = 0;
		}
	}

	//��������
	//void PushBack(SeqList* ps, DataType x);   //C����
	void PushBack(const T& x)    //��ʽ��thisָ�� void PushBack(Vector<int>* this,const T& x)
	{
		//����
		_array[_size] = x;
		++_size;
	}
	size_t Size()
	{
		return _size;
	}

	//T operator[](size_t pos)   
	//{
	//	assert(pos < _size);   //��ֹԽ��
	//	return _array[pos];
	//}

	T& operator[](size_t pos)
	{
		assert(pos < _size);   //��ֹԽ��
		return _array[pos];
	}

private:
	T* _array;
	size_t _size;
	size_t _capacity;
};

void Func(Vector<int>& v)//���ܼ�const��const���ܵ���const
{
	for (size_t i = 0; i < v.Size(); ++i)
	{
		cout << v[i] << " ";
	}
}
int main()
{
	Vector<int> v1;   //����������

	//PushBack(&s1, 1);   //C����
	v1.PushBack(1);     //v1.PushBack(&v1,1);
	v1.PushBack(2);    
	v1.PushBack(3);     
	v1.PushBack(4);     

	Func(v1);

	for (size_t i = 0; i < v1.Size(); ++i)
	{
		//ż������2��
		if (v1[i] % 2 == 0)
		{
			v1[i] *= 2;   //��������ر��������򻯵�һ��д��
			v1.operator[](i) *= 2;//��������(��������ֵ)
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
// ע�⣺��ģ���к�������������ж���ʱ����Ҫ��ģ������б�

////***********************************************************************************
////��ģ���ʵ����
////��ģ��ʵ�����뺯��ģ��ʵ������ͬ����ģ��ʵ������Ҫ����ģ�����ֺ��<>��Ȼ��ʵ���������ͷ���<>�м��ɣ���ģ�����ֲ����������࣬��ʵ�����Ľ�������������ࡣ
//
////// Vector������Vector<int>��������
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
