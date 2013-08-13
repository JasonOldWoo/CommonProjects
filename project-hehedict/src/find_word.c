#include "search_tree.h"

TREETYPE *Find_Word(TREETYPE *root, ELEMTYPE *word)
{
	while (root)
	{
		if (0 == strcmp(root->word, word))
		{
			return root;
		}
		else if (-1 == strcmp(root->word, word))
		{
			root = root->right;
		}
		else if (1 == strcmp(root->word, word))
		{
			root = root->left;
		}
	}
	if (!root)
	{
		return NULL;
	}
}
