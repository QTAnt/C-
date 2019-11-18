#include <iostream>
#include <string>
using namespace std;

//继承***************************************************************
////基类(父类)
//class Person
//{
//public:
//	Person(const string& name = "congcong", string gender = "女", int age = 18)
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
////访问权限：控制一个成员是否可以直接在类外进项访问
////private:
//public:
//	string _name;
//	string _gender;
//	int _age;
//};
//
////派生类(子类)
////继承权限
//class Student : public :: Person   //继承Person类，是一继承列表
//{
////	void Word()
////	{
////		cout << "Good good study,day day up" << endl;
////	}
////
////	//扩展
////private:
////	int _stuid;
////	string _major;
	
//};
//
//int main()
//{
//	//可以检验是否将成员变量继承下来了（如上情况时，非继承关系的时候，sizeof()=1;继承时，sizeof()=32(string+int=28+4)）
//	//空类的大小为1
//	//string的大小为28
//	//cout << sizeof(string) << endl;
//	//cout << sizeof(Student) << endl;
//
//	Student s;
//	s.PrintPerson();
//
//	system("pause");
//	return 0;
//}

//公有继承（public）*************************************************************
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
	int _pub;	//公有
protected:
	int _pro;	//保护
private:
	int _pri;	//私有
};

class Derived : public Base
{
public:
	void SetDerivedInfo(int pub, int pro, int pri)
	{
		//从基类继承下来的成员变量进行赋值
		_pub = pub;		//公有
		_pro = pro;		//保护
		//_pri = pri;   //该行出错:即使是公有继承,父类的私有成员变量在子类里是不可直接被访问的，但是该成员已经被继承到子类中

		//子类新增加的成员变量赋值
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
//	d._pub = 10;  //可以应用
//	d._pro = 10;  //编译出错(D类可以编译，说明权限变为保护)
//	system("pause");
//	return 0;
//}


#if 0
//C语言“注释”
code
(1)code中定义的是一些调试版本的代码，此时code完全被编译器忽略。如果想让code生效，只需把#if 0改成#if 1
(2)#if 0还有一个重要的用途就是用来当成注释，如果你想要注释的程序很长，这个时候#if 0是最好的，保证不会犯错误。（但是林锐的书上说千万不要把#if 0 来当作块注释使用） #if 1可以让其间的变量成为局部变量。
(3)这个结构表示你先前写好的code，现在用不上了，又不想删除，就用这个方法，比注释方便。
#endif
//保护继承（protected）**********************************************************
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
//	int _pub;	//公有
//protected:
//	int _pro;	//保护
//private:
//	int _pri;	//私有
//};
//
//class Derived : protected Base
//{
//public:
//	void SetDerivedInfo(int pub, int pro, int pri)
//	{
//		//从基类继承下来的成员变量进行赋值
//		//如果是保护的形式，基类中被public访问的限定符修饰的成员在子类中的权限变成protected
//		_pub = pub;		//公有
//
//		//如果是保护的形式，基类中被protected访问的限定符修饰的成员在子类中的权限不变
//		_pro = pro;		//保护
//
//		//_pri = pri;   //该行出错:保护继承,父类的私有成员变量在子类里是不可直接被访问的，但是该成员已经被继承到子类中
//
//		//子类新增加的成员变量赋值
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
//	//d._pub = 10;  //编译出错,不可直接被访问，说明权限发生改变
//	//d._pro = 10;
//
//	system("pause");
//	return 0;
//}

//私有继承（private）**********************************************************
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
	int _pub;	//公有
protected:
	int _pro;	//保护
private:
	int _pri;	//私有
};

class Derived : private Base
{
public:
	void SetDerivedInfo(int pub, int pro, int pri)
	{
		//从基类继承下来的成员变量进行赋值
		//如果是private的形式，基类中被public、protected访问的限定符修饰的成员在子类中的权限变成private
		_pub = pub;		//公有
		_pro = pro;		//保护

		//_pri = pri;   //该行出错:private继承,父类的私有成员变量在子类里是不可见

		//子类新增加的成员变量赋值
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
//		_pub = 10;  //报错，说明权限为私有
//	}
//};

int main()
{
	Derived d;
	//d._pub = 10;  //编译出错,不可直接被访问，说明权限发生改变
	//d._pro = 10;

	system("pause");
	return 0;
}