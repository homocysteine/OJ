/*
逆序计算：
将碱基放进一个String中
从这个数组中的第二个元素开始，针对每一个元素，把这个元素前边的所有元素遍历一遍
如果被针对的元素是A，那么它前面出现一次C或G或T则逆序加1
如果被针对的元素是C，那么它前面出现一次G或T则逆序加1
如果被针对的元素是G，那么它前面出现一次T则逆序加1
如果被针对的元素是T，那么不用管它。。。。。
计算实现：
用两层循环，外层循环负责更换被针对的元素，内层循环用来遍历该元素之前的所有元素
输入：
用cin接受两个整型变量n,m
利用一个数组，数组中的每个元素是string类的
m是数组的申请长度，可以用在输入的循环条件中
（或者用二维数组，cin变量设为char类型？）经试验，就是它了！？

结构体里放一个一维数组加一个存储逆序数的整型变量

数据绑定：
定义一个结构体，结构体里放一个一维数组，用来放碱基；还放一个整型变量，用来存放逆序数
结构体类是一个数组，用来切换不同的行
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
	int n, m;//n是碱基序列长度，m是碱基序列条数
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