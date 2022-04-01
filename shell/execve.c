#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

char **_strtok(char *s);
int _ls(char **argv);

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

	argv[i] = strtok(s, " ");
	while(argv[i])
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

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	printf("$ ");

	while ((nread = getline(&line, &len, stdin)) != -1) {
		exec(line);
		printf("$ ");
	}

	free(line);
	exit(EXIT_SUCCESS);
}
