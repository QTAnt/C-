#include "Date.h"

int Date::GetMonthDay(int year, int month)  //获得月份有多少天
{
	//1、写12个if
	//2、switch语句
	//3、
	//年份判断考虑闰年：四年一闰，百年不闰，四百年再一闰地球公转）
	static const int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };    //加 static目的是防止经常调用
	if ( month == 2 && (year % 4 == 0 && year % 100 != 0 && year % 400 == 0))
	{
		return 29;
	}
	return monthArray[month];

}

Date::Date(int year, int month, int day)
{
	//检查日期合法性
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
		cout << "Date Invalid" <<endl;   //非法语句
	}
}

void Date:: Print()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

//运算符重载
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

//复用

bool Date::operator>=(const Date& d)
{
	return *this > d || *this == d;  //(*this > d) *this调用的是‘bool Date::operator>(const Date& d)’,其他的同理
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

//d+100   拷贝构造一个对象（*this 是 d）
Date Date::operator+(int day)
{
	Date ret(*this);  //拷贝构造一个对象（*this 是 d）
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