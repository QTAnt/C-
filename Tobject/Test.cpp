#include <iostream>


//��ע�⡿
//
//1. ÿ����Ա�����ڳ�ʼ���б���ֻ�ܳ���һ��(��ʼ��ֻ�ܳ�ʼ��һ��)
//2. ���а������³�Ա��������ڳ�ʼ���б�λ�ý��г�ʼ����
//
//* ���ó�Ա����
//* const��Ա����
//* �����ͳ�Ա(����û��Ĭ�Ϲ��캯��)

//class A
//{
//public:
//	A(int a = 0)      
//		:_a(a)
//	{}
//
//private:
//	int _a;
//};
//
//class B
//{
//	
//public:             //��ʼ���б��ǳ�Ա����ĵط�
//	B(int ref = 0)
//		:_ref(ref)
//		, _n(10)    //n��const�������һ��ֵ��û��ֵ���಻��
//		, _a(0)
//	{}
//	                //���ܻῼѡ���⣨�����ĸ�����಻����
//private:            //����
//	int & _ref;     //����
//	const int _n;   //const����
//	A _a;           //������  Ҫ����_a�Ĺ��캯����ʼ���б�;����_a�Ĺ��캯��
//};
//
//
//int main()
//{
//	B b;
//
//	system("pause");
//	return 0;
//}


//3������ʹ�ó�ʼ���б��ʼ������Ϊ�������Ƿ�ʹ�ó�ʼ���б������Զ������ͳ�Ա������һ������ʹ�ó�ʼ���б��ʼ��
//class Time
//{
//public:
//	 Time(int hour = 0)
//		:_hour(hour)
//	{
//		cout << "Time()" << endl;
//	}
//	Time(const Time& t)
//	{
//		cout <<"Time(const Time& t)" << endl;
//	}
//
//private:
//	int _hour;
//};
//
//class Date
//{
//public:
//	Date(int day)
//		:_t(10)
//	{}
//
//private:
//	int _day;
//	Time _t;
//};
//
//class Array
//{
//public:
//	Array(int size)
//		:_size(size)
//		, _array((int*)malloc(sizeof(int)*_size))
//		//4. ��Ա������������������������ڳ�ʼ���б��еĳ�ʼ��˳�������ڳ�ʼ���б��е��Ⱥ�����޹�  ���� _size�Ĵ�СΪ10������Array
//	{}
//
//private:
//	int* _array;
//	int _size;
//};
//
////�����⣺ʵ��һ���࣬�����г����д������˶��ٸ������**********************************
//
////int n = 0;       //ͨ�����������˶��ٴκ������ɵô��������Ŀ(ȱ�ݣ�Υ�����������ķ�װ)�Ľ�����>���óɾ�̬�� static
//class A
//{
//public:
//	A()
//	{
//		++n;
//		cout << "A()" << endl;
//	}
//
//	A(const A& a)
//	{ 
//		++n;
//		cout << "A(const A& a)" << endl;
//	}
//	//˽�е�Ҫ�������н��з��ʣ���Ҫͨ��һ�����еĳ�Ա����
//	static int Getn()   //���������� ; û��thisָ��
//	{
//		//m = 10;  //���ܷ���m,����m��Ҫthisָ��
//		return n;
//	}
//
//private:
//	static int n;     //���������� 
//	int m;
//};
//
////��̬��Ա�ĳ�ʼ���������ʼ����������������
//int A::n = 0;
//
//
//A f(A a)
//{
//	return a;  //��ֵ���أ�����a,��Ҫ��������һ�� ����> 4����
//}
//
////A& f(A a)
////{
////	return a;  ///�����÷��أ����ص��Ǳ���   ����> 3����
////}
//
//int main()
//{
//	/*Date d(1);
//	Array a(10);*/
//
//	Time t1(10);   //����
//	Time t2 = 20;   //����ת��  ���� + �������� + �Ż� == ����
//	
//	//Time t2 = 20; ����>����(����)
//	//��53������ӡ�explicit������ᱨ��(����)�� �����������֣��Ͳ��üӡ�explicit��
//	//��explicit���ι��캯���������ֹ���ι��캯������ʽת��;�����ڵ������Ĺ��캯��
//	//����	1	error C2440: ����ʼ����: �޷��ӡ�int��ת��Ϊ��Time��	f:\code\c++\��\tobject\tobject\test.cpp	99	1	Tobject  ��   	2	IntelliSense:  �����ڴ� "int" ת���� "Time" ���ʵ����캯��	f:\CODE\C++\��\Tobject\Tobject\Test.cpp	99	12	Tobject
//
//	A a1;
//	A a2;
//	f(a1);
//
//	cout << a1.Getn() << endl;
//	cout << a2.Getn() << endl;
//	
//
//	////static int n;   //���������� 
//	////int m;
//	//////�������������ж���Ϊ����ʱ������a1.n,a2.n�ĵ�ַ��һ����,a1.m,a2.m�ĵ�ַ��һ��
//	//cout << &a1.n << endl;   //00330320
//	//cout << &a2.n << endl;   //00330320
//	//cout << &a1.m << endl;   //00AFFA70
//	//cout << &a2.m << endl;   //00AFFA64
//
//
//	cout << A::Getn() << endl;
//
//	system("pause");
//}
//
////ȫ��û�з�װ�ĸ���



//////C++11 �ĳ�Ա��ʼ�����淨**************************************************************
//class B
//{
//public:
//	B(int b = 0)
//		:_b(b)
//	{}
//	int _b;
//};
//class A
//{
//public:
//	A()
//		:a(100)
//	{}
//
//	void Print()
//	{
//		cout << a << endl;
//		cout << b._b << endl;
//		cout << p << endl;
//	}
//
//private:
//	// �Ǿ�̬��Ա�����������ڳ�Ա����ʱ��ֱ�ӳ�ʼ��
//	//ȱʡֵ
//	int a = 10;    //�������a(100),���Խ���� a = 100 ;����� a = 10;��ȱʡֵ(��̥)
//	B b = 20;   //ȱʡֵ
//	int* p = (int*)malloc(4);   
//	static int n;    //��̬��Ա���������������ʼ��
//};
//
//int A::n = 10;
//
//int main()
//{
//	A a;
//	a.Print();
//	
//
//	system("pause");
//	return 0;
//}

//
////***********************************��ϰǰ��*************************************
//class Date
//{
//public:
//	//Date d1(2018);      //ֱ�ӹ���
//	Date(int year)          
//		: _year(year)
//	{
//		cout << "Date(int year)" << endl;
//	}
//
//	//Date d2 = d1;       //��������
//	Date(const Date& d)       
//	{
//		cout << "Date(const Date& d)" << endl;
//	}
//
//	//d1 = 2020;          //���� + ��ֵ
//	Date& operator=(const Date& d)   
//	{
//		cout << "Date& operator=(const Date& d)" << endl;
//		return *this;
//	}
//
//
//	//ostream& operator<<(ostream& _cout)
//	//{
//	//	_cout << d._year << "-" << d._month << "-" << d._day;
//	//	return _cout;
//	//}
//
//private:
//	int _year;
//	
//};
//
//int main()
//{
//	Date d1(2018);      //ֱ�ӹ���
//	Date d2 = 2019;     //��ʽ����ת��  ������ʱ���� + �������� + �Ż� == ���죨�ȹ���һ����ʱ����2019��
//
//	d1 = 2020;          //���� + ��ֵ
//
//	system("pause");
//	return 0;
//


