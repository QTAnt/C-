//https://www.nowcoder.com/questionTerminal/e2422543519249f292d8435394ab82fe
//来源：牛客网
//数根可以通过把一个数的各个位上的数字加起来得到。如果得到的数是一位数，那么这个数就是数根；如果结果是两位数或者包括更多位的数字，那么再把这些数字加起来。如此进行下去，直到得到是一位数为止。
//比如，对于24 来说，把2 和4 相加得到6，由于6 是一位数，因此6 是24 的数根。
//再比如39，把3 和9 加起来得到12，由于12 不是一位数，因此还得把1 和2 加起来，最后得到3，这是一个一位数，因此3 是39 的数根。
//现在给你一个正整数，输出它的数根。

#include <iostream>
#include <string>
using namespace std;

int NRoot(int num) 
{
	int nr = 0;
	while (num > 0) 
	{
		nr += num % 10;     /*每次只获取个位数字*/
		num /= 10;
	}

	while (nr > 9) 
	{
		nr = NRoot(nr);
	}
	return nr;
}

int main()
{
	string n;
	while (cin >> n) 
	{
		int sum = 0;
		for (int i = 0; i < n.length(); i++) 
		{
			sum += n[i] - '0';
		}
		cout << NRoot(sum) << endl;
	}
	return 0;
}