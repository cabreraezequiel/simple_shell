#include "main.h"

void print_history()
{
	size_t len = 0;
	ssize_t nread;
/*	char *filename = ".simple_shell_history";*/
	char buf[1024];
	int f, i = 0;

	printf("estoy dentro de history");

	f = open(".simple_shell_history", O_RDONLY, 0400);

	read(f, buf, strlen(filename));

	strtok(buf, "\n");

	while (i != '\0')
	{
		printf("%d %s", ++i, strtok(NULL, "\n"));
	}




}
