//https://www.nowcoder.com/questionTerminal/e2422543519249f292d8435394ab82fe
//��Դ��ţ����
//��������ͨ����һ�����ĸ���λ�ϵ����ּ������õ�������õ�������һλ������ô�������������������������λ�����߰�������λ�����֣���ô�ٰ���Щ���ּ���������˽�����ȥ��ֱ���õ���һλ��Ϊֹ��
//���磬����24 ��˵����2 ��4 ��ӵõ�6������6 ��һλ�������6 ��24 ��������
//�ٱ���39����3 ��9 �������õ�12������12 ����һλ������˻��ð�1 ��2 �����������õ�3������һ��һλ�������3 ��39 ��������
//���ڸ���һ�����������������������

#include <iostream>
#include <string>
using namespace std;

int NRoot(int num) 
{
	int nr = 0;
	while (num > 0) 
	{
		nr += num % 10;     /*ÿ��ֻ��ȡ��λ����*/
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