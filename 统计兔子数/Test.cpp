//��һֻ���ӣ��ӳ������3������ÿ���¶���һֻ���ӣ�С���ӳ����������º�ÿ��������һֻ���ӣ��������Ӷ���������ÿ���µ���������Ϊ���٣�
//https://www.nowcoder.com/practice/1221ec77125d4370833fd3ad5ba72395?tpId=37&&tqId=21260&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
#include <iostream>
using namespace std;

int main()
{

	int month;
	int count;
	while (cin >> month)
	{
		int first = 1;
		int second = 1;

		for (int n = 3; n <= month; ++n)
		{
			count = first + second;
			first = second;
			second = count;
		}
		cout << count << endl;
	}
	return 0;
}