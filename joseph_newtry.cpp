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
	for (int i = 0; i <size/2; i++)//ǰһ���Ǻ���
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
	//����k
	//����һ��2*k��˳���
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
			//���m
			for (;; m++)
			{
				initList(list, 2 * input);
				int pos = 1;
				for (int j = 0; j < input; j++)
				{
					pos = (pos - 1 + m) % list.length;//�����pos�����������ţ��±�+1
					if (pos == 0)
						pos = list.length;
					if (list.elem[pos - 1] == 0)//����ں�������
						break;//��ǰ����
					deleteList(list, pos);//������ں������ڣ���ɾ���������
					//һ������̭����һ��Ҫ�ӱ���̭����һλ��ʼ
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