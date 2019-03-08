#include <iostream>
#include <string>   //字符串
#include <vector>   //顺序表（数组）
#include <list>     //链表

using namespace std;

void test_string1()
{
	string s1("hello");     //带参的构造函数  ;  typedef basic_string<char> string;
	string s2 = "world";

	char str1[] = "string";  //7
	char str2[] = "财大";   //通常一个汉字是两个字节 5
	
	//编码集
	char str3[5];
	str3[0] = -78;
	str3[1] = -56;
	str3[2] = -76;
	str3[3] = -13;
	str3[4] = '\0';
	cout << str3 << endl;
}

void test_string2()
{
	string s1("hello"); //构造
	string s2(s1);      //拷贝构造
	string s3("world");
	s1 = s3;            //赋值

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;

	//string(const string& str, size_t pos, size_t len = npos); str的pos位置往后npoed个位置
	//string s4(s3, 2, 3);

	//去后缀
	string file("file.cpp");
	string suffix(file, 4, 4);
	cout << suffix << endl;

	string path("c:\\test.c", 3);
	cout << path << endl;

	//cout << s4 << endl;
}

//1、遍历字符串
//数组遍历用[]
//把"1234"转换成整形
//<1>***********************************************************
//int StrToIntl(string str)
//{
//	int value = 0;
//	for (size_t i = 0; i < str.size(); ++i)
//	{
//		//实现打印
//		//cout << str[i] << " ";
//		//cout << str.operator[](i) << " ";  //等价上一行 operator[]是函数;(i)是参数；访问底层数组的第i个字符
//
//		value *= 10;
//		value += str[i] - '0';   //运算符重载，函数调用
//	}
//	return value;
//}

//<2>迭代器************************************************************
//int StrToInt2(string str)
//{
//	int value = 0;
//	//在stl中的迭代器(可想象成指针)：不破坏封装的情况下去访问容器
//	string::iterator it = str.begin();   //1234
//	while (it != str.end())
//	{
//		value *= 10;
//		value += (*it - '0');
//		++it;
//	}
//
//	//vector<int> v;               //1 2 3
//	//v.push_back(1);
//	//v.push_back(2);
//	//v.push_back(3);
//	//vector<int>::iterator vit = v.begin();
//	//while (vit != v.end())
//	//{
//	//	cout << *vit << " ";
//	//	++vit;
//	//}
//	//cout << endl;
//
//	//list<int> l;                  //10 20 30
//	//l.push_back(10);
//	//l.push_back(20);
//	//l.push_back(30);
//	//list<int>::iterator lit = l.begin();
//	//while (lit != l.end())
//	//{
//	//	cout << *lit << " ";
//	//	++lit;
//	//}
//	//cout << endl;
//
//	return value;
//}

//<3>******************************************************************
int StrToInt3(string str)
{
	int value = 0;
	//C++11
	for (auto ch : str)
	{
		value *= 10;
		value += (ch - '0');
	}
	return value;
}

void test_string3()
{
	//cout << StrToIntl("1234")<< endl;
	//cout << StrToInt2("1234") << endl;
	cout << StrToInt3("1234") << endl;

}

int main()
{
	//test_string1();
	//test_string2();
	test_string3();

	system("pause");
	return 0;
}