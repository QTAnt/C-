#include "Date.h"

int Date::GetMonthDay(int year, int month)  //����·��ж�����
{
	//1��д12��if
	//2��switch���
	//3��
	//����жϿ������꣺����һ�򣬰��겻���İ�����һ�����ת��
	static const int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };    //�� staticĿ���Ƿ�ֹ��������
	if ( month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0 )))
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
		day > 0 && day <= GetMonthDay(year, month))
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

//d+100   d���ܸı䣬����ֱ���޸ģ���������һ������*this �� d��ret������޸�d
Date Date::operator+(int day)   //��ֵ����
{
	//Date ret(*this);  //��������һ������ret��*this �� d��ret��dһ��
	//ret._day += day;  //����������Ķ���Ӽ�����
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

	//+����+=         //Ч�ʵ͵ĸ���Ч�ʸߵ�
	Date ret(*this);      
	ret += day;
	return ret;
}

//d1 += 100
//d2 += -100
Date& Date::operator+=(int day)
{
	   
	//�ٸ���
	if (day < 0)
	{
		return *this -= -day;
	}

	_day += day;  //����������Ķ���Ӽ�����
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
	//while (ret._day <= 0)  //����0 ���Ϸ�
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
	while ( _day <= 0)  //����0 ���Ϸ�
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

//����************************************************************************************

//++d   ����>d.operator++(&d)    //ǰ�÷���++֮���ֵ
Date Date::operator++()
{
	*this += 1;
	return *this;
}

//d++   ����>d.operator++(&d,1)  //���÷���++֮ǰ��ֵ,Ҫ����֮ǰ��ֵ
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

//����-����
int Date::operator-(const Date& d)
{
	//С������һֱ++���ӵ��ʹ������һ��ʱ�����˶��ٴξͲ������
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

	//Date d5 = d2;  //��������:d2����d5(��d5��ʼ����d2)
	//
	//Date d6(2019, 2, 28);        //�������������� main ����
	//d6.Print();     

	//Date(2019, 2, 28).Print();   //Date(2019, 2, 28)���Ǵ�����һ������;��������;��������ֻ�ڱ��У�����֮��ͻ������������    ����֮��û������������

	//Date d1(2019, 2, 28);
	//Date d2 = d1 + 100;    //ʱ�����������1(��������ʱ����)
	//d2.Print();

	//(d1 + 100).Print();      //ʱ�����������2(��һ������ʱ����)         //��ֵ���صķ���ֵ��һ����������


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