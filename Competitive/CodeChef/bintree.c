#include <stdio.h>

int main()
{
	long long dist(long long, long long);
	long long n;
	long long a[10000], b[10000];
	long long i, j;
	scanf("%Ld", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%Ld", &a[i]);
		scanf("%Ld", &b[i]);
	}
	for(i = 0; i < n; i++)
	{
		printf("%Ld\n", dist(a[i], b[i]));
	}
	return 0;
}

long long dist(long long a, long long b)
{
	int count;
	while(a != b)
	{
		if(a > b)
		{
			a = a >> 1;
			count += 1;
		}
		else
		{
			b = b >> 1;
			count += 1;
		}
	}
	return count;	
}

