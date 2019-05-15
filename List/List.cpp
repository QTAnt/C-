#include <iostream>
#include <list>

using namespace std;

void print_list(const list<int>& l)
{
	//����ı���ֻ��һ�ַ�ʽ����������
	//list<int>::const_iterator cit = l.cbegin();
	auto cit = l.cbegin();          //auot��ȱ�ݣ����ű������ԣ����ܵ��ű���(����򵥣����ǣ�����ɶ��Խ���)

	while (cit != l.cend())
	{
		cout << *cit << " ";
		++cit;
	}
	cout << endl;
}

//������******************************************************************************
void test_list1()
{
	list<int> l1;                         // ����յ�l1
	list<int> l2(3, 100);                 //l2�з�3��ֵΪ100��Ԫ��
	list<int> l3(l2.begin(), l2.end());   // ��l2��[begin(), end() )����ҿ������乹��l3
	list<int> copy(l3);                   // ��l3���������ʼ��copy

	//Ӧ�õ���������ӡcopy�е�Ԫ��
	//list<int> ::iterator copyit = copy.begin();
	auto copyit = copy.begin();

	while (copyit != copy.end())
	{
		cout << *copyit << " ";
		++copyit;
	}
	cout << endl;
	print_list(copy);

	//���ڷ�Χ��for
	for (const auto& e : l3)   //�������const��&�����ϣ���ɸ��ĵĻ�������const
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

	//���������
	//list<int>::reverse_iterator rit = l3.rbegin();
	auto rit = l3.rbegin();

	while (rit != l3.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

}

//ͷ(β)�壬ͷ(β)ɾ
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
	l.assign(5, 6);         //���丳ֵ������֮ǰ�Ĵ���

	for (const auto& e : l)
		cout << e << " ";
	cout << endl;
}

//����ɾ��****************************************************************************
//erase�����ھ�ɾ���������ھͻᱨ��

void test_list3()
{
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);

	l.insert(l.begin(), 0);   //����

	auto pos = find(l.begin(), l.end(), 3);        //find���ԶԲ�ͬ�ĵ����������в���->���ͣ�ģ�壩����������ķ�Χ������ҿ���[ )
	l.insert(pos, 11);   //�����ϴ��룬���ҪѰ�ҵ���ֵ������(�磺��300)����l.end()��һֱ�����ң�ֱ���ҵ����һλ���ͻ�嵽���������β�壬Ϊ������������Ҫ���������ж�
	if (pos != l.end())
	{
		l.insert(pos, 30);         //list���벻�ᵼ�µ�����ʧЧ
		*pos = 33;     //pos�ղŴ����3��������֮�󣬰�33��ֵ����
	}
		
	l.erase(pos);        //listɾ���ᵼ�µ�����ʧЧ
	//*pos = 33;         //�������Ѿ�ʧЧ���Ѿ�ɾ���ˣ�Ұָ���ˣ�,�ᱨ��

	
	for (const auto& e : l)
		cout << e << " ";
	cout << endl;


	//ɾ������ż��
	auto eit = l.begin();
	while (eit != l.end())
	{
		if (*eit % 2 == 0)
		{
			eit = l.erase(eit);    //erase�Զ�������һ��λ�õĵ�����
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
//����*******************************************************************************
#include <time.h>
void test_list4()
{
	list<int> l1(1000000, 3);
	list<int> l2(1000000, 4);
	
	//Ч�ʽ���
	size_t begin1 = clock();
	swap(l1, l2);    //���
	size_t end1 = clock();

	size_t begin2 = clock();
	l1.swap(l2);     //��Ա�����Ľ������Ƽ�ʹ�ã�
	size_t end2 = clock();

	cout << end1 - begin1 << endl;
	cout << end2 - begin2 << endl;
}

//�ı�����***************************************************************************
void test_list5()
{
	list<int> l;
	l.resize(10);     //Ĭ��ȱʡֵ��0
	l.resize(20, 1);  //�䵱����(�ı�����)
	l.resize(5);      //�䵱ɾ��   
	l.clear();        //������ͷ�ڵ㣬���Լ������루�����Ͳ�һ���ˣ�����Ҳɾ��ͷ�ڵ㣩
	l.push_back(100);

	for (const auto& e : l)
		cout << e << " ";
	cout << endl;
}

//remove�����ھ�ɾ���������ھͲ�ɾ��,���ᱨ��**************************************
//remove_if�������ض�������ɾ������һ����������
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

//unique(ȥ��)��������������*******************************************************
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

	l.sort();     //������Ŀ�������Ч�ʣ�������ֱ��ɾ�Ļ�����̫���ˣ� ʱ�临�Ӷȣ�N*log(N)
	l.unique();   //��ȥ��  ʱ�临�Ӷȣ�O(N)

	for (const auto& e : l)
		cout << e << " ";
	cout << endl;
}
//***********************************************************************************
//emplace(�ȼ���insert,C++11,���죫����)��emplace_back(�ȼ���push_back)
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

// push_backβ�壺�ȹ����Ԫ�أ�Ȼ��Ԫ�ؿ������ڵ��У�����ʱ�ȵ����캯�����ٵ��������캯��
// emplace_backβ�壺�ȹ���ڵ㣬Ȼ����ù��캯���ڽڵ���ֱ�ӹ������
// emplace_back��push_back����Ч������һ�ο������캯���ĵ���
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
	//Date d1(2019, 5, 15);  //����һ��
	//l.push_back(d1);       //��������
	//l.emplace_back(d1);    //��������

	//��ֵ���ÿ���������ֵ����ֵ����Ҳ����������ֵ
	//Date d1(2019, 5, 15);  
	//�������������������졢�������죨û�в��
	l.push_back(Date(2019, 5, 15));       //�������졢��������
	l.emplace_back(Date(2019, 5, 15));    //�������졢��������
	l.emplace_back(2019, 5, 15);   //ֻ��һ�ι���(����),�ٿ�������һ��
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