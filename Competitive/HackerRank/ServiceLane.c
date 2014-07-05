#include <stdio.h>
int main()
{
	int t;
	int l;
	int w[100000];
	int i[1000], j[1000];
	int max[1000];
	int c1, c2;
	scanf("%d", &l);
	scanf("%d", &t);
	for(c1 = 0; c1 < l; c1++)
	{
		scanf("%d", &w[c1]);
	}
	for(c1 = 0; c1 < t; c1++)
	{
		scanf("%d", &i[c1]);
		scanf("%d", &j[c1]);
	}
	for(c1 = 0; c1 < t; c1++)
	{
		max[c1] = 3;
		for(c2 = i[c1]; c2 <= j[c1]; c2++)
		{
			if(w[c2] < max[c1])
			{
				max[c1] = w[c2];
			}
		}
		printf("%d\n", max[c1]);
	}
	return 0;
}

