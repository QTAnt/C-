//问题描述：在计算机中，通配符一种特殊语法，广泛应用于文件搜索、数据库、正则表达式等领域。现要求各位实现字符串通配符的算法。
//要求：
//实现如下2个通配符：
//*：匹配0个或以上的字符（字符由英文字母和数字0 - 9组成，不区分大小写。下同）
//？：匹配1个字符
//输入：
//通配符表达式；
//一组字符串。
//输出：
//返回匹配的结果，正确输出true，错误输出false
//https://www.nowcoder.com/practice/43072d50a6eb44d2a6c816a283b02036?tpId=37&&tqId=21294&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking

#include <iostream>
#include <string>
using namespace std;

bool match(const char* original, const char *str)
{
	//当前字符结束，返回true
	if (*original == '\0' && *str == '\0')
		return true;
	//两个字符串有一个先结束，则返回false
	if (*original == '\0' || *str == '\0')
		return false;
	if (*original == '?')
	{
		//遇到?号，匹配一个字符，跳过一个位置
		return match(original + 1, str + 1);
	}
	else if (*original == '*')
	{
		// 遇到*号，匹配0个(str不挪动)，1个（两者都向前挪动一个字符）或多个(str向前挪动一个字符)
		return match(original + 1, str) || match(original + 1, str + 1) || match(original, str + 1);
	}
	else if (*original == *str)
	{
		//如果当前字符相等，匹配下一个字符
		return match(original + 1, str + 1);
	}
	return false;
}

int main()
{
	string original, str;
	while (cin >> original >> str)
	{
		bool ret = match(original.c_str(), str.c_str());
		if (ret)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}