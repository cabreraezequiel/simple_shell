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
		exit(2);
	}

	else
	{
		if(strstr(stat, "-"))
			status = - atoi(stat);
		else
			status = atoi(stat);

		free(s);
		exit(status);
	}
}
