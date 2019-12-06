//**********************************************
//<3>��hoare�汾��ǰ��ָ�뷨
//���һ��ֵΪ��׼ֵkey,cur��0λ�ã�prev��curǰһ��λ�á�
//cur�ұ�keyֵС�ģ��ҵ�֮��prev++��prev��cur��ͬһλ�ã�cur��prev��ֵ�໥��������ʱ�൱���Լ����Լ����������λ��û�з����仯�����cur�ҵ�����key��ֵ����cur����++��֪���ҵ�һ����keyֵС��������ʱprev��++��(�˿̣�cur��prev��ǰһ��λ��)��cur����prev��������ʱ��С���������������ɻ�λ�������Դ�����......
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
		//int keyindex = PartSort1(a, left, right);      //�Ƚ���������
		//int keyindex = PartSort2(a, left, right);      //�Ƚ���������
		int keyindex = PartSort3(a, left, right);      //�Ƚ���������
		// [left,keyindex-1] key [keyindex+1, right]  //��������ʣ��һ������ʱ��Ͳ����ٱ���
		QuickSort(a, left, keyindex - 1);
		QuickSort(a, keyindex + 1, right);
	//}
	//else
	//{
	//	InsertSort(a + left, right - left + 1);
	//}
}

//�ǵݹ�(ջ)   //����ͨ������ֹ�
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
			s.push(begin);    //�����������ң�����ǰ��˳�򱣳�һ��
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
	QuickSortNonR(a, 0, sizeof(a) / sizeof(int)-1);   //�ǵݹ�
	PrintArray(a, sizeof(a) / sizeof(int));
}
//*************************************************************
//�鲢�����ʺ����������򣨴����У������ݵ�����
//�е����������ĺ�������
//�����򣨴����У������ݵ����򣩡��������ڴ��е�����
//�������н������㣬��һ�������飬��Ϊ���������������У�Ȼ�����αȽϴ�С����С����������
void _MerageSort(int* a,int left, int right, int* tmp)
{
	int mid = left + (right - left) / 2;
	if (left == right)  //���䲻�û��ֵ�ʱ��
		return;
	//[left,mid][mid+1,right]����ֱ�����
	_MerageSort(a, left, mid, tmp);
	_MerageSort(a, mid+1, right, tmp);

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

void MerageSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);  //����һ����ʱ���飬ʱ�临�Ӷ�O(N)
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