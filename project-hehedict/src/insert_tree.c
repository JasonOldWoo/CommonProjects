#include "insert_tree.h"


TREETYPE *LL_Rot(TREETYPE *root);
TREETYPE *RR_Rot(TREETYPE *root);
TREETYPE *LR_Rot(TREETYPE *root);
TREETYPE *RL_Rot(TREETYPE *root);

int Height(TREETYPE *root);
int Max(int a, int b);


TREETYPE *Insert_Tree(TREETYPE *root, ELEMTYPE *word, ELEMTYPE *tran)
{
	if (NULL == root)
	{
		root = (TREETYPE *)malloc(sizeof(TREETYPE));
		strcpy(root->word, word);
		strcpy(root->tran, tran);
		root->height = 0;
		root->left = NULL;
		root->right = NULL;
	}
	else if (-1 == strcmp(word, root->word))
	{
		root->left = Insert_Tree(root->left, word, tran);
		/*
			ensure that A point is nearest to new node,
			'Cause after A point do rotating, its parent's bf(balance factor) must be less than 2
		*/
		if (2 == (Height(root->left)-Height(root->right)))
		{
			if (-1 == strcmp(word, root->left->word))
			{
				root = LL_Rot(root);
			}
			else
			{
				root = LR_Rot(root);
			}
		}
	}
	else if (1 == strcmp(word, root->word))
	{
		root->right = Insert_Tree(root->right, word, tran);
		if (2 == (Height(root->right)-Height(root->left)))
		{
			if (1 == strcmp(word, root->right->word))
			{
				root = RR_Rot(root);
			}
			else
			{
				root = RL_Rot(root);
			}
		}
	}
	root->height = Max(Height(root->left), Height(root->right)) + 1;	//notice that height of bottom of tree is zero
	return root;	//return main root, 'Cause it is the first elem which pushed into stack
}


TREETYPE *LL_Rot(TREETYPE *root)
{
	TREETYPE *leaf;
	leaf = root->left;
	root->left = leaf->right;
	leaf->right = root;
	/*
		rotate around shaft B Clockwisely
	*/

	//update height because of the change of position of node
	root->height = Max(Height(root->left), Height(root->right)) + 1;
	leaf->height = Max(Height(leaf->left), root->height) + 1;
	return leaf;
}


TREETYPE *RR_Rot(TREETYPE *root)
{
	TREETYPE *leaf;
	leaf = root->right;
	root->right = leaf->left;
	leaf->left = root;
	/*
		rotate around shaft B Anti-Clockwisely
	*/

	//update height
	root->height = Max(Height(root->left), Height(root->right)) + 1;
	leaf->height = Max(Height(leaf->right), root->height) + 1;
	return leaf;
}


TREETYPE *LR_Rot(TREETYPE *root)
{
	root->left = RR_Rot(root->left);	//rotate around shaft C Anti-Clockwisely
	return LL_Rot(root);	//rotate around shatf C Clockwisely
}


TREETYPE *RL_Rot(TREETYPE *root)
{
	root->right = LL_Rot(root->right);	//rotate around shaft C Clockwisely
	return RR_Rot(root);	//rotate around shaft C Anti-Clockwisely
}


int Height(TREETYPE *root)
{
	if (!root)
		return -1;
	return root->height;
	/*
		cases:
			tree:
				1
			height if root:
				0
			tree
				1
			       / \
			      2   3
			height of root:
				1
	*/
}


int Max(int a, int b)
{
	return (a > b ? a : b);
}


void Print_Tree(TREETYPE *root)
{//inorder print
	if (!root)
	{
		return ;
	}
	Print_Tree(root->left);
	printf("word: %s\ntran: %s\n", root->word, root->tran);
	Print_Tree(root->right);
}

