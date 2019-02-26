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


//   //C++ 输入输出
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
//	cout << a << endl;   //cout——>控制台；endl——>换行
//	cout << b << " " << c << endl;
//
//	system("pause");
//	return 0;
//}



////类和对象
//
//////类的大小
//
////  结论：一个类的大小，实际就是该类中 “成员变量”之和，当然也要进行内存对齐，注意空类的大小，空类比较特殊，编译器给了空类一个字节来唯一标识这个类
//


//class A1
//{
//public:
//	void PrintA()  //放在公共的代码段
//	{
//		  cout << _a << endl;
//}
//private:
//	char _a;  //占空间
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
//	//分配一个字节，占位，表示对象存在过
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



//class Date  //类里边不受访问限定符的限制
//{
//public:
//	void Print() //()里有隐含的this指针，Date* this,this 是一个形参
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//			
//
//		//编译时编译器解读为 ：cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
//
//	}
//	void Init(int year, int month, int day) //成员函数里边初始化(构造)  ； year存在栈上
//	{
//		_year = year;        //带斜杠‘/’的代表成员变量，予以区分
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year;  
//	int _month;
//	int _day;  //类大小12个字节
//};
//
//int main()
//{
//	//两个对象调用同一个函数，出现不同的结果
//	Date d1;
//	d1.Init(2018, 11, 10);
//	d1.Print();
//	//编译时 ：d1.Print(&d1);
//	
//
//	Date d2;
//	d2.Init(2019, 02, 24);
//	d2.Print();
//	//编译时 ：d1.Print(&d1);
//
//	//举个例子：对象为Date，应用d.Print;对象为 Date*，应用d->Print
//	Date* p = &d1;
//	//Date* p = nullptr;   //发生错误：0x0034434F 处有未经处理的异常(在 C++enter.exe 中):  0xC0000005:  读取位置 0x00000008 时发生访问冲突。
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
//	void Init(int year, int month, int day)    //应用Init初始化
//	{
//		_year = year;        //带斜杠‘/’的代表成员变量，予以区分
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
//	d2.Print();  //如果创建出对象，但是忘了调用Init()函数的话，结果会出现随机值
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





//构造函数(特殊的成员函数)——>不用Init初始化，直接被初始化 
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
//	//重载
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	//1、基本类型/内置类型
//	int _year;
//	int _month;
//	int _day;
//
//	//2、自定义类型 ( 自定义类型通过构造函数进行初始化 )
//	//默认的构造函数对自定义类型初始化；对内置类型没有
//
//	Time _t;
//};
//
//
//// 默认构造函数
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
//	//最常用：全缺省构造函数
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		//初始化
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	//~Date( )    //不写的话，年一起会自动生成一个析构函数,日期类函数不用析构函数
//	//{
//	//	//清理
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
////// 以下测试函数能通过编译吗？
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
//	~SeqList()  //析构函数
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
//	//Date d1;  //无参调用
//	//d1.Print();
//
//	//Date d2(2019, 2, 24);  //带参调用 +对象( )
//	//d2.Print();            //后构造的先析构（栈帧上），顺序相反
//
//	//SeqList sl;
//
//	Person p;
//
//	//system("pause");
//	return 0;
//}





//// 拷贝构造函数
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
//	//浅拷贝！！！
//	// d2(d1) ; d2-this，d1-d
//	//Date(const Date& d)    
//	//	//拷贝构造函数的参数只有一个且必须使用引用传参，使用传值方式会引发无穷递归调用,用引用    //最好加上 const(防止被更改)
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
//// 这里会发现下面的程序会崩溃掉？这里就需要我们以后讲的深拷贝去解决。释放了两次空间，会报错
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
//	Date d2(d1);   //拷贝构造
//	//这里d2调用的默认拷贝构造完成拷贝，d2和d1的值也是一样的
//	
//	d1.Print();
//	d2.Print();     
//
//
//	//一块空间只能释放一次
//	String s1("hello");
//	String s2(s1);
//
//
//	//system("pause");
//	//return 0;
//}





//运算符重载
// 全局的operator==
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
		//d1.operator==(d2) << (&d1,d2)         //实际上 ：&d1传给了隐含的this，d2传给了d  所以实际上就是d1与d2的比较
		return _year == d._year && _month == d._month && _day == d._day;
	}

	//d1 = d2
	//赋值运算符的重载  ！有返回值，目的是实现连续赋值
	//d1 = d1

	 //要点5. 一个类如果没有显式定义赋值运算符重载，编译器也会生成一个，完成对象按字节序的值拷贝(浅拷贝)

		//date operator=(const date& d)   //引用 ：d 为第二个d1的别名
		//{
		//	if (this != &d)            //防止自己给自己赋值。  取地址 ：this指向的是第一个d1，d为 第二个d1的别名,如果相等的话，即为“同一个”
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

////不同的域可以定义不同的变量
//bool operator==(const Date& d1, const Date& d2)   //opeartor是函数名，第一个是左操作数，第二个是右操作数
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
	////cout << operator==(d1, d2) << endl;   // 运算符优先级 ‘<<' 高于 ‘==’
	//////编译器先判断是否为自定义类型——>重载运算符？——>
	//
	////d1.operator==(d2) << (&d1,d2)         //实际上 ：&d1传给了隐含的this，d2传给了d
	//cout << d1.operator==(d2) << endl;     
	//cout << (d1==d2) << endl;
	////cout << (d1<d2) << endl;

	Date d1(2018, 11, 10);
	Date d2(2018, 11, 11);

	d1 = d2;
	//d1 = d2 = d3 ;  //连续赋值(从右往左)   d2 = d3 d2.operator


	system("pause");
	return 0;
}










