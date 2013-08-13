#include "sub_menu.h"


int dict_memu()
{
	char ch[10] = "q";
	char tmpPath[150];
	strncpy(tmpPath, dictPath+10, strlen(dictPath+10)-4);
	printf("______________________________________________________________\n\n");
	printf("  《%s》\n\n\n", tmpPath);
	printf("\t\t[1] 查询词条    |    [4] 修改词条\n");
	printf("\t\t                |\n");
	printf("\t\t[2] 新增词条    |    [5] 保存字典\n");
	printf("\t\t                |\n");
	printf("\t\t[3] 删除词条    |    [6] 返回主选单\n\n\n\n");
	printf("______________________________________________________________\n\n\n\n\n");
	
	while (0!=strcmp(ch,"1") && 0!=strcmp(ch,"2") && 0!=strcmp(ch,"3") && 0!=strcmp(ch, "4") && 0!=strcmp(ch, "5") && 0!=strcmp(ch, "6"))
	{
		printf("请选择功能\n");
		scanf("%s", ch);
	}
	return ch[0] - 48;
}

