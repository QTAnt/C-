#include <iostream>


//【注意】
//
//1. 每个成员变量在初始化列表中只能出现一次(初始化只能初始化一次)
//2. 类中包含以下成员，必须放在初始化列表位置进行初始化：
//
//* 引用成员变量
//* const成员变量
//* 类类型成员(该类没有默认构造函数)

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
//public:             //初始化列表是成员定义的地方
//	B(int ref = 0)
//		:_ref(ref)
//		, _n(10)    //n是const，必须给一个值，没有值，编不过
//		, _a(0)
//	{}
//	                //可能会考选择题（以下哪个代码编不过）
//private:            //声明
//	int & _ref;     //引用
//	const int _n;   //const类型
//	A _a;           //类类型  要调用_a的构造函数初始化列表;调用_a的构造函数
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


//3、尽量使用初始化列表初始化，因为不管你是否使用初始化列表，对于自定义类型成员变量，一定会先使用初始化列表初始化
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
//		//4. 成员变量在类中声明次序就是其在初始化列表中的初始化顺序，与其在初始化列表中的先后次序无关  所以 _size的大小为10，并非Array
//	{}
//
//private:
//	int* _array;
//	int _size;
//};
//
////面试题：实现一个类，计算中程序中创建出了多少个类对象**********************************
//
////int n = 0;       //通过计数调用了多少次函数，可得创建类的数目(缺陷：违背了面向对象的封装)改进——>设置成静态的 static
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
//	//私有的要能在类中进行访问，需要通过一个公有的成员函数
//	static int Getn()   //属于整个类 ; 没有this指针
//	{
//		//m = 10;  //不能访问m,访问m需要this指针
//		return n;
//	}
//
//private:
//	static int n;     //属于整个类 
//	int m;
//};
//
////静态成员的初始化（类外初始化，但是属于类域）
//int A::n = 0;
//
//
//A f(A a)
//{
//	return a;  //传值返回，返回a,还要拷贝构造一个 ——> 4个类
//}
//
////A& f(A a)
////{
////	return a;  ///传引用返回，返回的是别名   ——> 3个类
////}
//
//int main()
//{
//	/*Date d(1);
//	Array a(10);*/
//
//	Time t1(10);   //构造
//	Time t2 = 20;   //类型转换  构造 + 拷贝构造 + 优化 == 构造
//	
//	//Time t2 = 20; ——>解析(如下)
//	//第53行如果加“explicit”，则会报错(如下)； 避免该问题出现，就不用加“explicit”
//	//用explicit修饰构造函数，将会禁止单参构造函数的隐式转换;适用于单参数的构造函数
//	//错误	1	error C2440: “初始化”: 无法从“int”转换为“Time”	f:\code\c++\课\tobject\tobject\test.cpp	99	1	Tobject  ；   	2	IntelliSense:  不存在从 "int" 转换到 "Time" 的适当构造函数	f:\CODE\C++\课\Tobject\Tobject\Test.cpp	99	12	Tobject
//
//	A a1;
//	A a2;
//	f(a1);
//
//	cout << a1.Getn() << endl;
//	cout << a2.Getn() << endl;
//	
//
//	////static int n;   //属于整个类 
//	////int m;
//	//////以上两行在类中定义为公有时，下面a1.n,a2.n的地址是一样的,a1.m,a2.m的地址不一样
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
////全局没有封装的概念



//////C++11 的成员初始化新玩法**************************************************************
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
//	// 非静态成员变量，可以在成员声明时，直接初始化
//	//缺省值
//	int a = 10;    //上面给了a(100),所以结果是 a = 100 ;这里的 a = 10;是缺省值(备胎)
//	B b = 20;   //缺省值
//	int* p = (int*)malloc(4);   
//	static int n;    //静态成员变量必须在类外初始化
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
////***********************************复习前面*************************************
//class Date
//{
//public:
//	//Date d1(2018);      //直接构造
//	Date(int year)          
//		: _year(year)
//	{
//		cout << "Date(int year)" << endl;
//	}
//
//	//Date d2 = d1;       //拷贝构造
//	Date(const Date& d)       
//	{
//		cout << "Date(const Date& d)" << endl;
//	}
//
//	//d1 = 2020;          //构造 + 赋值
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
//	Date d1(2018);      //直接构造
//	Date d2 = 2019;     //隐式类型转换  构造临时对象 + 拷贝构造 + 优化 == 构造（先构造一个临时对象2019）
//
//	d1 = 2020;          //构造 + 赋值
//
//	system("pause");
//	return 0;
//


