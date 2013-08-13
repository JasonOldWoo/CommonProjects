#ifndef __SUB_MENU_H__
#define __SUB_MENU_H__


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include "search_word.h"
#include "dele_word.h"
#include "modi_word.h"
#include "add_word.h"
#include "timeinfo.h"
#include "create_tree.h"

#define TMPPATH "data/dict_tmp.hdtt"
#define NOTNEED 0!=strcmp(ch,"y")&&0!=strcmp(ch,"n")

int sgn_save;
char dictPath[100];
void Choose_Dict(int choice);
int desk_menu();
int dict_menu();
void Sys_Quit();
int Overwrite_Dict();
int Delete_Dict(FILE *pFile);
void dictionary();
void Import_Dict();


#endif
