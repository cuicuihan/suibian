#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n, m;
int kk[1000*1000];
int k[1000];
int BinarySerach(int x)
{
	int found = 0;
	int end = n * n-1, begin = 0;
	int mid = 0;
	while (end-begin>=1)
	{
		mid = (end + begin) / 2;
		if (kk[mid] == x)
			return found = 1;
		else if (kk[mid] < x)
			begin = mid + 1;
		else
			end = mid;
	}
	return found;
}

int main()
{
	int f = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i<n; i++)
		scanf("%d", &k[i]);
	int a, b, c, d;
	for(a=0;a<n;a++)
		for (b =0; b < n; b++)
		{
			kk[a*n + b] = k[a] + k[b];
		}
	sort(kk,kk + n*n);
	for(c=0;c<n;c++)
		for (d = 0; d < n; d++)
		{
			if (BinarySerach(m - k[c] - k[d]))
				f = 1;
		}
	if (f)
		printf("cunzai\n");
	else
		printf("notcunzai");
	return 0;
}
