//��һ���������������������㰴�����һ��һ��ش����������α�ţ��������Ϊ1���������������a��b�������һ���㷨�����a��b�������������ȵı�š���������int a, b��Ϊ�������ı�š��뷵��a��b������������ȵı�š�ע�������㱾��Ҳ����Ϊ�������ȡ�
//����������2��3���أ�1
//https://www.nowcoder.com/practice/70e00e490b454006976c1fdf47f155d9?tpId=8&&tqId=11017&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
//#include <iostream>
////#include <alogrithm>
//using namespace std;

//class LCA {
//public:
//	int getLCA(int a, int b)
//	{
//		while (a != b)
//		{
//			if (a > b)
//			{
//				//a = (a / 2);
//				a /= 2;
//			}
//			else
//				//b = (b / 2);
//			    b /= 2;
//		}
//		return a;
//	}
//};
//
//int main()
//{
//	LCA l1;
//	l1.getLCA( 2, 7);
//
//	system("pause");
//	return 0;
//}
//*************************************************************************************
//�����
//https://www.nowcoder.com/practice/70e00e490b454006976c1fdf47f155d9?tpId=8&&tqId=11017&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
//����: ��һ��byte���ֶ�Ӧ�Ķ�����������1�����������������3�Ķ�����Ϊ00000011���������2��1
//���� : һ��byte�͵�����
// ��� : ��
//  ���� : ��Ӧ�Ķ�����������1�����������
//   �������� : ����һ��byte����������� : ���ת�ɶ�����֮������1�ĸ���
//		  ����λ���㣬��ȡÿһλ�Ķ�����ֵ
//		  ��ȡ��iλ��ֵ��(n >> i) & 1
//		  �����Ŷ���������VS������ȷ�ģ�������OJ��ͨ����Ϊ0.00%�����ˣ����ֵֹ�

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	int n;
//	//��ȡ��iλ��ֵ�� (n >> i) & 1
//	while (cin >> n)
//	{
//		int num = 0;
//		int Tmax = 0;
//		while (n)
//		{
//			if (n & 1)
//			{
//				num++;
//				Tmax = max(num, Tmax);  //�˴��Լ�ʵ��Ҳ�ǹ�����
//			}
//			else
//				num = 0;
//
//		//n = n >> 1;
//			n >>= 1;
//		}
//
//		cout << Tmax << endl;
//		system("pause");
//		return 0;
//	}
//}
//**********************����Ǳ��˵Ĵ��룬��ͨ����(�Ҿ��ø����Լ���û��Ѽ���ֹ�)
//#include <iostream>
//using namespace std;
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		int count = 0, max = 0;
//		while (n)
//		{
//			if (n & 1)
//			{
//				count++;
//				if (max<count)
//				{
//					max = count;
//				}
//			}
//			else
//				count = 0;
//			n >>= 1;
//		}
//		cout << max << endl;
//	}
//	return 0;
//}