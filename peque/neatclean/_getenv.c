#include "main.h"

/**
 * _getenv - return environment value
 * @s - s
 * Return: value
 */

char *_getenv(char *s)
{
	int i = 0, bol = 0, n = 0;
	char *str;

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
			str = _strdup(environ[i]);
			if (_strcmp(strtok(str, "=\n"), s) == 0)
				return (strtok(NULL, "=\n"));
		}
	}
	return (NULL);
}

char **path(void)
{
	int i = 0;
	char **argv;
	char *s;

	printf("hola\n");
	argv = malloc(1024);

	s = _strdup(_getenv("PATH"));
	printf("s: %s\n", s);
	argv[i] = strtok(s, ":\n");

	while (argv[i] != NULL) {
		printf("path[%d]: %s\n", i, argv[i]);
		argv[++i] = strtok(NULL, ":\n");
	}
	free(s);

	return(argv);
}
