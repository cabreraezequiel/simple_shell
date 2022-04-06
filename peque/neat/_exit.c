#include "main.h"

void _exit_(char *stat)
{
	int status;

	if (stat == NULL)
		exit(0);
	else
	{
		status = atoi(stat);
		exit(status);
	}
}
