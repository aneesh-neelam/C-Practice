#include <stdio.h>

int main()
{
	long long fact(long long);
	long long t;
	long long a[10000];
	long long i;
	scanf("%Ld", &t);
	for(i = 0; i < t; i++)
	{
		scanf("%Ld", &a[i]);
	}
	for(i = 0; i < t; i++)
	{
		printf("%Ld\n", fact(a[i]));
	}
	return 0;
}

long long fact(long long n)
{
	if(n <= 0) return 1;
	else return n * fact(n - 1);
}

