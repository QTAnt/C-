#include <iostream>
#include <string>
using namespace std;
//编一：https://www.nowcoder.com/practice/30c1674ad5694b3f8f0bc2de6f005490?tpId=8&&tqId=11019&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
//有两个32位整数n和m，请编写算法将m的二进制数位插入到n的二进制的第j到第i位, 其中二进制的位数从低位数到高位且以0开始。
//给定两个数int n和int m，同时给定int j和int i，意义如题所述，请返回操作后的数，保证n的第j到第i位均为零，且m的二进制位数小于等于i - j + 1。
//测试样例：
//1024，19，2，6
//返回：1100

//i j
//m:1024：100000000 00
//n:19 ： 10011
//要把m的二进制值插入m的第j位到第i位，只需要把n先左移j位，然后再进行或运算（|）即可。
//10000000000
//00001001100
//-------------------
//10001001100 ---->1100（十进制）


//class BinInsert {
//public:
//	int binInsert(int n, int m, int j, int i) {
//		// write code here
//		m <<= j;
//		return n | m;
//	}
//};
//*******************************************************************************
//编二：https://www.nowcoder.com/practice/98dc82c094e043ccb7e0570e5342dd1b?tpId=37&&tqId=21298&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
//题目描述
//题目标题：
//计算两个字符串的最大公共字串的长度，字符不区分大小写
//详细描述：
//接口说明
//原型：
//int getCommonStrLength(char * pFirstStr, char * pSecondStr);
//输入参数：
//char * pFirstStr //第一个字符串
//char * pSecondStr//第二个字符串
//输入描述 :
//输入两个字符串
//
//输出描述 :
//输出一个整数
//
//示例1
//输入
//复制
//asdfas werasdfaswer
//输出
//复制
//6
//int Maxsubstr(string a, string b)
//{
//	unsigned int start1, start2 ;
//	int count = 0, Max = 0 ;
//	for (unsigned int i = 0; a[i] != '\0'; i++)
//	{
//		for (unsigned int j = 0; b[j] != '\0'; j++)
//		{
//			start1 = i ;
//			start2 = j ;
//			while (a[start1] == b[start2] && start1 < a.length() && start2 < b.length())
//			{
//				start1++ ;
//				start2++ ;
//				count++ ; 
//			}
//			if (count>Max)
//			{
//				Max = count;
//			}
//			count = 0;
//		}
//	}
//	return Max;
//}
//
//int main()
//{
//	string str1, str2;
//	cin >> str1;
//	cin >> str2;
//	//不区分大小写
//	for (unsigned int i = 0; i < str1.size(); i++)
//	{
//		str1[i] = tolower(str1[i]);
//	}
//
//	for (unsigned int i = 0; i < str2.size(); i++)
//	{
//		str2[i] = tolower(str2[i]);
//	}
//
//	cout << Maxsubstr(str1, str2) << endl;
//
//	system("pause");
//	return 0;
//}
