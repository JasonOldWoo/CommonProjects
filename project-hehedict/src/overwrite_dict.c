#include "sub_menu.h"



int Overwrite_Dict(char * src ,char * dest )
{
	FILE *psrc = fopen(src ,"r" );
	if(psrc == NULL)
	{
		printf("%s 打开失败！\n",src);
		return 0;
	}
	FILE *pdest = fopen(dest , "w");
	if(pdest == NULL)
	{
		printf("%s 打开失败！\n",dest);
		return -1;
	}
	int ch;
	while((ch=getc(psrc))!=EOF)
	{
		fputc(ch , pdest);
	}
	fclose(psrc);
	fclose(pdest);

	return 1;
}
