#include "Date.h"

int Date::GetMonthDay(int year, int month)  //获得月份有多少天
{
	//1、写12个if
	//2、switch语句
	//3、
	//年份判断考虑闰年：四年一闰，百年不闰，四百年再一闰地球公转）
	static const int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };    //加 static目的是防止经常调用
	if ( month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0 )))
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
		day > 0 && day <= GetMonthDay(year, month))
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

//d+100   d不能改变，不能直接修改；拷贝构造一个对象（*this 是 d）ret，间接修改d
Date Date::operator+(int day)   //传值返回
{
	//Date ret(*this);  //拷贝构造一个对象ret（*this 是 d）ret跟d一样
	//ret._day += day;  //给拷贝构造的对象加减天数
	//while (ret._day > GetMonthDay(ret._year, ret._month))
	//{
	//	ret._day -= GetMonthDay(ret._year, ret._month);
	//	ret._month++;
	//	if (ret._day == 13)
	//	{
	//		ret._year++;
	//		ret._month = 1;
	//	}
	//}
	//return ret;

	//+复用+=         //效率低的复用效率高的
	Date ret(*this);      
	ret += day;
	return ret;
}

//d1 += 100
//d2 += -100
Date& Date::operator+=(int day)
{
	   
	//再复用
	if (day < 0)
	{
		return *this -= -day;
	}

	_day += day;  //给拷贝构造的对象加减天数
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}

	return *this;
}

//d-day 
Date Date::operator-(int day)
{
	//Date ret(*this);
	//ret._day -= day;
	//while (ret._day <= 0)  //大于0 ，合法
	//{
	//	ret._month--;
	//	if (ret._month == 0)
	//	{
	//		ret._year--;
	//		ret._month = 12;
	//	}
	//    ret._day += GetMonthDay(ret._year, ret._month);
	//}
	//
	//return ret;

	Date ret(*this);
	ret -= day;
	return ret;
}

Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += -day;
	}
	_day -= day;
	while ( _day <= 0)  //大于0 ，合法
	{
		_month--;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}

	return *this;
}

//复用************************************************************************************

//++d   ——>d.operator++(&d)    //前置返回++之后的值
Date Date::operator++()
{
	*this += 1;
	return *this;
}

//d++   ——>d.operator++(&d,1)  //后置返回++之前的值,要保存之前的值
Date Date::operator++(int)
{
	Date tmp(*this);
	*this += 1;

	return tmp;
}

Date Date::operator--()
{
	*this -= 1;
	return *this;

}

Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;

	return *this;

}

//日期-日期
int Date::operator-(const Date& d)
{
	//小的日期一直++，加到和大的日期一样时，加了多少次就差多少天
	Date max = *this;
	Date min = d;
	int flag = 1;
	if ( *this < d )
	{
		max = d;
		min = *this;
		flag = -1;
	}

	int n = 0;
	while (min != max)
	{
		++min;
		++n;
	}

	return n*flag;

}

int main()
{
	//Date d1(2019, 2, 27);
	//d1.Print();


	//Date d2(2016, 2, 27);
	//d2.Print();
	//
	//Date d3(d2);
	//Date d4;
	//d2 = d4;

	//Date d5 = d2;  //拷贝构造:d2赋给d5(把d5初始化成d2)
	//
	//Date d6(2019, 2, 28);        //生命周期在整个 main 函数
	//d6.Print();     

	//Date(2019, 2, 28).Print();   //Date(2019, 2, 28)就是创建的一个对象;匿名对象;生命周期只在本行，结束之后就会调用析构函数    用完之后没有名字留下来

	//Date d1(2019, 2, 28);
	//Date d2 = d1 + 100;    //时间加天数方法1(保存日期时适用)
	//d2.Print();

	//(d1 + 100).Print();      //时间加天数方法2(看一下日期时适用)         //传值返回的返回值是一个匿名对象


	//Date d3 = d2 - 100;
	//d3.Print();

	Date d1(2019, 2, 28);
	d1 += 100;
	d1.Print();   //2019,6,8

	d1 -= 100;
	d1.Print();   //2019,2,28

	(++d1).Print();//2019,3,1
	(d1++).Print();//2019,3,1
	d1.Print();    //2019,3,2

	Date d2(2019, 2, 28);
	Date d3(2019, 4, 1);
	cout << (d2 - d3) << endl;
	cout << (d3 - d2) << endl;


	system("pause");
	return 0;
}