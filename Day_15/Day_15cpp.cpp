#include <iostream>
#include <vector>
using namespace std;

//��һ��
//https://www.nowcoder.com/practice/1b46eb4cf3fa49b9965ac3c2c1caf5ad?tpId=37&&tqId=21285&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
//��ʵ�����½ӿ�
//public   static   int  findNumberOf1(int num)
//{
//	/*  ��ʵ��  */
//	return  0;
//} Ʃ�磺����5 ��5�Ķ�����Ϊ101�����2
//
//�漰֪ʶ�㣺
//�������� :
//����һ������
//������� :
//����������������1�ĸ���
//ʾ��1
//����
//����
//5
//���
//����
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

//�����
//https://www.nowcoder.com/practice/365d5722fff640a0b6684391153e58d8?tpId=49&&tqId=29337&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
//�ڵ����������n����ɫ�����ף����׷������֣�����ÿ����ɫ�����������׸�����һ����ͬ��A��������Ҫ���ţ�������Ҫȥ������ѡ���ס����ǻ谵�ĵƹ������޷��ֱ����׵���ɫ��ֻ�ֱܷ�������֡������������һЩ���ף�Ȼ��ѡ��һ˫��ɫ��ͬ�����������ס����ڵ������ǣ�������Ҫ�ö���ֻ����(���ּ�����)�����ܱ�֤һ����ѡ��һ˫��ɫ��ͬ�����ס�
//
//������ɫ����n(1��n��13), ͬʱ������������Ϊn������left, right, �ֱ����ÿ����ɫ���������׵����������ݱ�֤���ҵ�����������������26����һ����������һ�ֺϷ�������
//
//����������
//4, [0, 7, 1, 6], [1, 5, 0, 6]
//���أ�10(���ͣ�������������ȡ2ֻ����������ȡ8ֻ)

class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		// write code here

	//************ע�⣺�����������
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
		//����ÿһ����ɫ��������������
		for (int i = 0; i<n; i++){
			//������0���ڵ���ɫ���ף��ۼ�
			if (left[i] * right[i] == 0)
				sum += left[i] + right[i];
			//���������ֶ��е���ɫ���ף�ִ������Ĳ���
			//�ҵ���Сֵ������
			else{
				left_sum += left[i];
				right_sum += right[i];
				left_min = min(left_min, left[i]);
				right_min = min(right_min, right[i]);
			}
		} 
		// ���Ϊ�����Ҷ����������������еĽ�� + ��0���ڵ������� + ����ټ�һ�϶����ܱ�֤��
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
//ѡ������********************************************************************************
//#include <stdio.h>
//#include <stdlib.h>
//void print(int* array, int size)//��ӡ����
//
//{
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", array[i]);
//	}
//
//	printf("\n");
//}
//void Swap(int* p1, int* p2)//ֵ��������
//
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//
//void SelectSort(int* a, int size)    //ѡ������
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