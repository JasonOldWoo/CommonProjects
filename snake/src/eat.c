#include "eat.h"

int eat(SHEAD *snake, int map[N][N])
{
	SNAKE *node = snake->shead;
	if (map[node->x][node->y]!=5)
	{
		return 0;
	}
	else
	{
		map[node->x][node->y] = 0;
		while (node->next)
			node = node->next;
		SNAKE *newNode = (SNAKE *)malloc(sizeof(SNAKE));
		newNode->pre = node;
		node->next = newNode;
		newNode->next = NULL;
		newNode->x = node->x + node->x - node->pre->x;
		newNode->y = node->y + node->y - node->pre->y;
		return 1;
	}
	
}
