//#include <iostream>
//
//using namespace std;
//
//int a = 10;
//
//int main()
//{
//	int a = 20;
//	//printf("%d\n", ::a);  //�����10 (::�������޶��������Ϊ�գ���ʾ�����ռ�Ϊȫ����)
//	//printf("%d\n", a);    //�����20 (������ѭ�ͽ�ԭ��)
//	system("pause");
//	return 0;
//}
//
//�����ռ���������ⶨ��(���˹ؼ���)�����õ����ظ�
//using namespace std;(��˼�ǰ�std��������ռ�չ������Ϊȫ�ֵ�)
#include <stdio.h>
#include <string>

//using namespace std;//1��ȫ��չ��
namespace zcc
{
	int a = 10;
	int strstr = 20;
	namespace zcc_c
	{
		int a = 100;
	}
}

using zcc::a;   //ָ��չ��zcc�е�a,2��չ������ĳһ��

int main()
{
	printf("%d\n", a);
	printf("%d\n", zcc::strstr);//3��չ��ָ���ģ����ĸ�չ���ĸ�
	printf("%d\n", zcc::zcc_c::a); //�����ռ��п�Ƕ�������ռ䣬�����ᳫ����д��

	system("pause");
	return 0;
}

//ͬһ��������������ڶ����ͬ���Ƶ������ռ䣬����������ϳ�ͬһ�������ռ���
