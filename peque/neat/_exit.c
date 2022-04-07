#include "main.h"

void _exit_(char *stat, char *s)
{
	int status;

	if (stat == NULL)
	{
		free(s);
		exit(0);
	}

	else
	{
		status = atoi(stat);
		free(s);
		exit(status);
	}
}
