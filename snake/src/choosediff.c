#include "choosediff.h"

int choose_diff()
{
	printf("please choose difficulty:(1/2/3/4)\n\n");
	printf("1. semi-pro    2.professional    3.world class    4.legendary\n");
	char ch[100] = "0";
	scanf("%s", ch);
	while (0!=strcmp(ch, "1") && 0!=strcmp(ch, "2") && 0!=strcmp(ch, "3") && 0!=strcmp(ch, "4"))
	{
		printf("repick please(1/2/3/4)\n");
		scanf("%s", ch);
	}
	getchar();
	printf("move: w, a, s, d\n");
	printf("are you ready? press any key to start....\n");
	getchar();
	printf("%s","\033[1H\033[2J");
	return ch[0]-48;
}
