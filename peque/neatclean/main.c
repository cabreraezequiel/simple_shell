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

/*		while(EOF)
	{
*/
		
		exec(line);

/*		exit(0);
		}*/
/*	else*/	if (isatty(0))
	{

		printf("$ ");
/*	sleep(3);*/
	}}

	free(line);
	exit(EXIT_SUCCESS);
}
