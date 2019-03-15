//Day_9  编一
//请编写一个函数（允许增加子函数），计算n x m的棋盘格子（n为横向的格子数，m为竖向的格子数）沿着各自边缘线从左上角走到右下角，总共有多少种走法，要求不能走回头路，即：只能往右和往下走，不能往左和往上走。
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
//编二
//请编写一个函数，将两个数字相加。不得使用+或其他算数运算符。
//给定两个int A和B。请返回A＋B的值
//
//测试样例：
//1, 2   ; 返回：3
//https://www.nowcoder.com/practice/e7e0d226f1e84ba7ab8b28efc6e1aebc?tpId
//class UnusualAdd {
//public:
//	int addAB(int A, int B) {
//		int sum = 0, carry = 0;
//		while (B != 0){
//			//对应位的和
//			sum = A^B;
//			//对应位和的进位，既然是进位，就要整体左移一位
//			carry = (A&B) << 1;
//			A = sum;
//			B = carry;
//		}
//		return sum;
//	}
//};