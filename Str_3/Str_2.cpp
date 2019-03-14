//[验证回文串](https://leetcode-cn.com/problems/valid-palindrome/submissions/)
#include <iostream>
#include <string>
class Solution {
public:
	bool isLetterOrNumber(char ch){
		return (ch >= '0' && ch <= '9')
			|| (ch >= 'a' && ch <= 'z')
			|| (ch >= 'A' && ch <= 'Z');//其中一个为真，就为真
	}

	bool isPalindrome(string s) {
		//两边同时往中间走(遍历)，应用闭区间
		int begin = 0, end = s.size() - 1;
		while (begin < end)
		{
			while (begin < end && !isLetterOrNumber(s[begin]))  //如果不是字母或者字符，就略过，继续往后找
				++begin;

			while (begin < end && !isLetterOrNumber(s[end]))  //如果不是字母或者字符，就略过，继续往前找
				--end;

			//if(s[begin]%32 != s[end]%32)
			if ((s[begin] + 32 - 'a') % 32 != (s[end] + 32 - 'a') % 32)
			{
				return false;
			}
			else
			{
				++begin;
				--end;
			}

		}
		return true;
	}

};
