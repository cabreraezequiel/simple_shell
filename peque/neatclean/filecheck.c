#include "main.h"

/**
 * filecheck - checks wether file exists in path or not
 * @filename - name of the file
 * Return: 0 if it exists, 1 otherwise
 */

int filecheck(char *filename, const char **path)
{
	int i = 0;
	char str[120];
	char file[120] = "/";
	char *res;

	printf("file: %s\n", file);
	strcat(file, filename);
	printf("file: %s\n", file);
	printf("i: %d\n", i);
	printf("patho: %s\n", path[i]);
	while (path[i] != NULL)
	{
		printf("file: %s\n", file);
		_strcpy(str, path[i]);
		res = str_concat(str, file);

		printf("str: %s\n", str);
		if (access(res, F_OK) == 0)
		{
			file[0] = 0;
			return (0);
		}

		str[0] = 0;
		i++;
	}
	str[0] = 0;
	file[0] = 0;
	return (1);
}
