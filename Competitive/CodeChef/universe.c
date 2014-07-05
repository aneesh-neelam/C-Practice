#include <stdio.h>
int main()
{
	int n[100000];
	int c1 = 0;
	int c2 = 0;
	do
	{
		scanf("%d", &n[c1]);
		c1++;
	}while(n[c1-1]!=42);

	for(c2 = 0; c2 < c1-1; c2++)
	{
		printf("%d\n", n[c2]);
	}
	return 0;
}

