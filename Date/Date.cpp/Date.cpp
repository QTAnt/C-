#include "Date.h"

int Date::GetMonthDay(int year, int month)  //����·��ж�����
{
	//1��д12��if
	//2��switch���
	//3��
	//����жϿ������꣺����һ�򣬰��겻���İ�����һ�����ת��
	static const int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };    //�� staticĿ���Ƿ�ֹ��������
	if ( month == 2 && (year % 4 == 0 && year % 100 != 0 && year % 400 == 0))
	{
		return 29;
	}
	return monthArray[month];

}

Date::Date(int year, int month, int day)
{
	//������ںϷ���
	if (year > 0 &&
		month > 0 && month < 13 &&
		day > 0 && day < GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "Date Invalid" <<endl;   //�Ƿ����
	}
}

void Date:: Print()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

//���������
bool Date::operator>(const Date& d)
{

	return ((_year > d._year)
		|| (_year == d._year && _month > d._month)
		|| (_year == d._year && _month == d._month && _day > d._day));
}

bool Date::operator==(const Date& d)
{
	return (_year == d._year && _month == d._month &&_day == d._day);
}

//����

bool Date::operator>=(const Date& d)
{
	return *this > d || *this == d;  //(*this > d) *this���õ��ǡ�bool Date::operator>(const Date& d)��,������ͬ��
}

bool Date::operator<(const Date& d)
{
	return !(*this >= d);
}

bool Date::operator<=(const Date& d)
{
	return !(*this > d);
}

bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}

//d+100   ��������һ������*this �� d��
Date Date::operator+(int day)
{
	Date ret(*this);  //��������һ������*this �� d��
	ret._day += day;
	while (ret._day > GetMonthDay(ret._year, ret._month))
	{

	}
	return ret;


}


int main()
{
	//Date d1(2019, 2, 27);
	//d1.Print();

	Date d2(2016, 2, 27);
	d2.Print();

	system("pause");
	return 0;
}