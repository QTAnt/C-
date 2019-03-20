//编程一：https://www.nowcoder.com/practice/769d45d455fe40b385ba32f97e7bcded?tpId
//根据输入的日期，计算是这一年的第几天。。
//详细描述：
//输入某年某月某日，判断这一天是这一年的第几天？
#include <iostream>

int main()
{
	int one2ndays[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
	int year, month, day;
	while (std::cin >> year >> month >> day)
	{
		int n = one2ndays[month - 1];
		n += day;              // 总天数 =（月份－1）的天数＋day(本月的第几天)
		if ((month > 2) && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))                                  //判断是否为闰年（若为闰年则总天数多一天）大于2月的日期要进来判断
		{
			n += 1;
		}
		std::cout << n << std::endl;
	}
	return 0;
}