#include "main.h"

/**
 * filecheck - checks wether file exists in path or not
 * @filename - name of the file
 * Return: 0 if it exists, 1 otherwise
 */

char *filecheck(char *filename)
{
	int i = 0;
	char *str = NULL;
	char file[120] = "/";
	char **patho = path();
	char *res = NULL;
	struct stat buffer;

	strcat(file, filename);

	while (patho[i] != NULL)
	{
		str = _strdup(patho[i]);
		res = str_concat(str, file);

		if (stat(res, &buffer) == 0)
		{
			free(patho);
			free(str);
			file[0] = 0;
			return (res);
		}

		free(res);
		free(str);
		i++;
	}
	free(patho);
	free(str);
	file[0] = 0;
	return (NULL);
}
