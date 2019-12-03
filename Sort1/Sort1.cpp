Sort.h

#pragma once 
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//��������ʱ�临�Ӷ�O(N^2) ����> [gapΪ1��ϣ������]
//��ã�˳������ O(N) ���������� O(N^2)
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		//a[end+1]����a[0]-a[end]��������
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}
void TestInsertSort()
{
	int a[] = { 2, 5, 8, 3, 9, 1, 6, 4, 7 };
	InsertSort(a, sizeof(a)/sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

//*************************************************************
//ϣ������(��С��������)
//Ԥ���򣺽ӽ����򣻲�������
//д��һ(Ԥ����)
//void ShellSort(int* a, int n)
//{
//	//���Ϊgap������
//	int end;
//	int gap = 3;
//	int tmp = a[end + gap];
//	for (int i = 0; i < n - 1; i++)
//	{
//		while (end >= 0)
//		{
//			if (tmp < a[end])
//			{
//				a[end + gap] = a[end];
//				end -= gap;
//			}
//			else
//			{
//				break;
//			}
//		}
//		a[end + gap] = tmp;
//	}
//}
//д��������׼д��
//gapԽ��Խ��
void ShellSort(int* a, int n)
{
	//���Ϊgap������
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1; // +1��֤�����һ�ε�gap=1
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
	
}
void TestShellSort()
{
	int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestOP()
{
	srand(time(0));   //ϵͳʱ��
	const int N = 100000;
	int *a1 = (int*)malloc(sizeof(int)*N);
	int *a2 = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++)
	{
		a1[i] = rand();
		a2[i] = a1[i];
	}
	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	free(a1);
	free(a2);
}

//*************************************************************
Test.cpp
#include "Sort.h"
int main()
{
	//TestInsertSort();
	//TestShellSort();
	TestOP();
	system("pause");
	return 0;
}