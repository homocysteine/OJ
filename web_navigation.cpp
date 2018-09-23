/*
命令的输入：
用cin接收string变量，并进行比对，做出相应反应
功能实现：
用数组或vector装入几个网址
back:
输出倒数第二个元素，删掉倒数第一个，并把倒数第一个push到第二个数组中
forward:
输出第二个vector中的倒数第一个元素，删掉，并把它push到第一个vector中
visit:
把新的网址push到第一个vector中，清空第二个vector
quit:exit(0)

准备两个数组
一个用来存储所拥有的网址
一个用来存储访问过的网址
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