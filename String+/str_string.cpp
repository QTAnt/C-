#include <iostream>
#include <string>

using namespace std;

//*���죻�������˽⣻reserve��resize;c_str;find
//
//void test_string1()
//{
//	string s1("hello");     //���εĹ��캯��  ;  typedef basic_string<char> string;
//	string s2 = "world";    //��ʽ����ת��(����+��������+�Ż�)
//
// 	char str1[] = "string";  //7
// 	char str2[] = "�й�";   //ͨ��һ�������������ֽ� 5
//	
//	//���뼯
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
//	string s1("hello"); //����
//	string s2(s1);      //��������
//	string s3("world");
//	s1 = s3;            //��ֵ
//
//	cout << s1 << endl;        //world
//	cout << s2 << endl;        //hello
//	cout << s3 << endl;        //world
//
//	//string(const string& str, size_t pos, size_t len = npos); str��posλ������npoed��λ��
//	string s4(s3, 2, 2);            //�Ӷ���ĵ�2λ��ʼȡ��ȡ2λ
//	cout << "s4:" << s4 << endl;    //s4:rl
//
//	string s5(s3, 2);               //�Ӷ���ĵ�2λ��ʼȡ,ֱ����\0��Ϊֹ
//	cout << "s5:" << s5 << endl;    //s5:rld
//
//	//ȡ�ַ�����ǰ��λ
//	string path("c:\\test.c", 3);    //ȡ�ַ�����ǰ3λ
//	cout << "the path is" << " " << path << endl;   //the path is c:\
//
//	//ȡ��׺
//	string file("file.cpp");
//	string suffix(file, 4, 4);       //�Ӷ���ĵ�4λ��ʼȡ4λ
//	cout << "suffix is" << " : " << suffix << endl; //suffix is : .cpp
//
//	//��������ʼ�����˽⣩
//    //string s6(file.begin(),file.end());
//	//cout << "s6:" << s6 << endl;     //s6: file.cpp
//	//string s7(++file.begin(), --file.end());
//	//cout << "s6:" << s7 << endl;     //s7: ile.cp����Ҫ��һλ�����һλ��
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
//���л���string�����ֱ�������ʽforѭ���������ղ�̫����
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
////���������˶�����û������д����
//void StrToInt4(const string& str)
//{
//	//1.������������ɶ���д
//	//2.������������ɶ���д
//	//3.const��������ֻ�������򡢷���
//	std::string::const_reverse_iterator rit = str.rbegin();    //���������
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
//	auto it = str.cbegin();     //C++11,Ӧ��cbegin,cend������ȷӦ�õ���const������
//
//	while (it != str.cend())
//	{
//		//*it = '1';            //��������str����const���Σ��˴�it�ᱻ�޸ģ�������ȷ���6789�������1111������Ҫ��const���Σ���&
//		value *= 10;
//		value += (*it - '0');
//		++it;
//	}
//	cout << value << endl;
//}
//*************************************************************************************
//����
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
//	cout << s1.capacity() << endl;   //15;15;31 (��Լ�ǰ���2������)
//	cout << s1.max_size() << endl;   //4294967294
//
//	//�˽�
//	//wstring ws(L"1111");             //ǰ��ġ�L�����ַ�������һ�ֱ�ʾ��ʽ��younicode ������д�⼸���֣�ֻ֪����ô���
//	//cout << ws.max_size() << endl;   //2147483646
//	//cout << ws.c_str() << endl;      //00AFF800
//
//}
//
//void test_string5()
//{
////�ܿ����������:��Լ����(�������д��۵ģ��ͷţ�����ԭ�������ݿ��������ݺ�ռ��Ȼ���ͷ�ԭ���Ŀռ�)
//	string s;
//
//	cout << "making s grow : \n" ;
//	s.reserve(100);   //�ı�����(111),������Ҫ���ڴ��С;�������ݣ����Ч��
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
//	//�ı��С�������������"sz < s.size;"��"s.size < sz <s.capacity()"��"sz > s.capacity()"Ĭ�ϲ����λ���ƣ�
//	//resize�����ã�1>.ɾ������(ֻ����ǰ��λ) 2>�����ݸ���������Ҫ�Ĵ�С
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
//���ݷ��� operator[]  /operator[0];operator[s.size()-1]

//char& operator[](size_t pos)  //ʵ�ֿ��
//{
//	return _str[pos];
//}

//void test_string7()
//{
//	string s1("hello,world");
//	//s1[5] = '%';  //��s1�ĵ�5��λ�ø���Ϊ'%'
//	//cout << s1 << endl;
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		if (s1[i] == ',')   //��
//		{
//			s1[i] = '%';    //д
//		}
//	}
//	cout << s1 << endl;             //hello%world
//
//	//2.������
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
//	for (auto& ch : s1)   //Ҫ���ĵĻ����ͱ���ҪӦ������
//	{
//		if (ch == ',')
//			ch = '%';
//	}
//	cout << s1 << endl;             //hello% world
//
//	size_t pos = s1.find('%');
//	s1[pos] = ',';
//	cout << s1 << endl;             //hello, world
//	s1.at(pos) = '%';  //����
//	cout << s1 << endl;             //hello% world
//
//	const string s2("ell");     //const,�����޸�
//}

//*************************************************************************************
////׷��
//void test_string8()
//{
//	string s1("hello");
//	s1.push_back(' ');
//	s1.append("world");
//
//	cout << s1 << endl;  //hello world
//
//	//�Ƽ�Ӧ������ķ�ʽ
//	s1 += "!!!";       //��������أ���ǿ����ɶ���  //�� s1.append("world");
//	s1 += '*';                                       //��s1.push_back(' ');
//	cout << s1 << endl;  //hello world
//
//	string protocol = "https://";
//	string domain = "www.baidu.com";
//
//	////string operator+(const string& s1, const string& s2)   //(ʵ��)
//	////{
//	////	string s = s1;
//	////	s += s2;
//	////	return s;
//	////}
//
//	//string url = protocol + domain;    //��ʱ���󣬿�������
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
//	s1.insert(0, 1, 'h');    //�ڵ�posλ�ò���1��'h'
//	cout << s1 << endl;      //hello
//
//	s1.insert(s1.begin(), 'h');//Ҳ��Ӧ�õ�����
//	cout << s1 << endl;      //hhello
//
//	s1.insert(0, "world");
//	cout << s1 << endl;       //worldhhello
//
//	s1.erase(5, 1);
//	cout << s1 << endl;       //worldhello
//}
//*************************************************************************************
//����
//void test_string10()
//{
//	string s1("hello");
//	string s2("world");
//	s1.swap(s2);     //��Ա�����Ľ�����ָ�뽻�����۱Ƚ�С
//	cout << s1 << "--" << s2 << endl;
//
//	swap(s1, s2);    //���۱Ƚϴ󣬲�������ʱ����Ч�ʵͣ��������죬��ֵ��
//	cout << s1 << "--" << s2 << endl;
//}

//*************************************************************************************
//�滻 replace
//void test_string11()
//{
//	string url = "https://blog.csdn.net/TheWindRisesll";
//	url.replace(0, 5, "http");  //�ӵ�posλ�ã���ʼ��5���ַ����滻//���ʣ�Ų�ַ����ٷŽ�ȥ
//
//	cout << url << endl;   //����  http://blog.csdn.net/TheWindRisesll
//
//	//c_str : C��ʽ��string��һ���ַ�������'\0'����
//	cout << url.c_str() << endl; //�ַ��� http://blog.csdn.net/TheWindRisesll
//
//	printf("%s\n", url.c_str()); //��� http://blog.csdn.net/TheWindRisesll
//	printf("%s\n", url);  //����������룻���ɶ���Ӧ��printf'%s'ָ�������Ϊchar,��url��һ�����󣬲�ƥ�䣬���Դ���
//
//	url[5] = '\0';
//	cout << url << endl;           //http: /blog.csdn.net / TheWindRisesll��cout�����һ���ַ�һ���ַ������������'\0'��ֹͣ�����size���ַ���
//	cout << url.c_str() << endl;   //http:
//	printf("%s\n", url.c_str());   //http:��printf���������'\0'�ͽ�����
//}
//*************************************************************************************
//substr:����Ӵ�
//void test_string12()
//{
//	string file = "test.cpp";
//	//string suffix(file, 4, 4);
//	//cout << suffix << endl;
//	size_t pos = file.find('c');    //����ҵ��˷��ص�һ�γ��ֵ�λ�ã����û�ҵ����ͷ���npos(��̬��Ա��һ��const���� -1)
//	if (pos != string::npos)
//	{
//		string suffix(file, pos,file.size() - pos);
//		cout << suffix << endl;   //cpp
//	}
//
//}

string getfilesuffix(const string& file)
{
	//size_t pos = file.find('.'); //���ص�һ�γ��ֵ�λ��
	size_t pos = file.rfind('.');  //�������һ�γ��ֵ�λ��
	string suffix;
	if (pos != string::npos)
	{
		//suffix = file.substr(pos);	//ȡ�����
		suffix = file.substr(pos, file.size()-pos);//�������Ҫȡ����λ��ȡ
	}
	return suffix;
}
//
void test_string13()
{
	cout << getfilesuffix("test.tar.zip") << endl;   //.zip
	const string file = "test.cpp.tar.zip";
	size_t pos = file.rfind('.');  //�������һ�γ��ֵ�λ��
	string suffix;
	if (pos != string::npos)
	{
		//suffix = file.substr(pos);	//ȡ�����
		suffix = file.substr(pos, file.size() - pos);//�������Ҫȡ����λ��ȡ
	}
	cout << suffix << endl;          //.zip

	size_t prevpos = file.rfind('.', pos - 1);  //�������һ�γ��ֵ�λ��
	if (prevpos != string::npos)
	{
		suffix = file.substr(prevpos, pos - prevpos);//�������Ҫȡ����λ��ȡ
	}
	cout << suffix << endl;          //.tar

	//������
	string url("http://blog.csdn.net/TheWindRisesll");
	size_t start = url.find("://");
	start += 3;
	size_t finish = url.find('/', start);   //��start��ʼ�ң��ҵ�finishλ��ֹͣ
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
