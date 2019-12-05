【交换排序】
//选择排序（最差的排序）
//最好和最坏的时间复杂度均为：O(N^2)
//与插入排序相比，插入排序好一点，虽然是O(N^2)，只需要遍历一遍
void Swap(int *p1, int *p2)
{
	int x = *p1;
	*p1 = *p2;
	*p2 = x;
}

void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	int min_index, max_index;
	while (begin <= end)
	{
		min_index = max_index = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[i] < a[min_index])
				min_index = i;
			if (a[i]>a[max_index])
				max_index = i;
		}

		Swap(&a[begin], &a[min_index]);
		if (min_index == begin)
		{
			max_index = min_index;
		}

		Swap(&a[end], &a[max_index]);
		begin++;
		end--;
	}
}

void TestSelectSort()
{
	int a[] = { 2, 5, 8, 3, 9, 1, 6, 4, 7 };
	//int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

//*************************************************************
//堆排序：(选择排序)
void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;  //默认指向左孩子
	while (child < n)
	{
		//右孩子存在，且右孩子大于左孩子
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;
		}
		if (a[child]>a[parent])
		{
			Swap(&a[child], &a[parent]);
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	//建堆（升序建大堆；降序建小堆）,调到根就结束
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	//选择排序
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);//把堆顶的数换到最后去，堆顶和最后一个数交换
		AdjustDown(a, end, 0);//剩下的数进行向下调整，此时有n-1个数；再把堆顶的数换到n-2的位置
		end--;
	}
}
void TestHeapSort()
{
	int a[] = { 2, 5, 8, 3, 9, 1, 6, 4, 7 };
	//int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	HeapSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
//*************************************************************
//
//冒泡排序
void BubbleSort(int* a, int n)
{
	int end = n;
	while (end >0)
	{
		//单趟冒泡
		for (int i = 1; i < end-1; i++)
		{
			if (a[i-1]>a[i])
			{
				Swap(&a[i - 1], &a[i]);
			}
		}
		end--;
	}
}
void TestBubbleSort()
{
	int a[] = { 2, 5, 8, 3, 9, 1, 6, 4, 7 };
	//int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	BubbleSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
//*************************************************************
//快速排序
//<1>、左右指针法
int PartSort1(int* a, int left, int right)
{
	int key = a[right];       //以left/right为基准值key,则右边/左边先动
	int keyindex = right;  //保存基准值的下标
	while (left < right)
	{
		//left找比key大的，right找比key小
		while (left < right && a[left] <= key)
		{
			left++;
		}
		while (left < right && a[right] >= key)
		{
			right--;
		}
		if (left < right)   //left小于right，才有交换的必要
		{
			Swap(&a[left], &a[right]);
			left++;
			right--;
		}
	}
	Swap(&a[left], &a[keyindex]);

	return left;
}
//快速排序有序的时候是最坏情况，此时时间复杂度是：O(N^2)，如何优化？？
//1、随机选key(比较坑)，在有序的情况下，按照固定的方法选一个数，选最左边或者最右边，就会选到了最大或者最小的。但是随机选一个数的话，这种几率会减少很多，但是不靠谱，不确定性很多，不稳定   
//2、三数取中法：头（值最小），尾（值最大），中间（值不大不小的数）。依旧用右边的数做key值，
int GetMidIndex(int* a, int left, int right)
{
	int mid = left + (right - left) / 2;  //防止栈溢出
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left]<a[right])
		{
			return right;
		}
		else
		{
			return left;
		}
	}
	else     //a[left] < a[mid]
	{
		if (a[mid] > a[right])
		{
			return  mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return mid;
		}
	}
}
//**********************************************
//<2>、挖坑法
//先选一个key值，左边找大放在右边的坑，右边找小放在左边的坑
int PartSort2(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[mid], &a[right]);
	int key = a[right];
	while (left < right)
	{
		while (left < right && a[left] <= key)
			left++;
		a[right] = a[left];     //如果左边的数大于key值，就把它扔在右边的坑

		while (left < right && a[right] >= key)
			right--;
		a[left] = a[right];		//如果右边的数小于key值，就把它扔在左边的坑
	}
	a[left] = key;
	return left;
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;

	if (right - left +1 > 10)
	{
		//int keyindex = PartSort1(a, left, right);      //先进单趟排序
		int keyindex = PartSort2(a, left, right);      //先进单趟排序
		// [left,keyindex-1] key [keyindex+1, right]  //左右区间剩下一个数的时候就不用再比了
		QuickSort(a, left, keyindex - 1);
		QuickSort(a, keyindex + 1, right);
	}
	else
	{
		InsertSort(a + left, right - left + 1);
	}
}

void TestQuickSort()
{
	//int a[] = { 2, 5, 8, 3, 9, 1, 6, 4, 7 };
	int a[] = { 9, 5, 7, 8, 6, 1, 3, 4, 2};
	//int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	QuickSort(a, 0, sizeof(a) / sizeof(int)-1);
	PrintArray(a, sizeof(a) / sizeof(int));
}