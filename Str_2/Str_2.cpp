//输入描述:
//输入一个非空字符串
//输出描述 :
//输出第一个只出现一次的字符，如果不存在输出 - 1
//#include <iostream>
//#include <string>
//using namespace std;
//
//int firstUniqChar(string s) {
//
//	int count[26] = { 0 };
//	for (int i = 0; i < s.size(); i++){
//			count[s[i] - 'a'] ++;         //遍历字符串，记录出现字符的次数
//	}
//
//	for (int i = 0; i < s.size(); i++){
//		if (1 == count[s[i] - 'a']){   //如果字符出现次数为1，则返回该位置i;否则返回-1
//				return i;
//		}
//			return -1;
//	}
//}
////法一
////int main()
////{
////	string s;
////	getline(cin, s);
////	int re = firstUniqChar(s);
////	if (re == -1)
////		cout << re << endl;
////	else
////		cout << s[re] << endl;
////
////	system("pause");
////	return 0;
////}
////法二
//int main()
//{
//	string str;
//	while (cin >> str)
//	{
//		int re = firstUniqChar(str);
//		if (re == -1)
//		{
//			cout << re << endl;
//		}
//		else
//			cout << str[re] << endl;
//	}
//	return 0;
//}
//*************************************************************************************
//计算字符串最后一个单词的长度，单词以空格隔开。
//一行字符串，非空，长度小于5000。
//
//输出描述 :
//整数N，最后一个单词的长度。
//<法一>
//#include <iostream>
//#include <string>
//using namespace std;

//int main()
//{
//	string cs;
//	getline(cin, cs);//输入一行
//	int count = 0;
//	string::reverse_iterator rit = cs.rbegin();
//	while (rit != cs.rend())
//	{
//		if (*rit == ' ')
//		{
//			break;
//		}
//		else{
//			rit++;
//			count++;
//		}
//	}
//	cout << count << endl;
//	system("pause");
//}
////<法二>
//#include <iostream>
//#include <string>
//using namespace std;
//
////找空格
//int main()
//{
//	//输入流：多项时可以根据换行分隔，还可以是空格
//	//缓冲区等待
//	//istream 是 cin的类型，cin是一个对象 istream& getline (istream& is, string& str)：
//	string s;
//	//while(cin>>s)   不要使用 cin>>s，因为它遇到空格、换行，都会结束，进入下一行，留在缓冲区
//	//getline 遇到 换行才结束，假若字符串中带有空格仍然能按正常处理（建议使用 getline）
//	while (getline(cin, s))     ///持续接收
//	{
//		size_t pos = s.rfind(' ');
//		cout << s.size() - pos - 1 << endl;  //要考虑没有找到的情况
//	}
//	return 0;
//}
//int main()
//{
//	string cs;
//	while (getline(cin, cs))//持续接收
//	{
//		size_t pos = cs.rfind(' ');
//		cout << cs.rfind() - pos << endl;
//	}
//	return 0;
//}