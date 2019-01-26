#include<iostream>
using namespace std;

int main()
{
	int temp,count=0,m;
	int *test;
	while (cin >> temp) {
		if (temp == 0)
			return 0;
		else
		{
			test = new int[2 * temp];//动态分配空间，记得用delete删去指针
			m = temp;
			for (;; m++)
			{
				for (int i = 0; i < 2 * temp; i++)//初始化数组，0表示存活，-1表示死亡
					test[i] = 0;
				int flag = 0;
				int i = 0;
				for (int k = 0; k < temp; k++) 
				{
					while(true)
					{
						if (i >= 2 * temp)//循环的数组
							i = i % (2 * temp);
						if (test[i] == 0)
							count++;
						if (count == m)
						{
							test[i] = -1;//死亡
							count = 0;
							break;
						}
						i++;
					}
					if (i < temp)
					{
						flag = 1;
						break;
					}
					i++;
				}
				if (flag == 1)
					continue;
				else
					break;
			}
			cout << m << endl;
		}
	}
	return 0;
}