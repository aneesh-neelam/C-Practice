#include <stdio.h>

int main()
{
	long long N, M;
	long long a[10000];
	long long b[10000];
	long long k[10000];
	long long j[10000] = {0};
	long long i;
	long long avg, sum;
	long long avgi;
	long long c2;
	scanf("%Ld", &N);
	scanf("%Ld", &M);
	for(i = 0; i < M; i++)
	{
		scanf("%Ld", &a[i]);
		scanf("%Ld", &b[i]);
		scanf("%Ld", &k[i]);
	}
	for(i = 0; i < M; i++)
	{
		for(c2 = a[i]-1; c2 < b[i]; c2++)
		{
			j[c2] = j[c2] + k[i];
		}
	}
	sum = 0;
	for(i = 0; i < N; i++)
	{
		sum = sum + j[i];
	}
	avg = sum / N;
	printf("%Ld", avg);
	return 0;
}

