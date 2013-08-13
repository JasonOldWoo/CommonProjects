#include "clearmap.h"


void clear_map(int map[N][N], int fx, int fy)
{
	int i;
	int j;	
	for (i=0; i<N; i++)
	{
		map[i][0] = 10;
		map[i][N-1] = 10;
		for (j=1; j<N-1; j++)
		{
			if (0==i || N-1==i)
				map[i][j] = 10;
			else
				map[i][j] = 0;
		}
	}
	//printf("check\n");
	map[fx][fy] = 5;
}

