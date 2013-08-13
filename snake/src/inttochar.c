#include "inttochar.h"

void mystrrev(char *str)
{
	int len = strlen(str);
	int mid = len/2;
	int cnt = 0;
	char tmp;
	while ((len--)>mid)
	{
		tmp = str[len];
		str[len] = str[cnt];
		str[cnt++] = tmp;
	}
}

void inttochar(char *cnum, int num)
{
	int cnt = 0;
	num*=10;
	while (num = num/10)
	{
		cnum[cnt++] = num - num/10*10 + 48;
	}
	cnum[cnt] = 0;
	mystrrev(cnum);
}
