//Day_9  ��һ
//���дһ�����������������Ӻ�����������n x m�����̸��ӣ�nΪ����ĸ�������mΪ����ĸ����������Ÿ��Ա�Ե�ߴ����Ͻ��ߵ����½ǣ��ܹ��ж������߷���Ҫ�����߻�ͷ·������ֻ�����Һ������ߣ���������������ߡ�
////https://www.nowcoder.com/practice/e2a22f0305eb4f2f9846e7d644dba09b?tpId
//
//
//#include <iostream>
//using namespace std;
//
//int PSum(int m, int n)
//{
//	if (m > 1 && n > 1){
//		return PSum(m - 1, n) + PSum(m, n - 1);
//	}
//	else if ((m >= 1) && (n == 1) || (n >= 1) && (m == 1)){
//		return m + n;
//	}
//	else{
//		return 0;
//	}
//}
//
//int main()
//{
//	int m, n;
//	while (cin >> m >> n)
//	{
//		cout << PSum(m, n) << endl;
//	}
//	return 0;
//}
//*************************************************************************************
//���
//���дһ��������������������ӡ�����ʹ��+�����������������
//��������int A��B���뷵��A��B��ֵ
//
//����������
//1, 2   ; ���أ�3
//https://www.nowcoder.com/practice/e7e0d226f1e84ba7ab8b28efc6e1aebc?tpId
//class UnusualAdd {
//public:
//	int addAB(int A, int B) {
//		int sum = 0, carry = 0;
//		while (B != 0){
//			//��Ӧλ�ĺ�
//			sum = A^B;
//			//��Ӧλ�͵Ľ�λ����Ȼ�ǽ�λ����Ҫ��������һλ
//			carry = (A&B) << 1;
//			A = sum;
//			B = carry;
//		}
//		return sum;
//	}
//};