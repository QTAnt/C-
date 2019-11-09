//#include <iostream>
//
//using namespace std;
//
//int a = 10;
//
//int main()
//{
//	int a = 20;
//	//printf("%d\n", ::a);  //结果：10 (::域作用限定符；左边为空，表示命名空间为全局域)
//	//printf("%d\n", a);    //结果：20 (访问遵循就近原则)
//	system("pause");
//	return 0;
//}
//
//命名空间里可以随意定义(除了关键字)，不用担心重复
//using namespace std;(意思是把std这个命名空间展开，即为全局的)
#include <stdio.h>
#include <string>

//using namespace std;//1、全部展开
namespace zcc
{
	int a = 10;
	int strstr = 20;
	namespace zcc_c
	{
		int a = 100;
	}
}

using zcc::a;   //指定展开zcc中的a,2、展开其中某一个

int main()
{
	printf("%d\n", a);
	printf("%d\n", zcc::strstr);//3、展开指定的，用哪个展开哪个
	printf("%d\n", zcc::zcc_c::a); //命名空间中可嵌套命名空间，但不提倡此类写法

	system("pause");
	return 0;
}

//同一个工程中允许存在多个相同名称的命名空间，编译器最后会合成同一个命名空间中
