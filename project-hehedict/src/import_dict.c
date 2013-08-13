#include "sub_menu.h"

void Import_Dict()
{
	DIR *dir;
	struct dirent *ptr;
	FILE *cata = fopen("data/dict_cata.hdtc", "w+");
	int checkLen = 0;
	int i = 0;
	dir = opendir("data/dict");
	while((ptr = readdir(dir)) != NULL)
	{
		
		checkLen = strlen(ptr->d_name);
		if (strcmp(ptr->d_name, ".")==0 || strcmp(ptr->d_name, "..")==0)
			continue ;
		else
		{
			if (strcmp((ptr->d_name)+checkLen-3, "hdt"))
				continue ;
			fprintf(cata, "%s\n", ptr->d_name);
		}
	}
	fprintf(cata, "\n");
	closedir(dir);
	fclose(cata);
}
