����������
//ѡ��������������
//��ú����ʱ�临�ӶȾ�Ϊ��O(N^2)
//�����������ȣ����������һ�㣬��Ȼ��O(N^2)��ֻ��Ҫ����һ��
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
//������(ѡ������)
void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;  //Ĭ��ָ������
	while (child < n)
	{
		//�Һ��Ӵ��ڣ����Һ��Ӵ�������
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
	//���ѣ����򽨴�ѣ�����С�ѣ�,�������ͽ���
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	//ѡ������
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);//�ѶѶ������������ȥ���Ѷ������һ��������
		AdjustDown(a, end, 0);//ʣ�µ����������µ�������ʱ��n-1�������ٰѶѶ���������n-2��λ��
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
//ð������
void BubbleSort(int* a, int n)
{
	int end = n;
	while (end >0)
	{
		//����ð��
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
//��������
//<1>������ָ�뷨
int PartSort1(int* a, int left, int right)
{
	int key = a[right];       //��left/rightΪ��׼ֵkey,���ұ�/����ȶ�
	int keyindex = right;  //�����׼ֵ���±�
	while (left < right)
	{
		//left�ұ�key��ģ�right�ұ�keyС
		while (left < right && a[left] <= key)
		{
			left++;
		}
		while (left < right && a[right] >= key)
		{
			right--;
		}
		if (left < right)   //leftС��right�����н����ı�Ҫ
		{
			Swap(&a[left], &a[right]);
			left++;
			right--;
		}
	}
	Swap(&a[left], &a[keyindex]);

	return left;
}
//�������������ʱ������������ʱʱ�临�Ӷ��ǣ�O(N^2)������Ż�����
//1�����ѡkey(�ȽϿ�)�������������£����չ̶��ķ���ѡһ������ѡ����߻������ұߣ��ͻ�ѡ������������С�ġ��������ѡһ�����Ļ������ּ��ʻ���ٺܶ࣬���ǲ����ף���ȷ���Ժܶ࣬���ȶ�   
//2������ȡ�з���ͷ��ֵ��С����β��ֵ��󣩣��м䣨ֵ����С���������������ұߵ�����keyֵ��
int GetMidIndex(int* a, int left, int right)
{
	int mid = left + (right - left) / 2;  //��ֹջ���
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
//<2>���ڿӷ�
//��ѡһ��keyֵ������Ҵ�����ұߵĿӣ��ұ���С������ߵĿ�
int PartSort2(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[mid], &a[right]);
	int key = a[right];
	while (left < right)
	{
		while (left < right && a[left] <= key)
			left++;
		a[right] = a[left];     //�����ߵ�������keyֵ���Ͱ��������ұߵĿ�

		while (left < right && a[right] >= key)
			right--;
		a[left] = a[right];		//����ұߵ���С��keyֵ���Ͱ���������ߵĿ�
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
		//int keyindex = PartSort1(a, left, right);      //�Ƚ���������
		int keyindex = PartSort2(a, left, right);      //�Ƚ���������
		// [left,keyindex-1] key [keyindex+1, right]  //��������ʣ��һ������ʱ��Ͳ����ٱ���
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