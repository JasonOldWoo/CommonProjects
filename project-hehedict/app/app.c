#include "app.h"

void main_menu()
{
	Import_Dict();
	desk_menu();
	printf("%s","\033[1H\033[2J");
	if (!Overwrite_Dict(dictPath, TMPPATH))
	{
		FILE *fp = fopen(TMPPATH, "w");
		if (!fp)
		{
			printf("抱歉，由于无法打开词库，系统退出\n");
			exit(1);
		}
		fclose(fp);
	}
	dictionary();
}


void Sys_Quit()
{
	char newtime[100];
	FILE* pf3 = fopen("log.txt","a+");
	char ch[10] = "q";
	while (NOTNEED)
	{
		printf("确定退出呵呵词典？(y/n)\n");
		scanf("%s", ch);
	}
	if (0 == strcmp(ch, "y"))
	{
		int i;
		strcpy(newtime , timeinfo());
		fprintf(pf3,"%s",newtime);
		fprintf(pf3, "%s\n", "退出系统");
		fclose(pf3);
		printf("%s","\033[1H\033[2J");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n\n");
		printf("\t\t谢谢使用！\n\n\n\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		for (i=0; i<100000000; i++);
		printf("%s","\033[1H\033[2J");
		printf("\n     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n");
		printf("\t\t谢谢使用！\n\n\n");
		printf("     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		for (i=0; i<4000000; i++);
		printf("%s","\033[1H\033[2J");
		printf("\n\n          ~~~~~~~~~~~~~~~~~~~~~\n\n");
		printf("\t\t谢谢使用！\n\n");
		printf("\n\n\n          ~~~~~~~~~~~~~~~~~~~~~~\n");
		for (i=0; i<4000000; i++);
		printf("%s","\033[1H\033[2J");
		printf("\n\n\n\n               ~~~~~~~~~\n");
		printf("\t\t谢谢使用！\n");
		printf("               ~~~~~~~~~\n");
		for (i=0; i<4000000; i++);
		printf("%s","\033[1H\033[2J");
		printf("\n\n\n\n                 ~~~~~\n");
		printf("\n                 ~~~~~\n");
		for (i=0; i<13000000; i++);
		printf("%s","\033[1H\033[2J");
		printf("\n\n\n\n     _____________________________\n");
		for (i=0; i<2500000; i++);
		printf("%s","\033[1H\033[2J");
		printf("\n\n\n\n          ___________________\n");
		for (i=0; i<2000000; i++);
		printf("%s","\033[1H\033[2J");
		printf("\n\n\n\n               _________\n");
		for (i=0; i<2000000; i++);
		printf("%s","\033[1H\033[2J");
		printf("\n\n\n\n                    *\n");
		for (i=0; i<4000000; i++);
		printf("%s","\033[1H\033[2J");
		exit(0);
	}
	else
		main_menu();
		
}


void dictionary()
{
	char newtime[100];
	FILE* pf3 = fopen("log.txt","a+");
	int func_choice;
	TREETYPE *root = NULL;
	root = Create_Tree(root);
	ELEMTYPE word[WN];
	func_choice=dict_memu();//功能选择
	int skip;
	char ch[10] = "q";
	switch(func_choice)
	{
		case 1:
		{
			printf("请输入要查找的内容\n");
			scanf("%s", word);
			skip=Search_Word(root,word);
			strcpy(newtime , timeinfo());
			fprintf(pf3,"%s",newtime);
			fprintf(pf3,"%s","搜索词条: ");
			fprintf(pf3,"%s, ",word);
			if(skip==0)
			{
				fprintf(pf3, "%s\n", "不存在");
				fseek(pf3,0,SEEK_END);
				strcpy(ch, "q");
				while(NOTNEED)
				{
					printf("是否添加到字典？(y/n)\n");
					scanf("%s", ch);
				}
				if(0 == strcmp(ch, "y"))
					goto ADDWORD;
				else
				{
					printf("%s","\033[1H\033[2J");
					dictionary();
				}
			}
			if(skip==1)
			{
				fprintf(pf3,"%s\n","成功");
				fseek(pf3,0,SEEK_END);
				printf("查找结束，按任意键继续....\n");
				setbuf(stdin, NULL);
				getchar();
				printf("%s","\033[1H\033[2J");
				dictionary();
			}
			break;
		}
		case 2: 
		{
			printf("请输入要增加的词条\n");
			
			scanf("%s", word); 
ADDWORD:
			strcpy(newtime , timeinfo());
			fprintf(pf3,"%s",newtime);
			fprintf(pf3,"%s","增加词条: ");
			fprintf(pf3,"%s, ",word);
			skip=Add_Word(root,word);
			if (-1==skip)
			{
				fprintf(pf3, "撤销操作\n");
				fseek(pf3, 0, SEEK_END);
				printf("按任意键继续....\n");
				getchar();
			}
			if(skip==0)
			{
				fprintf(pf3, "%s\n", "已存在");
				fseek(pf3,0,SEEK_END);
				strcpy(ch, "q");
				while(NOTNEED)
				{
					printf("此单词已存在，是否进行修改？(y/n)\n");
					printf("%s\n", word);
					Search_Word(root, word);
					scanf("%s", ch);
				}
				if (0 == strcmp(ch, "y"))
					goto MODIWORD;
				
			}
			if(skip==1)
			{
				fprintf(pf3,"%s\n","成功");
				fseek(pf3,0,SEEK_END);
				sgn_save = 1;
				printf("添加成功，按任意键继续....\n");
				setbuf(stdin, NULL);
				getchar();
			}
			printf("%s","\033[1H\033[2J");
			dictionary();
			break;
		}
		case 3:
		{
			printf("请输入要删除的词条\n");
			scanf("%s", word);
			strcpy(newtime , timeinfo());
			fprintf(pf3,"%s",newtime);
			fprintf(pf3,"%s","删除词条: ");
			fprintf(pf3,"%s, ",word);
			skip = Dele_Word(root, word);
			if (skip == 1)
			{
				fprintf(pf3,"%s\n","成功");
				fseek(pf3,0,SEEK_END);
				sgn_save = 1;
				printf("删除成功，按任意键继续...\n");
			}
			else
			{
				fprintf(pf3,"%s\n","不存在");
				fseek(pf3,0,SEEK_END);
				printf("词条不存在，按任意键继续...\n");
			}
			setbuf(stdin, NULL);
			getchar();
			printf("%s","\033[1H\033[2J");
			dictionary();
			break;
		}
		case 4:
		{
			printf("请输入要修改的词条\n");
			scanf("%s", word);
			Search_Word(root, word);
MODIWORD:
			strcpy(newtime , timeinfo());
			fprintf(pf3,"%s",newtime);
			fprintf(pf3,"%s","修改词条: ");
			fprintf(pf3,"%s, ",word);
			skip = Modi_Word(root, word);
			if (skip == 1)
			{
				fprintf(pf3,"%s\n","成功");
				fseek(pf3,0,SEEK_END);
				sgn_save = 1;
				printf("修改成功，按任意键继续....\n");
			}
			else
			{
				fprintf(pf3,"%s\n","不存在");
				fseek(pf3,0,SEEK_END);
				strcpy(ch, "q");
				while(NOTNEED)
				{
					printf("是否添加？(y/n)\n");
					scanf("%s", ch);
				}
				if (0 == strcmp(ch, "y"))
					goto ADDWORD;
				else
				{
					printf("%s","\033[1H\033[2J");
					dictionary();
				}
			}
			setbuf(stdin, NULL);
			getchar();
			printf("%s","\033[1H\033[2J");
			dictionary();
			break;
		}
		case 5:
		{
			strcpy(ch, "q");
			while (NOTNEED)
			{
				printf("是否覆盖已有词库？(y/n)\n");
				scanf("%s", ch);
			}
			if (strcmp(ch, "y") == 0)
			{
				strcpy(newtime , timeinfo());
				fprintf(pf3,"%s",newtime);
				fprintf(pf3,"%s","保存词库: ");
				fprintf(pf3,"%s, ",dictPath);
				if(Overwrite_Dict(TMPPATH, dictPath)==1)
				{
					fprintf(pf3,"%s\n","成功");
					fseek(pf3,0,SEEK_END);
					printf("保存成功，按任意键继续....\n");
					sgn_save = 0;
				}
				else
				{
					fprintf(pf3,"%s\n","失败");
					fseek(pf3,0,SEEK_END);
					printf("抱歉，保存失败，按任意键继续....\n");
				}
			}
			else
			{
				fprintf(pf3, "%s\n", "撤销操作");
				fseek(pf3, 0 , SEEK_END);
				printf("已取消操作，按任意键继续....\n");
			}
			setbuf(stdin, NULL);
			getchar();
			printf("%s","\033[1H\033[2J");
			dictionary();
			break;
		}
		case 6:
		{
			char ch[10] = "q";
			if (sgn_save)
			{
				while (NOTNEED)
				{
					printf("文件已修改，是否保存？(y/n)\n");
					scanf("%s", ch);
				}
				if (0 == strcmp(ch, "y"))
				{
					strcpy(newtime , timeinfo());
					fprintf(pf3,"%s",newtime);
					fprintf(pf3,"%s","保存词库: ");
					fprintf(pf3,"%s, ",dictPath);
					if(Overwrite_Dict(TMPPATH, dictPath)==1)
					{
						fprintf(pf3,"%s\n","成功");
						fseek(pf3,0,SEEK_END);
						printf("保存成功，按任意键继续....\n");
					}
					else
					{
						fprintf(pf3,"%s\n","失败");
						fseek(pf3,0,SEEK_END);
						printf("抱歉，保存失败，按任意键继续....\n");
					}
					setbuf(stdin, NULL);
					getchar();
				}
				sgn_save = 0;
			}
			printf("%s","\033[1H\033[2J");
			main_menu();
		}
		default: break;
	}
}

