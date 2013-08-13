#include "controldirection.h"


void control_direction(char *ch)
{
	while (1)
	{
		*ch = mygetch();
		if (*ch == '\n')
			pthread_exit(0);
	}
}
