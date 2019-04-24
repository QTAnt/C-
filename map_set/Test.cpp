#include <iostream>
#include <string>
using namespace std;

//左子树的所有值小于根节点，右子树的所有值大于根节点

#include <map>
#include <set>

template<class K, class V>
struct pair
{
	K first;
	V second;

	//构造函数
};

template<class K, class V>
inline std::pair<K, V> make_pair(const K& k, const V& v)
{
	return std::pair<K, V>(k, v);
}

void test_map()
{
	//1.key./value. 通过关键字查找映射信息value（项目里通过页号寻找span）
	//pair是一个有两个模板参数的结构体，分别是first(key)、second(value)
	std::map<std::string, std::string> dict;

	//std::pair<std::string, std::string>：模板类+参数
	dict.insert(std::pair<std::string, std::string>("sort", "排序"));	
	dict.insert(std::make_pair("string", "字符串")); //函数模板：std::make_pair ,自动退出类型
	dict.insert(std::make_pair("left", "左边")); 
	dict.insert(std::make_pair("left", "剩余"));  
	//结果是“左边”，插入的时候只看key,key有了就不再插入了；value相不相同不重要
	dict["pair"];
	dict["key"] = "关键字"; 
	dict["pair"] = "剩余";

	std::map<std::string, std::string>::iterator dit = dict.begin();
	while (dit != dict.end())
	{
		//cout << (*dit).first << ":" << (*dit).second << endl; 
		//pair不支持输出，不能直接应用*dit;与list的很像;dic是一个迭代器，解引用是里面的数据，该数据是一个pair，pair有一个first，有一个second
		cout << dit->first << ":" << dit->second << endl;  //推荐用这种形式写
		++dit;
	}
	cout << endl;

	//统计水果出现的次数
	std::string strs[] = { "苹果", "苹果", "香蕉", "桃子", "香蕉", "桃子", "西瓜", "苹果" };
	//std::map<std::string, int> countmap;   //水果名字，水果数量
	//for (const auto& str : strs) //表示找到了，数量增加
	//{
	//	auto it = countmap.find(str);
	//	if (it != countmap.end())
	//	{
	//		//(*it).second++;//返回的是引用
	//		it->second++;//返回的是指针,省略了一个->
	//	}
	//	else //表示没有，没有就插入
	//	{
	//		countmap.insert(make_pair(str, 1));
	//	}
	//}


	//**************************************************************************************

	typedef std::map<std::string, int> CountMap;
	typedef std::map<std::string, int>::iterator CountMapIter;

	std::map<std::string, int> countmap;
	//for (const std::string& str : strs)
	for (const auto& str : strs) //表示找到了，数量增加
	{
		//std::pair<std::map<std::string, int>::iterator, bool> ret = countmap.insert(make_pair(str, 1));
		//auto ret = countmap.insert(make_pair(str, 1));   //可读性差
		std::pair<CountMapIter, bool> ret = countmap.insert(make_pair(str, 1));
		if (ret.second == false)
		{
			ret.first->second++;
		}
	}

	//std::map<std::string, int> countmap;
	////for (const std::string& str : strs)
	//for (const auto& str : strs) //表示找到了，数量增加
	//{
	//	countmap[str]++;
	//}


	//std::map<std::string, int>::iterator cit = countmap.begin();
	auto cit = countmap.begin(); //简写
	while (cit != countmap.end())
	{
		cout << cit->first << ":" << cit->second << endl;
		++cit;
	}
	cout << endl;

	for (const auto& kv : countmap)  //写for时一定要带上const &,除非是遍历int类型的东西（拷引用再赋值，不影响）;把countmap里的数据拿出来
	{
		cout << kv.first << ":" << kv.second << endl;
	}

	cout << endl;
}

void test_set()   //增、删、查；（不能修改）绝大多数，常用
{
	//作用：1.key. 查找关键字在不在
	//2.排序+去重（如果已经存在，则不再插入）唯一的一个
	
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

	it = s.find(3); //O(logN) 推荐使用
	//it = std::find(s.begin(), s.end(), 3); //O(N) ：适于所有迭代器
	if (it != s.end())
	{
		cout << "找到了" << endl;
		s.erase(it);
	}

	//s.erase(it);    //该语句在循环外时，有3就删除，没有3就报错
	s.erase(3);   //有3就删除，没有3就不删

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	//作用：1.key. 查找关键字在不在
	//2.排序,不查重
	std::multiset<int> ms;   //multi多 排序，不查重；不支持operator[]
	ms.insert(3);
	ms.insert(3);
	ms.insert(1);
	ms.insert(5);
	ms.insert(4);
	ms.insert(3);
	ms.insert(2);
	ms.insert(3);

	auto mit = ms.find(3);  //找到一个继续找，可找到所有的3，返回的是中序的第一个3
	if (mit != ms.end())
	{
		cout << "找到了" << endl; 
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
