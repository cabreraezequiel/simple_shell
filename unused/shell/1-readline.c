#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	printf("$ ");

        while ((nread = getline(&line, &len, stdin)) != -1) {
		fwrite(line, nread, 1, stdout);

		printf("$ ");

	}

	free(line);
	       exit(EXIT_SUCCESS);
}
