#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char **_strtok(char *s)
{
	int n = 0, i = 0;
	char **array;


	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ')
			n++;
	}

	array = malloc(sizeof(char *) * (n));
	if (array == NULL)
		printf("error\n");
	i = 0;
	array[i] = strtok(s, " ");
	while(array[i] != NULL)
	{
		printf("%s\n", array[i]);
		array[++i] = strtok(NULL , " ");
		if (array[i] == NULL)
			printf("error\n");
	}
	free(array);

	return (array);
}


int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	printf("$ ");

	if ((nread = getline(&line, &len, stdin)) != -1) {
		fwrite(line, nread, 1, stdout);
		_strtok(line);
	}

	free(line);
	       exit(EXIT_SUCCESS);
}
