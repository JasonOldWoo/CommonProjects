#include "search_word.h"

void myStrcpy(char *dest, char *src);

int Search_Word(TREETYPE *root, ELEMTYPE *word)
{
	char tran[TN];
	myStrcpy(tran, Search_Tree(root, word));
	if (tran[0])
	{
		printf("%s\n", tran);
		return 1;
	}
	else
	{
		printf("对不起，您输入的单词不存在\n");
		return 0;
	}
}

 void myStrcpy(char *dest, char *src)
{
	int len = 0;
	if (src)
		len = strlen(src);
	else
	{
		dest[0] = 0;
		return ;
	}
	int i = 0;
	int j = 0;
	int cnt = 1;
	for (i=0, j=0; i<len; i++)
	{
		if (src[i] == '@')
		{
			dest[j++] = '(';
			dest[j++] = (cnt++)+48;
			dest[j++] = ')';
			continue;
		}
		else
			dest[j++] = src[i];
	}
	dest[j] = '\0';
	return ;
}


