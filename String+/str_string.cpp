#include <iostream>
#include <string>

using namespace std;

//*构造；迭代器了解；reserve，resize;c_str;find
//
//void test_string1()
//{
//	string s1("hello");     //带参的构造函数  ;  typedef basic_string<char> string;
//	string s2 = "world";    //隐式类型转换(构造+拷贝构造+优化)
//
// 	char str1[] = "string";  //7
// 	char str2[] = "中国";   //通常一个汉字是两个字节 5
//	
//	//编码集
//	char str3[5];
//	str3[0] = -42;
//	str3[1] = -48;
//	str3[2] = -71;
//	str3[3] = -7;
//	str3[4] = '\0';
//	cout << str2 << endl;
//	cout << str3 << endl;
//}
//
//void test_string2()
//{
//	string s1("hello"); //构造
//	string s2(s1);      //拷贝构造
//	string s3("world");
//	s1 = s3;            //赋值
//
//	cout << s1 << endl;        //world
//	cout << s2 << endl;        //hello
//	cout << s3 << endl;        //world
//
//	//string(const string& str, size_t pos, size_t len = npos); str的pos位置往后npoed个位置
//	string s4(s3, 2, 2);            //从对象的第2位开始取，取2位
//	cout << "s4:" << s4 << endl;    //s4:rl
//
//	string s5(s3, 2);               //从对象的第2位开始取,直到‘\0’为止
//	cout << "s5:" << s5 << endl;    //s5:rld
//
//	//取字符串的前三位
//	string path("c:\\test.c", 3);    //取字符串的前3位
//	cout << "the path is" << " " << path << endl;   //the path is c:\
//
//	//取后缀
//	string file("file.cpp");
//	string suffix(file, 4, 4);       //从对象的第4位开始取4位
//	cout << "suffix is" << " : " << suffix << endl; //suffix is : .cpp
//
//	//迭代器初始化（了解）
//    //string s6(file.begin(),file.end());
//	//cout << "s6:" << s6 << endl;     //s6: file.cpp
//	//string s7(++file.begin(), --file.end());
//	//cout << "s6:" << s7 << endl;     //s7: ile.cp（不要第一位和最后一位）
//
//}
//
//
//int main()
//{
//	/*test_string1();
//	test_string2();*/
//
//	system("pause");
//	return 0;
//}
//*************************************************************************************
//自行回忆string的三种遍历（新式for循环方法掌握不太够）
//void StrToIntl(string str1)
//{
//	int value = 0;
//	for (size_t i = 0; i < str1.size(); i++)
//	{
//		value *= 10;
//		value += str1[i] - '0';
//	}
//	cout << value << endl;
//}
//
//void StrToInt2(string str2)
//{
//	int value = 0;
//	std::string::iterator it = str2.begin();
//	while (it != str2.end())
//	{
//		value *= 10;
//		value += (*it - '0');
//		it++;
//	}
//	cout << value << endl;
//}
//
//void StrToInt3(string str3)
//{
//	int value = 0;
//	for (auto ch : str3 )
//	{
//		value *= 10;
//		value += (ch - '0');
//	}
//	cout << value << endl;
//}
//
//int main()
//{
//	StrToIntl("1234");
//	StrToInt2("5678");
//	StrToInt3("9000");
//
//	//test_string1();
//  //test_string2();
//	//test_string3();
//
//	system("pause");
//	return 0;
//}
//*************************************************************************************
////迭代器除了读数据没害可以写数据
//void StrToInt4(const string& str)
//{
//	//1.正向迭代器：可读可写
//	//2.反向迭代器：可读可写
//	//3.const迭代器：只读（正向、反向）
//	std::string::const_reverse_iterator rit = str.rbegin();    //反向迭代器
//	while (rit != str.rend())
//	{
//		cout << *rit << "";
//		++rit;
//	}
//	cout << endl;
//}
//
//void StrToInt5(const string& str)
//{
//	int value = 0;
//	//std::string::const_iterator it = str.begin();
//	auto it = str.cbegin();     //C++11,应用cbegin,cend更能明确应用的是const迭代器
//
//	while (it != str.cend())
//	{
//		//*it = '1';            //如果传入的str不用const修饰，此处it会被修改，不能正确输出6789，而输出1111；所以要用const修饰，传&
//		value *= 10;
//		value += (*it - '0');
//		++it;
//	}
//	cout << value << endl;
//}
//*************************************************************************************
//增容
//void test_string4()
//{
//	string s1("Sunday");
//	s1.push_back(' ');
//	s1.push_back('M');
//	s1.push_back('A');
//	s1.push_back('R');
//	s1.push_back('C');
//	s1.push_back('H');
//	//s1.push_back('H');
//	//s1.push_back('H');
//	//s1.push_back('H');
//	//s1.push_back('H');
//
//	cout << s1.size() << endl;       //6;12;16
//	cout << s1.length() << endl;     //6;12;16
//	cout << s1.capacity() << endl;   //15;15;31 (大约是按照2倍增容)
//	cout << s1.max_size() << endl;   //4294967294
//
//	//了解
//	//wstring ws(L"1111");             //前面的‘L’是字符串的另一种表示方式（younicode （不会写这几个字，只知道这么念））
//	//cout << ws.max_size() << endl;   //2147483646
//	//cout << ws.c_str() << endl;      //00AFF800
//
//}
//
//void test_string5()
//{
////能看出如何增容:大约按半(增容是有代价的（释放）；把原来的数据拷贝到扩容后空间里，然后释放原来的空间)
//	string s;
//
//	cout << "making s grow : \n" ;
//	s.reserve(100);   //改变容量(111),增到需要的内存大小;避免增容，提高效率
//  
//	size_t sz = s.capacity();
//	for (int i = 0; i < 100; i++)
//	{
//		s.push_back('c');
//		if (sz != s.capacity())
//		{
//			sz = s.capacity();
//			cout << "capacity changed: " << sz << '\n';
//		}
//	}
//	cout << s << endl;
//	
//}
//void test_string6()
//{
//	//s.resize(100);      
//	//改变大小（有三种情况："sz < s.size;"、"s.size < sz <s.capacity()"、"sz > s.capacity()"默认补齐空位机制）
//	//resize的作用：1>.删除数据(只保留前几位) 2>把数据个数增到想要的大小
//	string s("hello world");
//
//	s.resize(5);
//	cout << s.size() << endl;     //5
//	cout << s.capacity() << endl; //15
//
//	s.resize(14, 'a');
//	cout << s.size() << endl;     //14
//	cout << s.capacity() << endl; //15
//	cout << s << endl;            //helloaaaaaaaaa
//
//	s.resize(18, 'c');
//	cout << s.size() << endl;     //18
//	cout << s.capacity() << endl; //31
//	cout << s << endl;            //helloaaaaaaaaacccc
//}
//*************************************************************************************
//数据访问 operator[]  /operator[0];operator[s.size()-1]

//char& operator[](size_t pos)  //实现框架
//{
//	return _str[pos];
//}

//void test_string7()
//{
//	string s1("hello,world");
//	//s1[5] = '%';  //把s1的第5个位置更改为'%'
//	//cout << s1 << endl;
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		if (s1[i] == ',')   //读
//		{
//			s1[i] = '%';    //写
//		}
//	}
//	cout << s1 << endl;             //hello%world
//
//	//2.迭代器
//	std::string::iterator it = s1.begin();
//	while (it != s1.end())
//	{
//		if (*it == '%')
//			*it = ',';
//			it++;
//	}
//	cout << s1 << endl;             //hello, world
//
//
//	//3.auto
//	for (auto& ch : s1)   //要更改的话，就必须要应用引用
//	{
//		if (ch == ',')
//			ch = '%';
//	}
//	cout << s1 << endl;             //hello% world
//
//	size_t pos = s1.find('%');
//	s1[pos] = ',';
//	cout << s1 << endl;             //hello, world
//	s1.at(pos) = '%';  //更改
//	cout << s1 << endl;             //hello% world
//
//	const string s2("ell");     //const,不能修改
//}

//*************************************************************************************
////追加
//void test_string8()
//{
//	string s1("hello");
//	s1.push_back(' ');
//	s1.append("world");
//
//	cout << s1 << endl;  //hello world
//
//	//推荐应用下面的方式
//	s1 += "!!!";       //运算符重载，增强代码可读性  //调 s1.append("world");
//	s1 += '*';                                       //调s1.push_back(' ');
//	cout << s1 << endl;  //hello world
//
//	string protocol = "https://";
//	string domain = "www.baidu.com";
//
//	////string operator+(const string& s1, const string& s2)   //(实现)
//	////{
//	////	string s = s1;
//	////	s += s2;
//	////	return s;
//	////}
//
//	//string url = protocol + domain;    //临时对象，拷贝构造
//	//cout << url << endl;      //https://www.baidu.com
//
//
//	string url = protocol ; 
//	url += domain;
//	cout << url << endl;        //https://www.baidu.com
//}

//void test_string9()
//{
//	string s1("ello");
//	s1.insert(0, 1, 'h');    //在第pos位置插入1个'h'
//	cout << s1 << endl;      //hello
//
//	s1.insert(s1.begin(), 'h');//也可应用迭代器
//	cout << s1 << endl;      //hhello
//
//	s1.insert(0, "world");
//	cout << s1 << endl;       //worldhhello
//
//	s1.erase(5, 1);
//	cout << s1 << endl;       //worldhello
//}
//*************************************************************************************
//交换
//void test_string10()
//{
//	string s1("hello");
//	string s2("world");
//	s1.swap(s2);     //成员变量的交换，指针交换代价比较小
//	cout << s1 << "--" << s2 << endl;
//
//	swap(s1, s2);    //代价比较大，产生了临时对象，效率低（拷贝构造，赋值）
//	cout << s1 << "--" << s2 << endl;
//}

//*************************************************************************************
//替换 replace
//void test_string11()
//{
//	string url = "https://blog.csdn.net/TheWindRisesll";
//	url.replace(0, 5, "http");  //从第pos位置，开始数5个字符，替换//本质，挪字符，再放进去
//
//	cout << url << endl;   //对象  http://blog.csdn.net/TheWindRisesll
//
//	//c_str : C形式的string是一个字符串，以'\0'结束
//	cout << url.c_str() << endl; //字符串 http://blog.csdn.net/TheWindRisesll
//
//	printf("%s\n", url.c_str()); //输出 http://blog.csdn.net/TheWindRisesll
//	printf("%s\n", url);  //输出错误，乱码；不可读（应用printf'%s'指输出类型为char,而url是一个对象，不匹配，所以错误）
//
//	url[5] = '\0';
//	cout << url << endl;           //http: /blog.csdn.net / TheWindRisesll（cout输出是一个字符一个字符的输出，遇到'\0'不停止，输出size个字符）
//	cout << url.c_str() << endl;   //http:
//	printf("%s\n", url.c_str());   //http:（printf输出是遇到'\0'就结束）
//}
//*************************************************************************************
//substr:获得子串
//void test_string12()
//{
//	string file = "test.cpp";
//	//string suffix(file, 4, 4);
//	//cout << suffix << endl;
//	size_t pos = file.find('c');    //如果找到了返回第一次出现的位置；如果没找到，就返回npos(静态成员的一个const变量 -1)
//	if (pos != string::npos)
//	{
//		string suffix(file, pos,file.size() - pos);
//		cout << suffix << endl;   //cpp
//	}
//
//}

string getfilesuffix(const string& file)
{
	//size_t pos = file.find('.'); //返回第一次出现的位置
	size_t pos = file.rfind('.');  //返回最后一次出现的位置
	string suffix;
	if (pos != string::npos)
	{
		//suffix = file.substr(pos);	//取到最后
		suffix = file.substr(pos, file.size()-pos);//根据算出要取出的位数取
	}
	return suffix;
}
//
void test_string13()
{
	cout << getfilesuffix("test.tar.zip") << endl;   //.zip
	const string file = "test.cpp.tar.zip";
	size_t pos = file.rfind('.');  //返回最后一次出现的位置
	string suffix;
	if (pos != string::npos)
	{
		//suffix = file.substr(pos);	//取到最后
		suffix = file.substr(pos, file.size() - pos);//根据算出要取出的位数取
	}
	cout << suffix << endl;          //.zip

	size_t prevpos = file.rfind('.', pos - 1);  //返回最后一次出现的位置
	if (prevpos != string::npos)
	{
		suffix = file.substr(prevpos, pos - prevpos);//根据算出要取出的位数取
	}
	cout << suffix << endl;          //.tar

	//找域名
	string url("http://blog.csdn.net/TheWindRisesll");
	size_t start = url.find("://");
	start += 3;
	size_t finish = url.find('/', start);   //从start开始找，找到finish位置停止
	string domain = url.substr(start, finish - start);
	cout << domain << endl;
}
int main()
{
	/*StrToInt4("1234");
	StrToInt5("6789");*/

	//test_string1();
	//test_string2();
	//test_string3();
	//test_string4();
	//test_string5();
	//test_string6();
	//test_string7();
	//test_string8();
	 //test_string9();
	//test_string10();
	//test_string11();
	//test_string12();
	test_string13();

	system("pause");
	return 0;
}
