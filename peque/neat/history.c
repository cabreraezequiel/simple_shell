#include "main.h"

void print_history(char *filename)
{
	char *buf;
	size_t size;
	int f, i = 0, n;
	char **tok;
	struct stat st;
	
	f = open(filename, O_RDONLY, 0400);

	stat(filename, &st);
	size = st.st_size;

	buf = malloc(sizeof(char) * size);
	read(f, buf, size);

	tok = malloc(1);

	for (n = 0; n != EOF; n++)
	{
		for (i = 0; buf[i] != '\n'; i++)
		{
		}
		tok = realloc(tok, (n) * sizeof(char *));
		tok[n] = malloc(sizeof(char) * i);
	}
	i = 0;
	printf("n: %u\n", n);

	tok[i] = strtok(buf, "\n");

	while (tok[i] != NULL)
	{
		printf("%d %s\n", i, tok[i]);
		tok[++i] = strtok(NULL, "\n");
	}

/*	free(tok);
 */
	free(buf);
	close(f);
}
