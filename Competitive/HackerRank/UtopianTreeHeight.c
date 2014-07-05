#include <stdio.h>
int main()
{
	int t;
	int n[10];
	int h[10];
	int i, j;
	scanf("%d", &t);
	for(i = 0; i < t; i++)
	{
		scanf("%d", &n[i]);
	}
	for(i = 0; i < t; i++)
	{
		h[i] = 1;
		for(j = 0; n[i]>0; n[i]--)
		{
			if(j == 0)
			{
				h[i] = h[i] * 2;
				j = 1;
			}
			else if(j == 1)
			{
				h[i] = h[i] + 1;
				j = 0;
			}
		}
		printf("%d\n", h[i]);
	}
	return 0;
}

