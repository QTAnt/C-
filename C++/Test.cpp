#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
//





//extern int Add(int x, int y);
//
//int main()
//{
//	int z = Add(1, 2);
//	printf("%d\n", z);
//
//	system("pause");
//	return 0;
//}


//   //C++ �������
//#include <iostream>
//using namespace std;
//int main()
//{
//	int a;
//	double b;
//	char c;
//
//	cin >> a;
//	cin >> b >> c;
//
//	cout << a << endl;   //cout����>����̨��endl����>����
//	cout << b << " " << c << endl;
//
//	system("pause");
//	return 0;
//}



////��Ͷ���
//
//////��Ĵ�С
//
////  ���ۣ�һ����Ĵ�С��ʵ�ʾ��Ǹ����� ����Ա������֮�ͣ���ȻҲҪ�����ڴ���룬ע�����Ĵ�С������Ƚ����⣬���������˿���һ���ֽ���Ψһ��ʶ�����
//


//class A1
//{
//public:
//	void PrintA()  //���ڹ����Ĵ����
//	{
//		  cout << _a << endl;
//}
//private:
//	char _a;  //ռ�ռ�
//};
//
//class A2
//{};
//
//class A3
//{
//	char _ch;
//	double _d;
//};
//
//
//int main()
//{
//	//����һ���ֽڣ�ռλ����ʾ������ڹ�
//	A1 a21;
//	A2 a22;
//
//	cout << sizeof(A1) << endl;
//	cout << sizeof(A2) << endl;
//
//	cout << sizeof(A3) << endl;
//	
//	system("pause");
//	return 0;
//}



//class Date  //����߲��ܷ����޶���������
//{
//public:
//	void Print() //()����������thisָ�룬Date* this,this ��һ���β�
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//			
//
//		//����ʱ���������Ϊ ��cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
//
//	}
//	void Init(int year, int month, int day) //��Ա������߳�ʼ��(����)  �� year����ջ��
//	{
//		_year = year;        //��б�ܡ�/���Ĵ����Ա��������������
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;  
//	int _month;
//	int _day;  //���С12���ֽ�
//};
//
//int main()
//{
//	//�����������ͬһ�����������ֲ�ͬ�Ľ��
//	Date d1;
//	d1.Init(2018, 11, 10);
//	d1.Print();
//	//����ʱ ��d1.Print(&d1);
//	
//
//	Date d2;
//	d2.Init(2019, 02, 24);
//	d2.Print();
//	//����ʱ ��d1.Print(&d1);
//
//	//�ٸ����ӣ�����ΪDate��Ӧ��d.Print;����Ϊ Date*��Ӧ��d->Print
//	Date* p = &d1;
//	//Date* p = nullptr;   //��������0x0034434F ����δ��������쳣(�� C++enter.exe ��):  0xC0000005:  ��ȡλ�� 0x00000008 ʱ�������ʳ�ͻ��
//	p->Print();
//
//
//	system("pause");
//	return 0;
//}




//class Date 
//{
//public:
//	void Print() 
//	{
//		cout << this->_year << "-" << this->_month << "-" << _day << endl;
//	}
//
//	void Init(int year, int month, int day)    //Ӧ��Init��ʼ��
//	{
//		_year = year;        //��б�ܡ�/���Ĵ����Ա��������������
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;  
//	int _month;
//	int _day;  
//};
//
//int main()
//{
//	Date d1;
//	d1.Init(2018, 11, 10);
//	d1.Print();
//
//	Date d2;
//	d2.Print();  //������������󣬵������˵���Init()�����Ļ��������������ֵ
//	d2.Init(2019, 02, 24);
//	d2.Print();
//	
//	
//	//Date* p = &d1;
//	//p->Print();
//
//
//	system("pause");
//	return 0;
//}





//���캯��(����ĳ�Ա����)����>����Init��ʼ����ֱ�ӱ���ʼ�� 
//class Time
//{
//public:
//	Time()
//	{
//		cout << "Time()" << endl;
//		_hour = _minute = _second = 0;
//	}
//
//private:
//	int _hour;
//	int _minute;
//	int _second;
//
//};
//
//
//class Date
//{
//public:
//	void Print()
//	{
//		cout << this->_year << "-" << this->_month << "-" << _day << endl;
//	}
//
//	Date()
//	{
//		//cout << "Date()" << endl;
//		_year = 2019;        
//		_month = 02;
//		_day = 24;
//	}
//
//	//����
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	//1����������/��������
//	int _year;
//	int _month;
//	int _day;
//
//	//2���Զ������� ( �Զ�������ͨ�����캯�����г�ʼ�� )
//	//Ĭ�ϵĹ��캯�����Զ������ͳ�ʼ��������������û��
//
//	Time _t;
//};
//
//
//// Ĭ�Ϲ��캯��
//class Date
//{
//public:
//		void Print()
//	{
//		cout << this->_year << "-" << this->_month << "-" << _day << endl;
//	}
//
//	//Date()
//	//{
//	//	_year = 1900;
//	//	_month = 1;
//	//	_day = 1;
//	//}
//
//	//��ã�ȫȱʡ���캯��
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		//��ʼ��
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//~Date( )    //��д�Ļ�����һ����Զ�����һ����������,�����ຯ��������������
//	//{
//	//	//����
//	//	cout << "~Date()" << endl;
//	//}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
////// ���²��Ժ�����ͨ��������
////void Test()
////{
////	Date d1;
////}
//
//class SeqList
//{
//public:
//	SeqList(size_t capacity = 10 )
//	{
//		_a = (int*)malloc(capacity * sizeof(int));
//		_size = 0;
//		_capacity = capacity;
//	}
//
//	~SeqList()  //��������
//	{
//		free(_a);
//		_a = nullptr;
//		_size = _capacity = 0;
//	}
//
//private:
//	int* _a;
//	size_t _size;
//	size_t _capacity;
//};
//
//class String
//{
//public:
//	String(const char* str = "jack")
//	{
//		_str = (char*)malloc(strlen(str) + 1);
//		strcpy(_str, str);
//	}
//
//	~String()
//	{
//		cout << "~String()" << endl;
//		free(_str);
//	}
//
//
//private:
//	char* _str;
//};
//
//class Person
//{
//private:
//	String _name;
//	int _age;
//};
//
//
//int main()
//{
//	//Date d1;  //�޲ε���
//	//d1.Print();
//
//	//Date d2(2019, 2, 24);  //���ε��� +����( )
//	//d2.Print();            //�������������ջ֡�ϣ���˳���෴
//
//	//SeqList sl;
//
//	Person p;
//
//	//system("pause");
//	return 0;
//}





//// �������캯��
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	//ǳ����������
//	// d2(d1) ; d2-this��d1-d
//	//Date(const Date& d)    
//	//	//�������캯���Ĳ���ֻ��һ���ұ���ʹ�����ô��Σ�ʹ�ô�ֵ��ʽ����������ݹ����,������    //��ü��� const(��ֹ������)
//	//{
//	//	_year = d._year;
//	//	_month = d._month;
//	//	_day = d._day;
//	//}
//	
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//
//// ����ᷢ������ĳ������������������Ҫ�����Ժ󽲵����ȥ������ͷ������οռ䣬�ᱨ��
//class String
//{
//public:
//	String(const char* str = "jack")
//	{
//		_str = (char*)malloc(strlen(str) + 1);
//		strcpy(_str, str);
//	}
//	~String()
//	{
//		cout << "~String()" << endl;
//		free(_str);
//	}
//private:
//	char* _str;
//};
//
//
//int main()
//{
//	String s1("hello");
//	String s2(s1);
//}
//
//
//int main()
//{
//	Date d1(2018,11,11);
//	Date d2(d1);   //��������
//	//����d2���õ�Ĭ�Ͽ���������ɿ�����d2��d1��ֵҲ��һ����
//	
//	d1.Print();
//	d2.Print();     
//
//
//	//һ��ռ�ֻ���ͷ�һ��
//	String s1("hello");
//	String s2(s1);
//
//
//	//system("pause");
//	//return 0;
//}





//���������
// ȫ�ֵ�operator==
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	//d1 == d2 (this,d)
	bool operator==(const Date& d)
	{
		//d1.operator==(d2) << (&d1,d2)         //ʵ���� ��&d1������������this��d2������d  ����ʵ���Ͼ���d1��d2�ıȽ�
		return _year == d._year && _month == d._month && _day == d._day;
	}

	//d1 = d2
	//��ֵ�����������  ���з���ֵ��Ŀ����ʵ��������ֵ
	//d1 = d1

	 //Ҫ��5. һ�������û����ʽ���帳ֵ��������أ�������Ҳ������һ������ɶ����ֽ����ֵ����(ǳ����)

		//date operator=(const date& d)   //���� ��d Ϊ�ڶ���d1�ı���
		//{
		//	if (this != &d)            //��ֹ�Լ����Լ���ֵ��  ȡ��ַ ��thisָ����ǵ�һ��d1��dΪ �ڶ���d1�ı���,�����ȵĻ�����Ϊ��ͬһ����
		//	{
		//		_year = d._year;
		//		_month = d._month;
		//		_day = d._day;
		//	}
		//	return *this;
		//}
	

private:
	int _year;
	int _month;
	int _day;
};

////��ͬ������Զ��岻ͬ�ı���
//bool operator==(const Date& d1, const Date& d2)   //opeartor�Ǻ���������һ��������������ڶ������Ҳ�����
//{
//	return d1._year == d2._year && d1._month == d2._month  &&  d1._day == d2._day;
//}
//
//bool operator<(const Date& d1, const Date& d2)
//{
//	return (d1._year < d2._year || ( d1._year < d2._year && d1._month < d2._month ) || ( d1._year < d2._year && d1._month < d2._month && d1._day < d2._day ) );
//
//}

int main()
{
	//Date d1,d2;
	//
	////cout << operator==(d1, d2) << endl;   // ��������ȼ� ��<<' ���� ��==��
	//////���������ж��Ƿ�Ϊ�Զ������͡���>���������������>
	//
	////d1.operator==(d2) << (&d1,d2)         //ʵ���� ��&d1������������this��d2������d
	//cout << d1.operator==(d2) << endl;     
	//cout << (d1==d2) << endl;
	////cout << (d1<d2) << endl;

	Date d1(2018, 11, 10);
	Date d2(2018, 11, 11);

	d1 = d2;
	//d1 = d2 = d3 ;  //������ֵ(��������)   d2 = d3 d2.operator


	system("pause");
	return 0;
}










