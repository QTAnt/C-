#include <iostream>
#include <string>
using namespace std;

//�̳�***************************************************************
////����(����)
//class Person
//{
//public:
//	Person(const string& name = "congcong", string gender = "Ů", int age = 18)
//		: _name(name)
//		, _gender(_gender)
//		, _age(age)
//	{}
//
//	void PrintPerson()
//	{
//		cout << "name:" << _name << " " << "gender:" << _gender << " " 
//			<< "age:" << _age << endl;
//	}
//
////����Ȩ�ޣ�����һ����Ա�Ƿ����ֱ��������������
////private:
//public:
//	string _name;
//	string _gender;
//	int _age;
//};
//
////������(����)
////�̳�Ȩ��
//class Student : public :: Person   //�̳�Person�࣬��һ�̳��б�
//{
////	void Word()
////	{
////		cout << "Good good study,day day up" << endl;
////	}
////
////	//��չ
////private:
////	int _stuid;
////	string _major;
	
//};
//
//int main()
//{
//	//���Լ����Ƿ񽫳�Ա�����̳������ˣ��������ʱ���Ǽ̳й�ϵ��ʱ��sizeof()=1;�̳�ʱ��sizeof()=32(string+int=28+4)��
//	//����Ĵ�СΪ1
//	//string�Ĵ�СΪ28
//	//cout << sizeof(string) << endl;
//	//cout << sizeof(Student) << endl;
//
//	Student s;
//	s.PrintPerson();
//
//	system("pause");
//	return 0;
//}

//���м̳У�public��*************************************************************
class Base
{
public:
	void SetBaseInfo(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}
	void PrintBaseInfo()
	{
		cout << _pub << endl;
		cout << _pro << endl;
		cout << _pri << endl;
	}

public:
	int _pub;	//����
protected:
	int _pro;	//����
private:
	int _pri;	//˽��
};

class Derived : public Base
{
public:
	void SetDerivedInfo(int pub, int pro, int pri)
	{
		//�ӻ���̳������ĳ�Ա�������и�ֵ
		_pub = pub;		//����
		_pro = pro;		//����
		//_pri = pri;   //���г���:��ʹ�ǹ��м̳�,�����˽�г�Ա�������������ǲ���ֱ�ӱ����ʵģ����Ǹó�Ա�Ѿ����̳е�������

		//���������ӵĳ�Ա������ֵ
		_pubd = pub;
		_prod = pro;
		_prid = pri;
	}
	
public:
	int _pubd;
protected:
	int _prod;
private:
	int _prid;
};
//
//class D : public Derived
//{
//	void TestFunc()
//	{
//		_pub = 10;
//	}
//};
//
//int main()
//{
//	//cout << sizeof(Derived) << endl;
//	Derived d;
//	d._pub = 10;  //����Ӧ��
//	d._pro = 10;  //�������(D����Ա��룬˵��Ȩ�ޱ�Ϊ����)
//	system("pause");
//	return 0;
//}


#if 0
//C���ԡ�ע�͡�
code
(1)code�ж������һЩ���԰汾�Ĵ��룬��ʱcode��ȫ�����������ԡ��������code��Ч��ֻ���#if 0�ĳ�#if 1
(2)#if 0����һ����Ҫ����;������������ע�ͣ��������Ҫע�͵ĳ���ܳ������ʱ��#if 0����õģ���֤���᷸���󡣣��������������˵ǧ��Ҫ��#if 0 ��������ע��ʹ�ã� #if 1���������ı�����Ϊ�ֲ�������
(3)����ṹ��ʾ����ǰд�õ�code�������ò����ˣ��ֲ���ɾ�������������������ע�ͷ��㡣
#endif
//�����̳У�protected��**********************************************************
//class Base
//{
//public:
//	void SetBaseInfo(int pub, int pro, int pri)
//	{
//		_pub = pub;
//		_pro = pro;
//		_pri = pri;
//	}
//	void PrintBaseInfo()
//	{
//		cout << _pub << endl;
//		cout << _pro << endl;
//		cout << _pri << endl;
//	}
//
//public:
//	int _pub;	//����
//protected:
//	int _pro;	//����
//private:
//	int _pri;	//˽��
//};
//
//class Derived : protected Base
//{
//public:
//	void SetDerivedInfo(int pub, int pro, int pri)
//	{
//		//�ӻ���̳������ĳ�Ա�������и�ֵ
//		//����Ǳ�������ʽ�������б�public���ʵ��޶������εĳ�Ա�������е�Ȩ�ޱ��protected
//		_pub = pub;		//����
//
//		//����Ǳ�������ʽ�������б�protected���ʵ��޶������εĳ�Ա�������е�Ȩ�޲���
//		_pro = pro;		//����
//
//		//_pri = pri;   //���г���:�����̳�,�����˽�г�Ա�������������ǲ���ֱ�ӱ����ʵģ����Ǹó�Ա�Ѿ����̳е�������
//
//		//���������ӵĳ�Ա������ֵ
//		_pubd = pub;
//		_prod = pro;
//		_prid = pri;
//	}
//
//public:
//	int _pubd;
//protected:
//	int _prod;
//private:
//	int _prid;
//};
//
//class D : public Derived
//{
//	void TestFunc()
//	{
//		_pub = 10;
//		_pro = 10;
//	}
//};
//
//int main()
//{
//	Derived d;
//	//d._pub = 10;  //�������,����ֱ�ӱ����ʣ�˵��Ȩ�޷����ı�
//	//d._pro = 10;
//
//	system("pause");
//	return 0;
//}

//˽�м̳У�private��**********************************************************
class Base
{
public:
	void SetBaseInfo(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}
	void PrintBaseInfo()
	{
		cout << _pub << endl;
		cout << _pro << endl;
		cout << _pri << endl;
	}

public:
	int _pub;	//����
protected:
	int _pro;	//����
private:
	int _pri;	//˽��
};

class Derived : private Base
{
public:
	void SetDerivedInfo(int pub, int pro, int pri)
	{
		//�ӻ���̳������ĳ�Ա�������и�ֵ
		//�����private����ʽ�������б�public��protected���ʵ��޶������εĳ�Ա�������е�Ȩ�ޱ��private
		_pub = pub;		//����
		_pro = pro;		//����

		//_pri = pri;   //���г���:private�̳�,�����˽�г�Ա�������������ǲ��ɼ�

		//���������ӵĳ�Ա������ֵ
		_pubd = pub;
		_prod = pro;
		_prid = pri;
	}

public:
	int _pubd;
protected:
	int _prod;
private:
	int _prid;
};

//class D : public Derived
//{
//	void TestFunc()
//	{
//		_pub = 10;  //����˵��Ȩ��Ϊ˽��
//	}
//};

int main()
{
	Derived d;
	//d._pub = 10;  //�������,����ֱ�ӱ����ʣ�˵��Ȩ�޷����ı�
	//d._pro = 10;

	system("pause");
	return 0;
}