#include "main.h"

/**
 * _exit_ - exit programm
 * @stat: stat
 * @s: s
 */

void _exit_(char *stat, char *s)
{
	int status;

	if (stat == NULL)
	{
		free(s);
		exit(EXIT_SUCCESS);
	}

	else
	{
		status = 2/*atoi(stat)*/;
		free(s);
		exit(status);
	}
}
