//**********************************************
//<3>、hoare版本：前后指针法
//最后一个值为基准值key,cur在0位置，prev在cur前一个位置。
//cur找比key值小的，找到之后，prev++，prev与cur在同一位置，cur与prev的值相互交换，此时相当于自己与自己交换，相对位置没有发生变化；如果cur找到大于key的值，则cur继续++，知道找到一个比key值小的数，此时prev再++，(此刻，cur在prev的前一个位置)，cur再与prev交换，此时，小数与大数交换，完成换位操作。以此类推......
int PartSort3(int* a, int left, int right)
{
	int key = a[right];
	int prev = left - 1;
	int cur = left;

	while (cur < right)
	{
		if (a[cur] < key && prev++ != cur)
		{
			Swap(&a[cur], &a[prev]);
		}
		cur++;
	}
	prev++;
	Swap(&a[right], &a[prev]);
	return prev;
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;

	//if (right - left + 1 > 10)
	//{
		//int keyindex = PartSort1(a, left, right);      //先进单趟排序
		//int keyindex = PartSort2(a, left, right);      //先进单趟排序
		int keyindex = PartSort3(a, left, right);      //先进单趟排序
		// [left,keyindex-1] key [keyindex+1, right]  //左右区间剩下一个数的时候就不用再比了
		QuickSort(a, left, keyindex - 1);
		QuickSort(a, keyindex + 1, right);
	//}
	//else
	//{
	//	InsertSort(a + left, right - left + 1);
	//}
}

//非递归(栈)   //调不通？奇奇怪怪
void QuickSortNonR(int* a, int left, int right)
{
	stack<int> s;
	s.push(left);
	s.push(right);
	while (!s.empty())
	{
		int end = s.top();
		s.pop();
		int begin = s.top();
		s.pop();

		int keyindex = PartSort3(0, begin, end);
		//[begin, keyindex-1] key [keyindex+1, end]
		if (begin < keyindex - 1)
		{
			s.push(begin);    //先入左，再入右，与先前的顺序保持一致
			s.push(keyindex - 1);
		}
		if (keyindex + 1 < end)
		{
			s.push(keyindex + 1);
			s.push(end);
		}
	}
}

void TestQuickSort()
{
	//int a[] = { 2, 5, 8, 3, 9, 1, 6, 4, 7 };
	int a[] = { 9, 5, 7, 8, 6, 1, 3, 4, 2};
	//int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	//QuickSort(a, 0, sizeof(a) / sizeof(int)-1);
	QuickSortNonR(a, 0, sizeof(a) / sizeof(int)-1);   //非递归
	PrintArray(a, sizeof(a) / sizeof(int));
}
//*************************************************************
//归并排序：适合用于外排序（磁盘中，大数据的排序）
//有点儿像二叉树的后续遍历
//外排序（磁盘中，大数据的排序）、内排序（内存中的排序）
//在数组中进行运算，开一个新数组，分为左右两段有序序列，然后依次比较大小，把小的数拿下来
void _MerageSort(int* a,int left, int right, int* tmp)
{
	int mid = left + (right - left) / 2;
	if (left == right)  //区间不用划分的时候
		return;
	//[left,mid][mid+1,right]区间分别有序
	_MerageSort(a, left, mid, tmp);
	_MerageSort(a, mid+1, right, tmp);

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

void MerageSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);  //创建一个临时数组，时间复杂度O(N)
	_MerageSort(a, 0, n - 1, tmp);
	free(tmp);
}
void TestMerageSort()
{
	//int a[] = { 2, 5, 8, 3, 9, 1, 6, 4, 7 };
	int a[] = { 9, 5, 7, 8, 6, 1, 3, 4, 2 };
	MerageSort(a, sizeof(a) / sizeof(int));   
	PrintArray(a, sizeof(a) / sizeof(int));
}