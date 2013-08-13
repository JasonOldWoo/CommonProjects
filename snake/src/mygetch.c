#include "mygetch.h"

/*********************************************************
Repost:
http://hi.baidu.com/wjq_qust/item/a076dab03a193297194697b2
**********************************************************/


int mygetch(void)
{
	struct termios oldt, newt;
	int ch;
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	return ch;
}
