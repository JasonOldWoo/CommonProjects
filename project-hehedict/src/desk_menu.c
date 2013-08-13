#include "sub_menu.h"
#include "app.h"

int desk_menu()
{
	FILE *cata = fopen("data/dict_cata.hdtc", "r");
	char name[100][150] = {};
	int cnt = 1;
	int i = 0;
	printf("______________________________________________________________\n\n\n\n");
	while (1)
	{
		fgets(name[++i], 150, cata);
		if (0 == strcmp(name[i], "\n"))
			break;
		name[i][strlen(name[i])-5] = 0;
		printf("\t\t\t[%d] %s\n\n", cnt++, name[i]);
	}
	printf ("\t\t\t[%d] 退出\n\n\n\n", cnt++);
	printf("______________________________________________________________\n\n\n\n\n");
	char ch[10] = {};
	while (1)
	{
		printf("请选择功能\n");
		scanf("%s", ch);
		if (ch[0]-48<cnt && ch[1]==0)
			break;
	}
	if (ch[0]-48<cnt-1)
	{
		char newtime[100];
		FILE* pf3 = fopen("log.txt","a+");
		strcpy(newtime , timeinfo());
		fprintf(pf3,"%s",newtime);
		fprintf(pf3, "%s： ", "进入词库");
		strcpy(dictPath, "data/dict/");
		strcat(dictPath, name[ch[0]-48]);
		strcat(dictPath, ".hdt");
		fprintf(pf3, "%s\n", dictPath);
		fclose(pf3);
	}
	else
	{
		Sys_Quit();
	}
}
