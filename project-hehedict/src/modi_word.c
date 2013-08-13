#include "modi_word.h"


int Modi_Word(TREETYPE *root, ELEMTYPE *word)
{

	if (Find_Word(root, word))
	{
		root = Dele_Tree(root, word);
		Add_Word(root, word);
		return 1;
	}
	return 0;
}
