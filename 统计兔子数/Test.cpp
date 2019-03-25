//有一只兔子，从出生后第3个月起每个月都生一只兔子，小兔子长到第三个月后每个月又生一只兔子，假如兔子都不死，问每个月的兔子总数为多少？
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