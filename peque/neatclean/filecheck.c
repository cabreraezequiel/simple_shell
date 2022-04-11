#include "main.h"

/**
 * filecheck - checks wether file exists in path or not
 * @filename - name of the file
 * Return: 0 if it exists, 1 otherwise
 */

int filecheck(char *filename)
{
	int i = 0;
	char *s;
	char *tok;
	char str[120];
	char file[120] = "/";
	char *res;
	char **patho = path();


	printf("%s\n", patho[i]);
	s = malloc(sizeof(_getenv("PATH")));
	s =_getenv("PATH");
	printf("s: %s\n", s);

	strcat(file, filename);
	tok = strtok(s, ":\n");

	printf("filename: %s\n", filename);
	printf("entra en filecheck\n");
	printf("tok: %s\n", tok);
	printf("s: %s\n", s);

	while (tok != NULL)
	{
		_strcpy(str, tok);
		res = str_concat(str, file);
		printf("res: %s\n", res);
		printf("tok : %s\n", tok);

		if (access(res, F_OK) == 0)
		{
			free(s);
			free(res);
			free(patho);
			return (0);
		}

		tok = strtok(NULL, ":\n");
		str[0] = 0;
	}

	return (1);
}
