//���һ��https://www.nowcoder.com/practice/769d45d455fe40b385ba32f97e7bcded?tpId
//������������ڣ���������һ��ĵڼ��졣��
//��ϸ������
//����ĳ��ĳ��ĳ�գ��ж���һ������һ��ĵڼ��죿
#include <iostream>

int main()
{
	int one2ndays[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
	int year, month, day;
	while (std::cin >> year >> month >> day)
	{
		int n = one2ndays[month - 1];
		n += day;              // ������ =���·ݣ�1����������day(���µĵڼ���)
		if ((month > 2) && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))                                  //�ж��Ƿ�Ϊ���꣨��Ϊ��������������һ�죩����2�µ�����Ҫ�����ж�
		{
			n += 1;
		}
		std::cout << n << std::endl;
	}
	return 0;
}