#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

////��һ��https://www.nowcoder.com/questionTerminal/6736cc3ffd1444a4a0057dee89be789b?orderByHotValue=1&page=1&onlyReference=false
////��Դ��ţ����
////ţţ�ٰ���һ�α�̱���, �μӱ�������3*n��ѡ��, ÿ��ѡ�ֶ���һ��ˮƽֵa_i.����Ҫ����Щѡ�ֽ������, һ�����n������, ��ÿ������3��.ţţ���ֶ����ˮƽֵ���ڸö����Ա�еڶ���ˮƽֵ��
////���� :
////һ������������Ա��ˮƽֵ�ֱ���3, 3, 3.��ô�����ˮƽֵ��3
////һ������������Ա��ˮƽֵ�ֱ���3, 2, 3.��ô�����ˮƽֵ��3
////һ������������Ա��ˮƽֵ�ֱ���1, 5, 2.��ô�����ˮƽֵ��2
////Ϊ���ñ������п���, ţţ�밲�Ŷ���ʹ���ж����ˮƽֵ�ܺ����
////��������ʾ :
////���ţţ��6����Ա���ֵ���������
////�������Ϊ :
////team1 : {1, 2, 5}, team2 : {5, 5, 8}, ��ʱ��ˮƽֵ�ܺ�Ϊ7.
////���������Ϊ :
////   team1 : {2, 5, 8}, team2 : {1, 5, 5}, ��ʱ��ˮƽֵ�ܺ�Ϊ10.
////		   û�б��ܺ�Ϊ10����ķ���, �������10.
////	   �������� :
////			����ĵ�һ��Ϊһ��������n(1 �� n �� 10 ^ 5)
////			�ڶ��а���3*n������a_i(1 �� a_i �� 10 ^ 9), ��ʾÿ������ѡ�ֵ�ˮƽֵ.
////		������� :
////			 ���һ��������ʾ���ж����ˮƽֵ�ܺ����ֵ.
//
//int main(){
//	int n;
//	while (cin >> n){
//		long long sum = 0;
//		vector<int> a(3 * n);
//		for (int i = 0; i < (3 * n); i++){
//			cin >> a[i];
//		} 
//		sort(a.begin(), a.end());
//		for (int i = n; i <= 3 * n - 2; i += 2){
//			sum += a[i];
//		} 
//		cout << sum << endl;
//	}
//}

//https://www.nowcoder.com/practice/f0db4c36573d459cae44ac90b90c6212?tpId=85&&tqId=29868&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
//���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ������磬���롱They are students.���͡�aeiou������ɾ��֮��ĵ�һ���ַ�����ɡ�Thy r stdnts.��
//�������� :
//ÿ�������������2���ַ���
//������� :
//���ɾ������ַ���

#include<iostream>
#include<string>
using namespace std;
int main()
{
	// ע�����ﲻ��ʹ��cin���գ���Ϊcin�����ո�ͽ����ˡ�
	// oj��IO�����ַ������ʹ��getline��
	string str1, str2;
	//cin>>str1;
	//cin>>str2;
	getline(cin, str1);
	getline(cin, str2);
	// ʹ�ù�ϣӳ��˼����str2ͳ���ַ����ֵĴ���
	int hashtable[256] = { 0 };
	for (size_t i = 0; i < str2.size(); ++i)
	{
		hashtable[str2[i]]++;
	}
	// ����str1��str1[i]ӳ��hashtable��Ӧλ��Ϊ0�����ʾ����ַ���
	// str2��û�г��ֹ�������+=��ret��ע��������ò�Ҫstr1.erases(i)
	// ��Ϊ�߱�������erase�����׳���
	string ret;
	for (size_t i = 0; i < str1.size(); ++i)
	{
		if (hashtable[str1[i]] == 0)
			ret += str1[i];
	}
	cout << ret << endl;
	return 0;
}