#ifndef __SEARCH_TREE_H__
#define __SEARCH_TREE_H__


#include "insert_tree.h"

ELEMTYPE *Search_Tree(TREETYPE *root, ELEMTYPE *word);	//return translation
TREETYPE *Find_Word(TREETYPE *root, ELEMTYPE *word);	//return leaf which contains word, if no leaf matched, return NULL


#endif
