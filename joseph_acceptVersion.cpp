#include <cstdio>
bool check(int m, int k)
{
	int sum = m * 2;
	int pos;
	pos = (k % sum == 0) ? sum : (k % sum);
	if (pos <= m)		//льепр╩об 
		return false;
	sum--;
	while (1)
	{
		pos = (k - (sum - pos + 1)) % sum;
		pos = pos == 0 ? sum : pos;
		sum--;
		if (pos <= m)
			return false;
		if (sum == m)
			return true;
	}
}
int main()
{
	int n;
	int l, r, mid;
	int ans[20] = { 0,2,7,5,30 };
	for (int i = 5; i <= 13; i++)
	{
		for (int j = i + 1; ; j++)
		{
			if (check(i, j))
			{
				ans[i] = j;
				break;
			}
		}
	}
	while (~scanf("%d", &n) && n)
		printf("%d\n", ans[n]);
	return 0;
}