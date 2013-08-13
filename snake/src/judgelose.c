#include "judgelose.h"


int judge_lose(int map[N][N], SHEAD *snake)
{
	SNAKE *node = snake->shead->next;
	while (node)
	{
		if ((snake->shead->x == node->x) && (snake->shead->y == node->y))
			return 1;
		node = node->next;
	}
	if (map[snake->shead->x][snake->shead->y] == 10)
		return 1;
	
	return 0;
}
