#include "main.h"

/**
 * _chdir - changes directory
 * @path: directory
 * Return: 0
 */

int _chdir(char **path)
{
	char s[100];

	if (path[2] != NULL)
		return (-1);

	if (path[1] == NULL || (_strcmp(path[1], "$HOME")) == 0)
	{
		chdir("/root");
		return (0);
	}

	else if ((_strcmp(path[1], "-") == 0))
	{
		chdir("..");
		printf("%s\n", getcwd(s, 100));
		return (0);
	}

	else
	{
		chdir(path[1]);
		return (0);
	}
}
