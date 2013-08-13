#include "add_word.h"


#define SET setbuf(stdin, NULL)
#define GET fgets(temp, TN, stdin)


TREETYPE *Write(TREETYPE *root, char *word)
{
	int length=0;
	char tran[TN] = {};
	char temp[TN]="y\n";
	while(strcmp(temp,"y\n")==0)
	{
		printf("请输入词性和解释(例如：v.跑步)，直接键入回车可取消操作\n");
		SET;
		GET;
		length=strlen(temp);
		if (isNull(temp))
		{
			printf("已撤消词条新增操作\n");
			return NULL;
		}

		temp[length-1]='\0';
		
		strcat(tran, "@");
		strcat(tran, temp);
		strcpy(temp, "q");
		while(strcmp(temp,"y\n")!=0&&strcmp(temp,"n\n")!=0)
		{
			printf("是否继续添加释义？(y/n)\n");
			SET;
			GET;
		}//如果用户输入y/n以外的字符，提示重新输入
	}
	root = Insert_Tree(root, word, tran);
	return root;
}


int Add_Word(TREETYPE *root, ELEMTYPE *word)
{

	if (Find_Word(root, word))
		return 0;
	if (!(root = Write(root, word)))
		return -1;

	Tree_To_File(root);
	return 1;
}

int isNull(char *str)
{
	int i = 0;
	while (1)
	{
		printf("str[%d]?=space: %d, str[%d]?=tab: %d, str[%d]?=enter:%d\n", i, str[i]==' ', i, str[i]=='\t', i, str[i]=='\n');
		if (str[i]!=' ' && str[i]!='\t' && str[i]!='\n' && str[i]!=0)
			return 0;
		if (str[i] == 0)
			break ;
		i++;
	}
	return 1;
}
