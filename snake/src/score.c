#include "score.h"


int score(SHEAD *snake)
{
	int score = 0;
	SNAKE *node = snake->shead;
	while (node)
	{
		score++;
		node=node->next;
	}
	score-=5;
	return score*137;
}

