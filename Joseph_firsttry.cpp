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
			test = new int[2 * temp];//��̬����ռ䣬�ǵ���deleteɾȥָ��
			m = temp;
			for (;; m++)
			{
				for (int i = 0; i < 2 * temp; i++)//��ʼ�����飬0��ʾ��-1��ʾ����
					test[i] = 0;
				int flag = 0;
				int i = 0;
				for (int k = 0; k < temp; k++) 
				{
					while(true)
					{
						if (i >= 2 * temp)//ѭ��������
							i = i % (2 * temp);
						if (test[i] == 0)
							count++;
						if (count == m)
						{
							test[i] = -1;//����
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