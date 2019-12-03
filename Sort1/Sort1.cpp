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

//插入排序：时间复杂度O(N^2) ——> [gap为1的希尔排序]
//最好：顺序有序 O(N) ；最坏：逆序最坏 O(N^2)
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		//a[end+1]插入a[0]-a[end]有序区间
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
//希尔排序(缩小增量排序)
//预排序：接近有序；插入排序
//写法一(预排序)
//void ShellSort(int* a, int n)
//{
//	//间距为gap的排序
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
//写法二：标准写法
//gap越大，越快
void ShellSort(int* a, int n)
{
	//间距为gap的排序
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1; // +1保证了最后一次的gap=1
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
	srand(time(0));   //系统时间
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