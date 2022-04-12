#include "main.h"

/**
 * main - main function
 * Return: 0
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	int fg;

	if (isatty(0))
	{

		printf("$ ");
	}

	signal(SIGINT, sighand);

	while ((fg = getline(&line, &len, stdin)) != -1)
	{
		exec(line);
		if (isatty(0))
			printf("$ "); }

	free(line);
	exit(EXIT_SUCCESS);
}
