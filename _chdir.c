#include "main.h"

/**
 * _chdir - changes directory
 * @path: directory
 * Return: 0
 */

int _chdir(char **path)
{
	char s[100];

	s[0] = 0;

/*	if (!path[2])
		return (1);
*/
	setenv("OLDPWD", getcwd(s, 100), 1);

	if (path[1] == NULL || (_strcmp(path[1], "$HOME")) == 0)
	{
		chdir(getenv("HOME"));
		setenv("PWD", getcwd(s, 100), 1);
		return (0);
	}

	else if ((_strcmp(path[1], "-") == 0))
	{
		chdir(getenv("OLDPWD"));
		setenv("PWD", getcwd(s, 100), 1);
		printf("%s\n", getcwd(s, 100));
		return (0);
	}

	else
	{
		chdir(path[1]);
		setenv("PWD", getcwd(s, 100), 1);
		return (0);
	}
}
