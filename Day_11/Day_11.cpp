//有一棵无穷大的满二叉树，其结点按根结点一层一层地从左往右依次编号，根结点编号为1。现在有两个结点a，b。请设计一个算法，求出a和b点的最近公共祖先的编号。给定两个int a, b。为给定结点的编号。请返回a和b的最近公共祖先的编号。注意这里结点本身也可认为是其祖先。
//测试样例：2，3返回：1
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
//编二：
//https://www.nowcoder.com/practice/70e00e490b454006976c1fdf47f155d9?tpId=8&&tqId=11017&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
//功能: 求一个byte数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1
//输入 : 一个byte型的数字
// 输出 : 无
//  返回 : 对应的二进制数字中1的最大连续数
//   输入描述 : 输入一个byte数字输出描述 : 输出转成二进制之后连续1的个数
//		  根据位运算，获取每一位的二进制值
//		  获取第i位的值：(n >> i) & 1
//		  好奇怪哦，这道题在VS下是正确的，但是在OJ下通过率为0.00%（烦人），怪怪的

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	int n;
//	//获取第i位的值： (n >> i) & 1
//	while (cin >> n)
//	{
//		int num = 0;
//		int Tmax = 0;
//		while (n)
//		{
//			if (n & 1)
//			{
//				num++;
//				Tmax = max(num, Tmax);  //此处自己实现也是过不了
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
//**********************这个是别人的代码，能通过的(我觉得跟我自己的没差鸭，怪怪)
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