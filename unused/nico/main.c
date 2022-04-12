#include "main.h"

/**
 * main - main function
 * Return: 0
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;


	signal(SIGINT, sighand);

	if (isatty(0))
	{
		while ((getline(&line, &len, stdin)) != -1)
		{
			exec(line);
		}
	}
	else
	{
		write(1, "$ ", 2);
		while ((getline(&line, &len, stdin)) != -1)
			{
				exec(line);
				write(1, "$ ", 2);
			}
	}

	free(line);
	exit(EXIT_SUCCESS);
}
