#ifndef __APP_H__
#define __APP_H__


#include "mygetch.h"
#include "insertnode.h"
#include "printsnake.h"
#include "eat.h"
#include "movesnake.h"
#include "controldirection.h"
#include "clearmap.h"
#include "judgelose.h"
#include "createfood.h"
#include "choosediff.h"

#define LEVEL 1

SHEAD *init_snake();
void create_snake(SHEAD *snake);
void game(SHEAD *snake);
void welcome();

#endif
