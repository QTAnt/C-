#include <iostream>
using namespace std;

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1);   //����һ��Ҫд
	/*Date(const Date& d);              
	Date& operator=(const Date& d);        //�漰��������ʱд����������
	~Date();*/
	void Print();
	int GetMonthDay(int year, int month);

	//����������Ҫ�ľ������������
	Date operator+(int day);               //����+����=���ڡ���>��ʱ����������Ӧ�����ã�
	Date& operator+=(int day);             //�ı�֮��Ķ���

	Date operator-(int day);             
	Date& operator-=(int day);

	int operator-(const Date& d);              

	//�������������
	//++d   ����>d.operator++(&d)
	Date operator++();
	//d++   ����>d.operator++(&d,0)
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