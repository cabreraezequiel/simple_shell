#include "main.h"

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread = 0;
	int f;

	f = open(".simple_shell_history", O_CREAT | O_RDWR | O_APPEND, 0600);

	printf("#cisfun$ ");

/*	line = malloc(len);*/

	while ((nread = getline(&line, &len, stdin)) != -1)
	{
/*		line = realloc(line, len);*/
		write(f, line, strlen(line));
		exec(line);
		printf("#cisfun$ ");
	}

	exit(EXIT_SUCCESS);
	close(nread);
	free(line);
	close(f);
}
