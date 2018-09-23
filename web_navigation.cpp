/*
��������룺
��cin����string�����������бȶԣ�������Ӧ��Ӧ
����ʵ�֣�
�������vectorװ�뼸����ַ
back:
��������ڶ���Ԫ�أ�ɾ��������һ�������ѵ�����һ��push���ڶ���������
forward:
����ڶ���vector�еĵ�����һ��Ԫ�أ�ɾ����������push����һ��vector��
visit:
���µ���ַpush����һ��vector�У���յڶ���vector
quit:exit(0)

׼����������
һ�������洢��ӵ�е���ַ
һ�������洢���ʹ�����ַ
*/
#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
using namespace std;
void visit(vector<string>&history1,vector<string>&history2)
{
	string temp;
	cin >> temp;
	history1.push_back(temp);
	cout << temp << endl;
	history2.clear();
}
void back(vector<string>&history1,vector<string>&history2)
{
	if (history1.size()==1)
	{
		cout << "Ignored" << endl;
	}
	else
	{
		cout << history1[history1.size() - 2] << endl;
		history2.push_back(history1[history1.size() - 1]);
		history1.pop_back();
	}
}
void forward(vector<string>&history1,vector<string>&history2)
{
	if (history2.empty())
	{
		cout << "Ignored" << endl;
	}
	else
	{
		cout << history2[history2.size() - 1] << endl;
		history1.push_back(history2[history2.size() - 1]);
		history2.pop_back();
	}
}
void quit()
{
	cout << "Ignored" << endl;
}

int main()
{
	string temp1,temp2;
	vector<string> history1;
	vector<string>history2;
	history1.push_back("http://www.acm.org/");
	while (cin >> temp1)
	{
		if (temp1 == "VISIT")
		{
			visit(history1,history2);
		}
		if (temp1 == "BACK")
		{
			back(history1, history2);
		}
		if (temp1 == "FORWARD")
		{
			forward(history1, history2);
		}
		if (temp1 == "QUIT")
		{
			exit(0);
		}
	}
	return 0;
}