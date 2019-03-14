//[��֤���Ĵ�](https://leetcode-cn.com/problems/valid-palindrome/submissions/)
#include <iostream>
#include <string>
class Solution {
public:
	bool isLetterOrNumber(char ch){
		return (ch >= '0' && ch <= '9')
			|| (ch >= 'a' && ch <= 'z')
			|| (ch >= 'A' && ch <= 'Z');//����һ��Ϊ�棬��Ϊ��
	}

	bool isPalindrome(string s) {
		//����ͬʱ���м���(����)��Ӧ�ñ�����
		int begin = 0, end = s.size() - 1;
		while (begin < end)
		{
			while (begin < end && !isLetterOrNumber(s[begin]))  //���������ĸ�����ַ������Թ�������������
				++begin;

			while (begin < end && !isLetterOrNumber(s[end]))  //���������ĸ�����ַ������Թ���������ǰ��
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
