#include "create_tree.h"

TREETYPE *Create_Tree(TREETYPE *root)
{
	FILE *pFile = fopen("data/dict_tmp.hdtt", "r");
	if (!pFile)
		printf("Create_Tree: open failed\n");
	char word[M][WN] = {};
	char tran[M][TN] = {};
	int i = 0;
	while (1)
	{
		fgets(word[i], WN, pFile);
		
		if (!word[i][0])
			break;
		word[i][strlen(word[i])-1] = '\0';
		fgets(tran[i], TN, pFile);
		tran[i][strlen(tran[i])-1] = '\0';
		root = Insert_Tree(root, word[i], tran[i]);
		i++;
	}
	fclose(pFile);
	return root;
}
