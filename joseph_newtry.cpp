#include<iostream>
using namespace std;
#define OK 0
#define ERROR -1
#define OVERFLOW -2
typedef int Status;
typedef struct
{
	int *elem;
	int length;
	int listSize;
}SqList;

void initList(SqList &L,int size)
{
	L.elem = (int*)malloc(size * sizeof(int));
	L.length = size;
	L.listSize = size;
	for (int i = 0; i <size/2; i++)//前一半是好人
		L.elem[i] = 0;
}

Status deleteList(SqList &L,int i)
{
	int *p, *q;
	if (i<1 || i>L.length)
		return ERROR;
	p = &(L.elem[i - 1]);
	q = &(L.elem[L.length - 1]);
	for (; p <= q; p++)
	{
		*p = *(p + 1);
	}
	L.length--;
	return OK;
}

int main()
{
	int input,m;
	SqList list;
	//输入k
	//开辟一个2*k的顺序表
	while (true) 
	{
		cin >> input;
		if (input == 0)
			return 0;
		else if (input < 0 || input >= 14)
			cout << 0 << endl;
		else 
		{
			m = input;
			//穷举m
			for (;; m++)
			{
				initList(list, 2 * input);
				int pos = 1;
				for (int j = 0; j < input; j++)
				{
					pos = (pos - 1 + m) % list.length;//这里的pos算出来的是序号，下标+1
					if (pos == 0)
						pos = list.length;
					if (list.elem[pos - 1] == 0)//如果在好人区内
						break;//提前结束
					deleteList(list, pos);//如果不在好人区内，先删除掉这个人
					//一个被淘汰后下一个要从被淘汰的下一位开始
				}
				if (list.length == input)
					break;
				else
				{
					free(list.elem);
					continue;
				}

			}
			cout << m << endl;
		}
	}
	return 0;
}