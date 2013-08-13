#include "dele_tree.h"



void Delete_Tree(TREETYPE **ROOT, TREETYPE *root, ELEMTYPE *word);
TREETYPE *Dele_Tree(TREETYPE *root, ELEMTYPE *word)
{
	pre = (TREETYPE *)malloc(sizeof(TREETYPE));
	TREETYPE **leaf = (TREETYPE **)malloc(sizeof(TREETYPE));
	
	*leaf = root;

	Delete_Tree(leaf, root, word);
	return *leaf;
}


void Delete_Tree(TREETYPE **ROOT, TREETYPE *root, ELEMTYPE *word)
{
	if (0 == strcmp(word,(*ROOT)->word))
	{
		TREETYPE *tmp = *ROOT;
		if (tmp->left)
                {
			
                        TREETYPE *max = tmp->left;
			TREETYPE *RIGHT = tmp->right;
			TREETYPE *LEFT = tmp->left;
                        root = root->left;
                        while (1)
                        {
                                if (root->right)
                                {
                                        root = root->right;
                                        max = root;
                                }
                                if (!root->right && root->left)
                                        root = root->left;
                                if (!root->right && !root->left)
                                        break;
                        }
                        max->right = RIGHT;
			*ROOT = LEFT;
			free(tmp);
		}
		else
		{
			*ROOT = (*ROOT)->right;
			free(tmp);
		}
		return ;
	}
	if (0 > strcmp(word,root->word))
	{
		if (root->left)
		{
			pre = root;
			Delete_Tree(ROOT, root->left, word);
		}
		else
			return ;

	}
	if (0 < strcmp(word,root->word))
	{
		if (root->right)
		{
			pre = root;
			Delete_Tree(ROOT, root->right, word);
		}
		else
			return ;
	}
	if (0 == strcmp(word, root->word))
	{
		TREETYPE *tmp = root;
		if (tmp->left)
		{
			TREETYPE *max = tmp->left;
			root = root->left;
			while (1)
			{
				if (root->right)
				{
					root = root->right;
					max = root;
				}
				if (!root->right && root->left)
				
					root = root->left;
				if (!root->right && !root->left)
					break;
			}
			max->right = tmp->right;
			if (pre->left == tmp)
				pre->left = tmp->left;
			if (pre->right == tmp)
				pre->right = tmp->left;
			free(tmp);
		}
		else
		{
			if (pre->left == tmp)
                                pre->left = tmp->right;
                        if (pre->right == tmp)
                                pre->right = tmp->right;
                        free(tmp);
		}
		return ;
		
	}
}
