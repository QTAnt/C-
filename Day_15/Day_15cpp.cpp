#include <iostream>
#include <vector>
using namespace std;

//编一：
//https://www.nowcoder.com/practice/1b46eb4cf3fa49b9965ac3c2c1caf5ad?tpId=37&&tqId=21285&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
//请实现如下接口
//public   static   int  findNumberOf1(int num)
//{
//	/*  请实现  */
//	return  0;
//} 譬如：输入5 ，5的二进制为101，输出2
//
//涉及知识点：
//输入描述 :
//输入一个整数
//输出描述 :
//计算整数二进制中1的个数
//示例1
//输入
//复制
//5
//输出
//复制
//2

#include<iostream>
using namespace std;
int main(){
	int n;
	while (cin >> n)
	{
		int count = 0;
		while (n)
		{
			if ((n & 1) == 1)
				count += 1;
			n >>= 1;
		}
		cout << count << endl;
	} return 0;
}

//编二：
//https://www.nowcoder.com/practice/365d5722fff640a0b6684391153e58d8?tpId=49&&tqId=29337&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
//在地下室里放着n种颜色的手套，手套分左右手，但是每种颜色的左右手手套个数不一定相同。A先生现在要出门，所以他要去地下室选手套。但是昏暗的灯光让他无法分辨手套的颜色，只能分辨出左右手。所以他会多拿一些手套，然后选出一双颜色相同的左右手手套。现在的问题是，他至少要拿多少只手套(左手加右手)，才能保证一定能选出一双颜色相同的手套。
//
//给定颜色种数n(1≤n≤13), 同时给定两个长度为n的数组left, right, 分别代表每种颜色左右手手套的数量。数据保证左右的手套总数均不超过26，且一定存在至少一种合法方案。
//
//测试样例：
//4, [0, 7, 1, 6], [1, 5, 0, 6]
//返回：10(解释：可以左手手套取2只，右手手套取8只)

class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		// write code here

	//************注意：以下题解有误
	//	int count = 0;
	//	int sum = 0;
	//	int max;
	//	int m;
	//	vector<int>::iterator itl = left.begin();
	//	while (itl != left.end())
	//	{
	//		if (*itl != 0)
	//		{
	//			count++;
	//		}
	//		itl++;
	//	}
	//	vector<int>::iterator itr = right.begin();
	//	while (itr != right.end())
	//	{
	//		itr++;
	//		max = right[0];
	//		if (*itr > max)
	//		{
	//			max = *itr;
	//		}
	//		sum += *itr;
	//	}
	//}

	//int m = sum - max + 1 + count;
	//return  m;
	

		int left_sum = 0, left_min = INT_MAX;
		int right_sum = 0, right_min = INT_MAX;
		int sum = 0;
		//遍历每一种颜色的左右手套序列
		for (int i = 0; i<n; i++){
			//对于有0存在的颜色手套，累加
			if (left[i] * right[i] == 0)
				sum += left[i] + right[i];
			//对于左右手都有的颜色手套，执行上面的策略
			//找到最小值和总数
			else{
				left_sum += left[i];
				right_sum += right[i];
				left_min = min(left_min, left[i]);
				right_min = min(right_min, right[i]);
			}
		} 
		// 结果为有左右都有数量的手套序列的结果 + 有0存在的手套数 + 最后再加一肯定就能保证了
			return sum + min(left_sum - left_min + 1, right_sum - right_min + 1) + 1;
	}
};

//int main()
//{
//	/*left.PushBack('0');
//	Gloves::findMinimum(4,[0, 7, 1, 6],[1, 5, 0, 6]);*/
//	vector<int> v1;
//	v1.push_back(0);
//	v1.push_back(7);
//	v1.push_back(1);
//	v1.push_back(6);
//
//	vector<int> v2;
//	v2.push_back(1);
//	v2.push_back(5);
//	v2.push_back(0);
//	v2.push_back(6);
//
//	int n = 4;
//
//	Gloves gloves;
//	int num = gloves.findMinimum(n, v1, v2);
//	cout << num << endl;
//
//
//	system("pause");
//	return 0;
//}
//
//
//
//选择排序********************************************************************************
//#include <stdio.h>
//#include <stdlib.h>
//void print(int* array, int size)//打印函数
//
//{
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", array[i]);
//	}
//
//	printf("\n");
//}
//void Swap(int* p1, int* p2)//值交换函数
//
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//
//void SelectSort(int* a, int size)    //选择排序
//{
//	int begin = 0, end = size - 1;
//	int min = begin, max = begin;
//	while (begin < end)
//	{
//		min = max = begin;
//		for (int i = begin; i < end; i++)
//		{
//			if (a[i] < a[min])
//			{
//				min = i;
//			}
//
//			if (a[i] > a[max])
//
//			{
//				max = i;
//			}
//		}
//		Swap(&a[begin], &a[min]);
//		print(a, size);
//
//		if (begin == max)
//		{
//			min = max;
//		}
//
//		Swap(&a[end], &a[max]);
//		print(a, size);
//		begin++;
//		end--;
//	}
//}
//
//int main()
//{
//	//int a[] = { 21, 32, 5, 5, 76, 34, 89, 12, 65, 34 };
//	int a[] = { 21, 32, 5, 15, 76, 34, 89, 12, 65, 37 };
//	SelectSort(a, 10);
//	print(a, 10);
//
//	return 0;
//}