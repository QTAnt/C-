#include <iostream>
#include <string>
using namespace std;

//������������ֵС�ڸ��ڵ㣬������������ֵ���ڸ��ڵ�

#include <map>
#include <set>

template<class K, class V>
struct pair
{
	K first;
	V second;

	//���캯��
};

template<class K, class V>
inline std::pair<K, V> make_pair(const K& k, const V& v)
{
	return std::pair<K, V>(k, v);
}

void test_map()
{
	//1.key./value. ͨ���ؼ��ֲ���ӳ����Ϣvalue����Ŀ��ͨ��ҳ��Ѱ��span��
	//pair��һ��������ģ������Ľṹ�壬�ֱ���first(key)��second(value)
	std::map<std::string, std::string> dict;

	//std::pair<std::string, std::string>��ģ����+����
	dict.insert(std::pair<std::string, std::string>("sort", "����"));	
	dict.insert(std::make_pair("string", "�ַ���")); //����ģ�壺std::make_pair ,�Զ��˳�����
	dict.insert(std::make_pair("left", "���")); 
	dict.insert(std::make_pair("left", "ʣ��"));  
	//����ǡ���ߡ��������ʱ��ֻ��key,key���˾Ͳ��ٲ����ˣ�value�಻��ͬ����Ҫ
	dict["pair"];
	dict["key"] = "�ؼ���"; 
	dict["pair"] = "ʣ��";

	std::map<std::string, std::string>::iterator dit = dict.begin();
	while (dit != dict.end())
	{
		//cout << (*dit).first << ":" << (*dit).second << endl; 
		//pair��֧�����������ֱ��Ӧ��*dit;��list�ĺ���;dic��һ��������������������������ݣ���������һ��pair��pair��һ��first����һ��second
		cout << dit->first << ":" << dit->second << endl;  //�Ƽ���������ʽд
		++dit;
	}
	cout << endl;

	//ͳ��ˮ�����ֵĴ���
	std::string strs[] = { "ƻ��", "ƻ��", "�㽶", "����", "�㽶", "����", "����", "ƻ��" };
	//std::map<std::string, int> countmap;   //ˮ�����֣�ˮ������
	//for (const auto& str : strs) //��ʾ�ҵ��ˣ���������
	//{
	//	auto it = countmap.find(str);
	//	if (it != countmap.end())
	//	{
	//		//(*it).second++;//���ص�������
	//		it->second++;//���ص���ָ��,ʡ����һ��->
	//	}
	//	else //��ʾû�У�û�оͲ���
	//	{
	//		countmap.insert(make_pair(str, 1));
	//	}
	//}


	//**************************************************************************************

	typedef std::map<std::string, int> CountMap;
	typedef std::map<std::string, int>::iterator CountMapIter;

	std::map<std::string, int> countmap;
	//for (const std::string& str : strs)
	for (const auto& str : strs) //��ʾ�ҵ��ˣ���������
	{
		//std::pair<std::map<std::string, int>::iterator, bool> ret = countmap.insert(make_pair(str, 1));
		//auto ret = countmap.insert(make_pair(str, 1));   //�ɶ��Բ�
		std::pair<CountMapIter, bool> ret = countmap.insert(make_pair(str, 1));
		if (ret.second == false)
		{
			ret.first->second++;
		}
	}

	//std::map<std::string, int> countmap;
	////for (const std::string& str : strs)
	//for (const auto& str : strs) //��ʾ�ҵ��ˣ���������
	//{
	//	countmap[str]++;
	//}


	//std::map<std::string, int>::iterator cit = countmap.begin();
	auto cit = countmap.begin(); //��д
	while (cit != countmap.end())
	{
		cout << cit->first << ":" << cit->second << endl;
		++cit;
	}
	cout << endl;

	for (const auto& kv : countmap)  //дforʱһ��Ҫ����const &,�����Ǳ���int���͵Ķ������������ٸ�ֵ����Ӱ�죩;��countmap��������ó���
	{
		cout << kv.first << ":" << kv.second << endl;
	}

	cout << endl;
}

void test_set()   //����ɾ���飻�������޸ģ��������������
{
	//���ã�1.key. ���ҹؼ����ڲ���
	//2.����+ȥ�أ�����Ѿ����ڣ����ٲ��룩Ψһ��һ��
	
	std::set<int> s;
	s.insert(4);
	s.insert(2);
	s.insert(5);
	s.insert(1);
	s.insert(3);
	s.insert(2);

	std::set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	it = s.find(3); //O(logN) �Ƽ�ʹ��
	//it = std::find(s.begin(), s.end(), 3); //O(N) ���������е�����
	if (it != s.end())
	{
		cout << "�ҵ���" << endl;
		s.erase(it);
	}

	//s.erase(it);    //�������ѭ����ʱ����3��ɾ����û��3�ͱ���
	s.erase(3);   //��3��ɾ����û��3�Ͳ�ɾ

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	//���ã�1.key. ���ҹؼ����ڲ���
	//2.����,������
	std::multiset<int> ms;   //multi�� ���򣬲����أ���֧��operator[]
	ms.insert(3);
	ms.insert(3);
	ms.insert(1);
	ms.insert(5);
	ms.insert(4);
	ms.insert(3);
	ms.insert(2);
	ms.insert(3);

	auto mit = ms.find(3);  //�ҵ�һ�������ң����ҵ����е�3�����ص�������ĵ�һ��3
	if (mit != ms.end())
	{
		cout << "�ҵ���" << endl; 
		while (*mit == 3)
		{
			cout << *mit << endl;
			++mit;
		}
	}

	for (auto e : ms)
	{
		cout << e << " ";
	}
	cout << endl;
}


int main()
{
	//test_set();
	test_map();
	system("pause");
	return 0;
}
