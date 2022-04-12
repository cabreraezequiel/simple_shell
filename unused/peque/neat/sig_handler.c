#include "main.h"

void sig_handler(int signum)
{
	printf("%d\n", signum);
}
