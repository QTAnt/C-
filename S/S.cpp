//*************************************************************
//归并排序：适合用于外排序（磁盘中，大数据的排序）
//有点儿像二叉树的后续遍历
//外排序（磁盘中，大数据的排序）、内排序（内存中的排序）
//在数组中进行运算，开一个新数组，分为左右两段有序序列，然后依次比较大小，把小的数拿下来
void _MergeSort(int* a,int left, int right, int* tmp)
{
	int mid = left + (right - left) / 2;
	if (left == right)  //区间不用划分的时候
		return;
	//[left,mid][mid+1,right]区间分别有序
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid+1, right, tmp);

	//a[left,mid] a[mid+1,right]区间归并到tmp的[left, right]
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = left;
	while (begin1<=end1 && begin2<=end2)  //表示其中一个数组完了
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1];
			begin1++;
		}
		else
		{
			tmp[i++] = a[begin2];
			begin2++;
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1];
		begin1++;
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2];
		begin2++;
	}

	//走完以上代码说明全在tmp里了，再拷回原数组
	memcpy(a + left, tmp + left, sizeof(int)*(i - left));//最终i到了最后一个位置，再减left，即要拷贝的数组的大小
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);  //创建一个临时数组，时间复杂度O(N)
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}
void TestMergeSort()
{
	//int a[] = { 2, 5, 8, 3, 9, 1, 6, 4, 7 };
	int a[] = { 9, 5, 7, 8, 6, 1, 3, 4, 2 };
	MergeSort(a, sizeof(a) / sizeof(int));   
	PrintArray(a, sizeof(a) / sizeof(int));
}


//归并排序非递归：gap为2、4、8....进行排序
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)* n);
	
	//[begin1, end1][begin2, end2]
	int gap = 2;
	while (gap <= 8)
	{
		for (int begin = 0; begin < n; begin += gap)
		{
			//[begin,begin+gap-1]
			
			int end = begin + gap - 1;
			int mid = (begin + end) / 2;

			int begin1 = begin, end1 = mid, begin2 = mid + 1, end2 = end;
			int index = begin1;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
					tmp[index++] = a[begin1++];
				else
					tmp[index++] = a[begin2++];
			}

			while (begin1 <= end1)
				tmp[index++] = a[begin1++];

			while (begin2 <= end2)
				tmp[index++] = a[begin2++];
		}
		memcpy(a, tmp, sizeof(int)*n);   

		gap *= 2;
		PrintArray(a, n);
	}
	free(tmp);
}

void TestMergeSortNonR()
{
	//int a[] = { 2, 5, 8, 3, 9, 1, 6, 4, 7 };
	int a[] = { 9, 5, 7, 8, 6, 1, 3, 4, 2 };
	MergeSortNonR(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}