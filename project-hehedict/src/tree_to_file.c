#include "tree_to_file.h"


#define WORD root->word
#define TRAN root->tran

void Write_Tree(TREETYPE *root, FILE *pFile);
void Write_Node(TREETYPE *root, FILE *pFile);

void Tree_To_File(TREETYPE *root)
{
	FILE *pFile = fopen("data/dict_tmp.hdtt", "w+");
	if (!pFile)
	{
		printf("Tree_To_File: open failed\n");
		return ;
	}
	Write_Tree(root, pFile);
	fclose(pFile);
}

void Write_Tree(TREETYPE *root, FILE *pFile)
{
	if (!root)
		return ;
	
	Write_Tree(root->left, pFile);
	Write_Node(root, pFile);
	Write_Tree(root->right, pFile);
	
}

void Write_Node(TREETYPE *root, FILE *pFile)
{
	fputs(WORD, pFile);
	fputs("\n", pFile);
	fputs(TRAN, pFile);
	fputs("\n", pFile);
}
