#include "shell.h"

/**
*
*
*
*
*/
int f_cd(char **args)
{
	if (args[1] != NULL && args[1] != "")
	{
		if (chdir(args[1]) != 0)
		{
			printf("error: no such directory\n");
		}
	}
	else
	{
		printf("specify an argument\"cd\"\n");
	}
	system("pwd");
	return (1);
}
