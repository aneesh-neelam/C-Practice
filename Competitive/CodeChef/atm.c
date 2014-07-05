#include <stdio.h>
int main()
{
	float acc;
	int tw;
	float ch = 0.50;
	float fin;
	scanf("%d%f", &tw, &acc);
	if(acc < (tw + ch) || tw % 5 != 0)
	{
		printf("%f", acc);
	}
	else if((acc + ch) > tw)
	{
		fin = acc - ch - tw;
		printf("%.2f", fin);
	}
	return 0;
}

