#include <iostream>
#include <string>
using namespace std;
//��һ��https://www.nowcoder.com/practice/30c1674ad5694b3f8f0bc2de6f005490?tpId=8&&tqId=11019&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
//������32λ����n��m�����д�㷨��m�Ķ�������λ���뵽n�Ķ����Ƶĵ�j����iλ, ���ж����Ƶ�λ���ӵ�λ������λ����0��ʼ��
//����������int n��int m��ͬʱ����int j��int i�����������������뷵�ز������������֤n�ĵ�j����iλ��Ϊ�㣬��m�Ķ�����λ��С�ڵ���i - j + 1��
//����������
//1024��19��2��6
//���أ�1100

//i j
//m:1024��100000000 00
//n:19 �� 10011
//Ҫ��m�Ķ�����ֵ����m�ĵ�jλ����iλ��ֻ��Ҫ��n������jλ��Ȼ���ٽ��л����㣨|�����ɡ�
//10000000000
//00001001100
//-------------------
//10001001100 ---->1100��ʮ���ƣ�


//class BinInsert {
//public:
//	int binInsert(int n, int m, int j, int i) {
//		// write code here
//		m <<= j;
//		return n | m;
//	}
//};
//*******************************************************************************
//�����https://www.nowcoder.com/practice/98dc82c094e043ccb7e0570e5342dd1b?tpId=37&&tqId=21298&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
//��Ŀ����
//��Ŀ���⣺
//���������ַ�������󹫹��ִ��ĳ��ȣ��ַ������ִ�Сд
//��ϸ������
//�ӿ�˵��
//ԭ�ͣ�
//int getCommonStrLength(char * pFirstStr, char * pSecondStr);
//���������
//char * pFirstStr //��һ���ַ���
//char * pSecondStr//�ڶ����ַ���
//�������� :
//���������ַ���
//
//������� :
//���һ������
//
//ʾ��1
//����
//����
//asdfas werasdfaswer
//���
//����
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
//	//�����ִ�Сд
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
