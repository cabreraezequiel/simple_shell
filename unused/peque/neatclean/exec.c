#include "main.h"

/**
 * exec - calls functions with their arguments
 * @s: user input
 * Return: 0
 */

int exec(char *s)
{
	pid_t child_pid;
	int status, i = 0;
	char *argv[1024];

	argv[i] = strtok(s, " \n\t");
	if (argv[0]  == NULL)
		return (1);

	while (argv[i] != NULL)
		argv[++i] = strtok(NULL, " \n\t");

	if ((_strcmp(argv[0], "cd") == 0))
		return (_chdir(argv));

	if ((_strcmp(argv[0], "exit") == 0))
		_exit_(argv[1], s);

	if (filecheck(argv[0]) == 0)
	{
	child_pid = fork();

	if (child_pid == 0)
	{
		if (execvp(argv[0], argv) == -1)
			perror("Error");
	}}

	else
		wait(&status);

	return (1);
}
