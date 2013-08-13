#include "movesnake.h"

void move_snake(SHEAD *snake, char *ch)
{

	SNAKE *node = snake->shead;
	int hx = node->x;
	int hy = node->y;
	int x = node->next->x;
	int y = node->next->y;
	
	while (node->next)
	{
		node = node->next;
	}
	node->pre->next = NULL;
	free(node);
	SNAKE *newNode = (SNAKE *)malloc(sizeof(SNAKE));

	newNode->next = snake->shead;
	snake->shead->pre = newNode;
	snake->shead = newNode;
	
	if (*ch == 'w' && (hy - y))
	{
		newNode->x = hx - 1;
		newNode->y = hy;
	}

	else if (*ch == 's' && (hy - y))
	{
		newNode->x = hx + 1;
		newNode->y = hy;
	}
	
	else if (*ch == 'a' && (hx - x))
	{
		newNode->y = hy - 1;
		newNode->x = hx;
	}

	else if (*ch == 'd' && (hx - x))
	{
		newNode->y = hy + 1;
		newNode->x = hx;
	}
	
	else
	{
		newNode->x = hx+hx-x;
		newNode->y = hy+hy-y;
	}


}
