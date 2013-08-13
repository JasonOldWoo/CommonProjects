#include "app.h"
#include <stdlib.h>  
#include <stdio.h>  
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	sgn_save = 0;
	int i = 0;
	int j;
	
	
	printf("%s","\033[1H\033[2J");
	printf("欢迎来到呵呵词典\n\n");
	for (i=0; i<=51; i++)
	{
		fflush(stdout);
		printf("\rLOADING：");
		for (j=0; j<=i; j++)
			printf("|");
		printf("%2d%%", 2*i);
		for (j=0; j<8500000; j++);
		if (i == 51)
			for (j=0; j<200000000; j++);
	}
	printf("%s","\033[1H\033[2J");
	
	main_menu();
	
	return 0;
}

