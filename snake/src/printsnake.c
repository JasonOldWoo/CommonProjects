#include "printsnake.h"

void print_snake(int map[N][N], SHEAD *snake, int fx, int fy)
{
	SNAKE *node = (SNAKE *)malloc(sizeof(SNAKE));
	node = snake->shead;
	
	while (node)
	{
		if (0==node->x || N-1==node->x || 0==node->y || N-1==node->y)
			break ;
		
		else
		{
			map[node->x][node->y] = 1;
		}
		node = node->next;
	}
	map[fx][fy] = 5;
	int i;
	int j;
	//printf("head: %d, %d\n", snake->shead->x, snake->shead->y);
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			if (map[i][j] == 1)
			{
				printf("*");
			}
			else if (map[i][j] == 10)
			{
				printf("+");
			}
			else if (map[i][j] == 5)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}
