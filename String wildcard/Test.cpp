//�����������ڼ�����У�ͨ���һ�������﷨���㷺Ӧ�����ļ����������ݿ⡢������ʽ��������Ҫ���λʵ���ַ���ͨ������㷨��
//Ҫ��
//ʵ������2��ͨ�����
//*��ƥ��0�������ϵ��ַ����ַ���Ӣ����ĸ������0 - 9��ɣ������ִ�Сд����ͬ��
//����ƥ��1���ַ�
//���룺
//ͨ������ʽ��
//һ���ַ�����
//�����
//����ƥ��Ľ������ȷ���true���������false
//https://www.nowcoder.com/practice/43072d50a6eb44d2a6c816a283b02036?tpId=37&&tqId=21294&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking

#include <iostream>
#include <string>
using namespace std;

bool match(const char* original, const char *str)
{
	//��ǰ�ַ�����������true
	if (*original == '\0' && *str == '\0')
		return true;
	//�����ַ�����һ���Ƚ������򷵻�false
	if (*original == '\0' || *str == '\0')
		return false;
	if (*original == '?')
	{
		//����?�ţ�ƥ��һ���ַ�������һ��λ��
		return match(original + 1, str + 1);
	}
	else if (*original == '*')
	{
		// ����*�ţ�ƥ��0��(str��Ų��)��1�������߶���ǰŲ��һ���ַ�������(str��ǰŲ��һ���ַ�)
		return match(original + 1, str) || match(original + 1, str + 1) || match(original, str + 1);
	}
	else if (*original == *str)
	{
		//�����ǰ�ַ���ȣ�ƥ����һ���ַ�
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