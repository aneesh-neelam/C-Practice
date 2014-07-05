#include <stdio.h>
#include <math.h>

int main()
{
	int checkFib(long int);
	long int n[10000];
	int t, i;
	scanf("%d", &t);
	for(i = 0; i < t; i++)
	{
		scanf("%ld", &n[i]);
	}
	for(i = 0; i < t; i++)
	{
		if(checkFib(n[i]))
		{
			printf("IsFibo\n");
		}
		else
		{
			printf("IsNotFibo\n");
		}
	}
	return 0;
}

int checkFib(long int n)
{
	long int isPerfectSquare(long int);
	if(isPerfectSquare(5*n*n + 4) || isPerfectSquare(5*n*n - 4))
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

long int isPerfectSquare(long int n)
{
	long int s = sqrt(n);
	if(s*s == n)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

