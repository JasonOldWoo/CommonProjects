#include "insertnode.h"

void insert_node(SHEAD *snake, int x, int y)
{
	SNAKE *node = (SNAKE *)malloc(sizeof(SNAKE));
	node = snake->shead;
	while (node->next)
		node = node->next;
	SNAKE *newNode = (SNAKE *)malloc(sizeof(SNAKE));
	newNode->pre = node;
	newNode->next = NULL;
	node->next = newNode;
	
	newNode->x = x;
	newNode->y = y;
}
