#include "app.h"

/************************
Author: Jason Wood
Version: 1.0 Beta
Date: 17/07/2013
************************/



int main()
{
	printf("%s","\033[1H\033[2J");
	SHEAD *snake = (SHEAD *)malloc(sizeof(SHEAD));
	snake = init_snake();
	create_snake(snake);
	welcome();
	game(snake);
	
	return 0;
}
