#include "main.h"

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	int f;

	f = open(".simple_shell_history", O_CREAT | O_RDWR | O_APPEND, 0600);

	printf("#cisfun$ ");

	while ((nread = getline(&line, &len, stdin)) != -1)
	{
		write(f, line, strlen(line));
		exec(line);
		printf("#cisfun$ ");
	}

	close(f);
	free(line);
	exit(EXIT_SUCCESS);
}
