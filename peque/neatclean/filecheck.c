#include "main.h"

/**
 * filecheck - checks wether file exists in path or not
 * @filename - name of the file
 * Return: 0 if it exists, 1 otherwise
 */

int filecheck(char *filename)
{
	int i = 0;
	char *str;
	char file[120] = "/";
	char *res;
	char **patho = path();

/*	printf("file: %s\n", file);*/
	strcat(file, filename);
/*	printf("file: %s\n", file);
	printf("i: %d\n", i);*/
	printf("patho: %s\n", patho[i]);
	while (patho[i] != NULL)
	{
		printf("file: %s\n", file);
		str = _strdup(patho[i]);
		res = str_concat(str, file);

		printf("str: %s\n", str);
		if (access(res, F_OK) == 0)
		{
			/*free(patho);*/
			free(str);
			file[0] = 0;
			return (0);
		}

		free(str);
		i++;
/*		patho = path();*/
	}
/*	free(patho);*/
	str[0] = 0;
	file[0] = 0;
	return (1);
}
