#include <iostream>
using namespace std;

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1);   //构造一定要写
	/*Date(const Date& d);              
	Date& operator=(const Date& d);        //涉及清理和深拷贝时写这三个函数
	~Date();*/
	void Print();
	int GetMonthDay(int year, int month);

	//日期类最重要的就是运算符重载
	Date operator+(int day);               //日期+天数=日期——>临时变量（不能应用引用）
	Date& operator+=(int day);             //改变之后的对象

	Date operator-(int day);             
	Date& operator-=(int day);

	int operator-(const Date& d);              

	//构成运算符重载
	//++d   ——>d.operator++(&d)
	Date operator++();
	//d++   ——>d.operator++(&d,0)
	Date operator++(int);


	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
	
private:
	int _year;
	int _month;
	int _day;
};