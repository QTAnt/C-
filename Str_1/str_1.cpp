#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//反转一个字符串
//class Solution{
//public:
//string reverseString(string s)
//{
//	size_t begin = 0, end = s.size() - 1;
//	while (begin<end)
//	{
//		swap(s[begin], s[end]);
//		++begin;
//		--end;
//	}
//	return s;
//}
////};
//
//int main()
//{
//	string s1="abcd wxxzcc";
//	cout << reverseString(s1) << endl;	
//	system("pause");
//	return 0;
//}
//
//int firstUniqChar(string s)
//{
//	string::iterator it = s.begin();
//
//	char c;
//	int num = 0;
//	 
//
//	while (it != s.end())
//	{
//		c = *it;
//		it++;
//		if (c== *it)
//		{
//			num++;
//		}
//		c = *it;
//		it++;
//	}
//	if (num > 0)
//		return num;
//	else
//		return -1;
//	
//}


class Solution {
public:
	void reverseString(vector<char>& s) {

		//库
		//reverse(s.begin(), s.end());

		//应用swap()
		if (s.empty())
			return;

		size_t begin = 0;
		size_t end = s.size() - 1;
		while (begin < end)
		{
			swap(s[begin], s[end];
			begin++;
			end--;
		}
	}
};

int main()
{
	string s1("allpple");
	//cout << firstUniqChar(s1) << endl;
	system("pause");
	return 0;
}