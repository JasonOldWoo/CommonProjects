#include "createfood.h"


void create_food(int *fx, int *fy, SHEAD *snake, int eat)
{
	if (eat)
	{
		srand(time(NULL));
		int rep = 0;
		SNAKE *node = snake->shead;
		//printf("check\n");
		while (1)
		{
			//printf("check\n");
			*fx = random()%(N-2)+1;
			*fy = random()%(N-2)+1;
			
			//printf("check\n");
			while (node)
			{
				//printf("check:%d, %d\n", node->x, node->y);
				
				if (node->x==(*fx) && node->y==(*fy))
				{
					rep = 1;
					break;
				}
				//printf("check\n");
				node = node->next;
				//printf("check\n");
			}
			if (rep == 1)
			{
				node = snake->shead;
				rep = 0;
				continue;
			}
			break;
		}
	}
}
