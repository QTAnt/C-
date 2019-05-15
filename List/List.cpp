#include <iostream>
#include <list>

using namespace std;

void print_list(const list<int>& l)
{
	//链表的遍历只有一种方式——迭代器
	//list<int>::const_iterator cit = l.cbegin();
	auto cit = l.cbegin();          //auot的缺陷：正着遍历可以；不能倒着遍历(代码简单，但是，代码可读性降低)

	while (cit != l.cend())
	{
		cout << *cit << " ";
		++cit;
	}
	cout << endl;
}

//迭代器******************************************************************************
void test_list1()
{
	list<int> l1;                         // 构造空的l1
	list<int> l2(3, 100);                 //l2中放3个值为100的元素
	list<int> l3(l2.begin(), l2.end());   // 用l2的[begin(), end() )左闭右开的区间构造l3
	list<int> copy(l3);                   // 用l3拷贝构造初始化copy

	//应用迭代器，打印copy中的元素
	//list<int> ::iterator copyit = copy.begin();
	auto copyit = copy.begin();

	while (copyit != copy.end())
	{
		cout << *copyit << " ";
		++copyit;
	}
	cout << endl;
	print_list(copy);

	//基于范围的for
	for (const auto& e : l3)   //建议加上const及&；如果希望可更改的话，不加const
	{
		cout << e << " ";
	}
	cout << endl;

	l3.push_back(111);
	for (const auto& e : l3)
	{
		cout << e << " ";
	}
	cout << endl;

	//反向迭代器
	//list<int>::reverse_iterator rit = l3.rbegin();
	auto rit = l3.rbegin();

	while (rit != l3.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

}

//头(尾)插，头(尾)删
void test_list2()
{
	list<int> l;
	l.push_back(1);
	l.push_front(2);
	l.push_front(3);

	for (const auto& e : l)
		cout << e << " ";
	cout << endl;

	l.pop_back();
	l.pop_front();
	l.assign(5, 6);         //分配赋值，覆盖之前的代码

	for (const auto& e : l)
		cout << e << " ";
	cout << endl;
}

//插入删除****************************************************************************
//erase（存在就删除；不存在就会报错）

void test_list3()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);

	l.insert(l.begin(), 0);   //插入

	auto pos = find(l.begin(), l.end(), 3);        //find可以对不同的迭代器都进行查找->泛型（模板）迭代器区间的范围是左闭右开：[ )
	l.insert(pos, 11);   //像以上代码，如果要寻找的数值不存在(如：找300)，则l.end()会一直往后找，直至找到最后一位，就会插到最后，类似于尾插，为避免这种现象，要进行如下判断
	if (pos != l.end())
	{
		l.insert(pos, 30);         //list插入不会导致迭代器失效
		*pos = 33;     //pos刚才存的是3，解引用之后，把33赋值给他
	}
		
	l.erase(pos);        //list删除会导致迭代器失效
	//*pos = 33;         //迭代器已经失效（已经删掉了，野指针了）,会报错

	
	for (const auto& e : l)
		cout << e << " ";
	cout << endl;


	//删除所有偶数
	auto eit = l.begin();
	while (eit != l.end())
	{
		if (*eit % 2 == 0)
		{
			eit = l.erase(eit);    //erase自动返回下一个位置的迭代器
		}
		else
		{
			++eit;
		}
	}
	for (const auto& e : l)
		cout << e << " ";
	cout << endl;
}
//交换*******************************************************************************
#include <time.h>
void test_list4()
{
	list<int> l1(1000000, 3);
	list<int> l2(1000000, 4);
	
	//效率近似
	size_t begin1 = clock();
	swap(l1, l2);    //深拷贝
	size_t end1 = clock();

	size_t begin2 = clock();
	l1.swap(l2);     //成员变量的交换（推荐使用）
	size_t end2 = clock();

	cout << end1 - begin1 << endl;
	cout << end2 - begin2 << endl;
}

//改变容量***************************************************************************
void test_list5()
{
	list<int> l;
	l.resize(10);     //默认缺省值是0
	l.resize(20, 1);  //充当插入(改变容量)
	l.resize(5);      //充当删除   
	l.clear();        //不清理头节点，可以继续插入（析构就不一样了，析构也删除头节点）
	l.push_back(100);

	for (const auto& e : l)
		cout << e << " ";
	cout << endl;
}

//remove（存在就删除；不存在就不删除,不会报错）**************************************
//remove_if（满足特定条件就删除，是一个迭代器）
void test_list6()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.remove(2);      //1 3 4
	l.remove(5);      //1 2 3 4

	for (const auto& e : l)
		cout << e << " ";
	cout << endl;
}

//unique(去重)，针对排序的链表*******************************************************
void test_list7()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(1);
	l.push_back(2);
	l.push_back(5);
	l.push_back(3);
	l.push_back(2);
	l.push_back(4);

	l.sort();     //先排序（目的是提高效率；不排序直接删的话代价太大了） 时间复杂度：N*log(N)
	l.unique();   //再去重  时间复杂度：O(N)

	for (const auto& e : l)
		cout << e << " ";
	cout << endl;
}
//***********************************************************************************
//emplace(等价于insert,C++11,构造＋插入)；emplace_back(等价于push_back)
void test_list8()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.emplace_back(4);

	for (const auto& e : l)
		cout << e <<  endl;
}

// push_back尾插：先构造好元素，然后将元素拷贝到节点中，插入时先调构造函数，再调拷贝构造函数
// emplace_back尾插：先构造节点，然后调用构造函数在节点中直接构造对象
// emplace_back比push_back更高效，少了一次拷贝构造函数的调用
// emplace_back / emplace_front / emplace
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		cout << "Date(int, int, int):" << this << endl;
	}
	Date(const Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		cout << "Date(const Date&):" << this << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

void test_list9()
{
	list<Date> l;
	//Date d1(2019, 5, 15);  //构造一次
	//l.push_back(d1);       //拷贝构造
	//l.emplace_back(d1);    //拷贝构造

	//左值引用可以引用左值；右值引用也可以引用左值
	//Date d1(2019, 5, 15);  
	//构造匿名对象正常构造、拷贝构造（没有差别）
	l.push_back(Date(2019, 5, 15));       //正常构造、拷贝构造
	l.emplace_back(Date(2019, 5, 15));    //正常构造、拷贝构造
	l.emplace_back(2019, 5, 15);   //只调一次构造(优势),少拷贝构造一次
}

int main()
{
	//print_list(const list<int>& l);
	//test_list1();
	//test_list2();
	//test_list3();
	//test_list4();
	//test_list5();
	//test_list6();
	//test_list7();
	//test_list8();
	test_list9();

	system("pause");
	return 0;
}