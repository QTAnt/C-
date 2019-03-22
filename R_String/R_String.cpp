//## 反转字符串
//[编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char\[\] 的形式给出。](https://leetcode-cn.com/problems/reverse-string/)
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

////##### string***********************************************************************

//class Solution {
//public:
//	string reverseString(string s) {
//		if (s.empty())
//			return string();
//
//		size_t begin = 0, end = s.size() - 1;
//		while (begin<end)
//		{
//			swap(s[begin], s[end]);
//			++begin;
//			--end;
//		}
//		return s;
//	}
//};

////##### vector***********************************************************************

//class Solution {
//public:
//	void reverseString(vector<char>& s) {
//
//		//库
//		//reverse(s.begin(), s.end());
//
//		//应用swap()
//		if (s.empty())
//			return;
//
//		size_t begin = 0;
//		size_t end = s.size() - 1;
//		while (begin < end)
//		{
//			swap(s[begin], s[end];
//			begin++;
//			end--;
//		}
//	}
//};

////##### VS***************************************************************************

//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
string reverseString(string s)
{
	size_t begin = 0, end = s.size() - 1;
	while (begin<end)
	{
		swap(s[begin], s[end]);
		++begin;
		--end;
	}
	return s;
}

int main()
{
	string s1 = "abcd wxxzcc";
	cout << reverseString(s1) << endl;
	system("pause");
	return 0;
}