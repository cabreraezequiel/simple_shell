#include "shell.h"

/**
 * main - execve example
 *
 * Return: Always 0.
 */
int exec(char *s)
{
	pid_t child_pid;
	int status, i = 0;
	char *argv[1024];

	argv[i] = strtok(s, " " "\n");
	while(argv[i + 1] != NULL)
	{
		i++;
		argv[i] = strtok(NULL, " ");
	}

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
			perror("Error");
	}
	else
		wait(&status);

	return (0);
}
