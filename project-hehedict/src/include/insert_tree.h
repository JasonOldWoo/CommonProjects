#ifndef __INSERT_TREE_H__
#define __INSERT_TREE_H__


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 10000
#define WN 100
#define TN 100
#define TREETYPE struct AVLTree
#define ELEMTYPE char

TREETYPE
{
	ELEMTYPE word[WN];	//word to be translated
	ELEMTYPE tran[TN];	//translation
	TREETYPE *left;		//left child of leaf
	TREETYPE *right;	//right child of leaf
	int height;		//tree's height
};

TREETYPE *Insert_Tree(TREETYPE *root, ELEMTYPE *word, ELEMTYPE *tran);	//insert without losing balance
void Print_Tree(TREETYPE *root);	//inorder print for convenient test of Insert_Tree(....)


#endif
