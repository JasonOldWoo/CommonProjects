#ifndef __SNAKE_H__
#define __SNAKE_H__


#define SNAKE struct snake
#define SHEAD struct shead

#define N 25

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <pthread.h>

SNAKE
{
	int x;
	int y;
	SNAKE *next;
	SNAKE *pre;
};

SHEAD
{
	SNAKE *shead;
};






#endif
