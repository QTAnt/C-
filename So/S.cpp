//*************************************************************
//�鲢�����ʺ����������򣨴����У������ݵ�����
//�е����������ĺ�������
//�����򣨴����У������ݵ����򣩡��������ڴ��е�����
//�������н������㣬��һ�������飬��Ϊ���������������У�Ȼ�����αȽϴ�С����С����������
void _MergeSort(int* a,int left, int right, int* tmp)
{
	int mid = left + (right - left) / 2;
	if (left == right)  //���䲻�û��ֵ�ʱ��
		return;
	//[left,mid][mid+1,right]����ֱ�����
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid+1, right, tmp);

	//a[left,mid] a[mid+1,right]����鲢��tmp��[left, right]
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = left;
	while (begin1<=end1 && begin2<=end2)  //��ʾ����һ����������
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

	//�������ϴ���˵��ȫ��tmp���ˣ��ٿ���ԭ����
	memcpy(a + left, tmp + left, sizeof(int)*(i - left));//����i�������һ��λ�ã��ټ�left����Ҫ����������Ĵ�С
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);  //����һ����ʱ���飬ʱ�临�Ӷ�O(N)
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


//�鲢����ǵݹ飺gapΪ2��4��8....��������
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