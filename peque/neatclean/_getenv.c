#include "main.h"

/**
 * _getenv - return environment value
 * @s - s
 * Return: value
 */

char *_getenv(char *s)
{
	int i = 0, bol = 0, n = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		bol = 0;
		for (n = 0; environ[i][n] != '\0' && s[n] != '\0'; n++)
		{
			if (environ[i][n] != s[n])
			{
				bol = 0;
				break;
			}

			if (environ[i][n] == s[n])
				bol++;
			if (environ[i][n] == '=' && s[n] == '\0')
			{
				bol++;
				break;
			}
		}

		if (bol > 0)
		{
			if (_strcmp(strtok(environ[i], "=\n"), s) == 0)
				return (strtok(NULL, "=\n"));
		}
	}
	return (NULL);
}

const char **path(void)
{
	int i = 0;
	const char **argv;
	argv = malloc(1024);
	argv[i] = strtok(_getenv("PATH"), ":\n");
	
	while (argv[i] != NULL) {
		printf("path[%d]: %s\n", i, argv[i]);
		argv[++i] = strtok(NULL, ":\n"); }

	return(argv);
}
