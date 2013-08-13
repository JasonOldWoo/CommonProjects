#include "chartoint.h"

int chartoint(char *str)
{
	int len = strlen(str);
	int num = 0;
	int lev = 1;
	int i = 0;
	for (i=len-1; i>=0; i++)
	{
		num += (str[i]-48)*lev;
		lev *= 10;
	}
	return num;
}
