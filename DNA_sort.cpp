/*
������㣺
������Ž�һ��String��
����������еĵڶ���Ԫ�ؿ�ʼ�����ÿһ��Ԫ�أ������Ԫ��ǰ�ߵ�����Ԫ�ر���һ��
�������Ե�Ԫ����A����ô��ǰ�����һ��C��G��T�������1
�������Ե�Ԫ����C����ô��ǰ�����һ��G��T�������1
�������Ե�Ԫ����G����ô��ǰ�����һ��T�������1
�������Ե�Ԫ����T����ô���ù�������������
����ʵ�֣�
������ѭ�������ѭ�������������Ե�Ԫ�أ��ڲ�ѭ������������Ԫ��֮ǰ������Ԫ��
���룺
��cin�����������ͱ���n,m
����һ�����飬�����е�ÿ��Ԫ����string���
m����������볤�ȣ��������������ѭ��������
�������ö�ά���飬cin������Ϊchar���ͣ��������飬�������ˣ���

�ṹ�����һ��һά�����һ���洢�����������ͱ���

���ݰ󶨣�
����һ���ṹ�壬�ṹ�����һ��һά���飬�����ż��������һ�����ͱ������������������
�ṹ������һ�����飬�����л���ͬ����
*/


/*#include<iostream>
using namespace std;
int main()
{
	char* p = new char[5];
	for (int i = 0; i < 5; i++)
	{
		cin >> p[i];
	}
	for (int i=0;i<5;i++)
		cout << p[i] << endl;
	cin.get();
	cin.get();
	return 0;
}*/
#include<iostream>
using namespace std;
struct Sequence
{
	char* base=new char[51];
	int reverse = 0;
};
void swap(Sequence& a, Sequence& b)
{
	Sequence temp = a;
	a = b;
	b = temp;
}
int partition(Sequence A[], int p, int q)
{
	int x = A[p].reverse;
	int i, j;
	i = p;
	for (j = p + 1; j <= q; j++)
	{
		if (A[j].reverse <= x)
		{
			i++;
			swap(A[j], A[i]);
		}
	}
	swap(A[p], A[i]);
		return i;
}
void quickSort(Sequence A[], int p, int q)
{
	if (p < q)
	{
		int r = partition(A, p, q);
		quickSort(A, p, r - 1);
		quickSort(A, r + 1, q);
	}
}
int main() 
{
	int n, m;//n�Ǽ�����г��ȣ�m�Ǽ����������
	cin >> n >> m;
	const int num = m;
	Sequence* sequence=new Sequence[101];
	for(int i=0;i<m;i++)
		for (int j = 0; j < n; j++)
		{
			cin >> sequence[i].base[j];
		}
	for (int i = 0; i<m; i++)
		for (int j = 1; j < n; j++)
		{
			for (int k = 0; k < j; k++)
			{
				if ('A' == sequence[i].base[j])
					if ('C' == sequence[i].base[k] || 'G' == sequence[i].base[k] || 'T' == sequence[i].base[k])
						sequence[i].reverse++;
				if ('C' == sequence[i].base[j])
					if ('G' == sequence[i].base[k] || 'T' == sequence[i].base[k])
						sequence[i].reverse++;
				if ('G' == sequence[i].base[j])
					if ('T' == sequence[i].base[k])
						sequence[i].reverse++;
			}
		}
	quickSort(sequence, 0, m - 1);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << sequence[i].base[j];
		}
		cout << endl;
	}
	cin.get();
	cin.get();
	return 0;
}