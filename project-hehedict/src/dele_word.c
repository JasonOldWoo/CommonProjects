#include "dele_word.h"

int  Dele_Word(TREETYPE *root, ELEMTYPE *word)
{
	char ch[10];
	if(Find_Word(root,word) == NULL)
	{
		return 0;
	}
	else
	{
		printf("是否确定删除%s(y/n)\n",word);
		while(1)
		{
			scanf("%s", ch);
			if(strcmp("y",ch)==0 || strcmp("n",ch)==0)
				break;
			else
				printf("请输入y/n\n");
		}
		if(strcmp("n",ch)==0)
			return 0;
		TREETYPE *leaf = Dele_Tree(root, word);
		Tree_To_File(leaf);
		return 1;
	}
}
