#include "app.h"

/***********************
this is main code
************************/

void game_wait(int level)
{
    struct timeval tmv;
    tmv.tv_sec = 0;
    tmv.tv_usec = 200000;
    if (level >= 2) tmv.tv_usec -= 50000;
    if (level >= 3) tmv.tv_usec -= 45000;
    if (level >= 4) tmv.tv_usec -= 40000;
    select(0, NULL, NULL, NULL, &tmv);
}

SHEAD *init_snake()
{
	SHEAD *snake = (SHEAD *)malloc(sizeof(SHEAD));
	SNAKE *head = (SNAKE *)malloc(sizeof(SNAKE));
	head->x = N/2;
	head->y = N/2;
	head->next = NULL;
	head->pre = NULL;
	snake->shead = head;

	return snake;
}

void create_snake(SHEAD *snake)
{
	int snakeLen = 5;
	int count = 0;
	for (count=1; count<snakeLen; count++)
		insert_node(snake, N/2, N/2+count);
}

void game(SHEAD *snake)
{
	int level = choose_diff();
	int map[N][N] = {};
	int *fx = (int *)malloc(sizeof(int));
	int *fy = (int *)malloc(sizeof(int));
	int haseat = 1;
	create_food(fx, fy, snake, haseat);
	clear_map(map, *fx, *fy);
	
	


	
	print_snake(map, snake, *fx, *fy);
	char s = 'k';
	char *ch = &s;
	int count = 0;
	int i;
	
	pthread_t id;
	int ret;
	int judge = 0;
	ret = pthread_create(&id, NULL, (void *)control_direction, ch);
	
	while (1)
	{
		
		//for (i=0; i<60000000-12000000*level; i++);
                game_wait(level);
		printf("%s","\033[1H\033[2J");
		if (judge_lose(map, snake))
			break;
		haseat = eat(snake, map);
		
		create_food(fx, fy, snake, haseat);
		//haseat = eat(snake, map);
		//for (i=0; i<100000000/LEVEL; i++);
		//printf("%s","\033[1H\033[2J");
		move_snake(snake, ch);
		*ch = 'k';
		clear_map(map, *fx, *fy);
		print_snake(map, snake, *fx, *fy);
	}
	int sco = score(snake);
	printf("game over, your score is %d, press enter to quit..\n", sco);
	pthread_join(id, NULL);
	/*
	char sc[100] = {};
	inttochar(sc, sco);
	*/
        //highscore(sco);
	//pthread_exit(0);
	return ;
	
}



void welcome()
{
	printf("%s","\033[1H\033[2J");
	printf("________________________________________\n\n\n\n");
	printf("              welcome!\n\n\n\n");
	printf("________________________________________\n\n");
	int i;
	for (i=0; i<900000000; i++);
	printf("%s","\033[1H\033[2J");
}
