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
int _ls(char **argv)
{
	pid_t child_pid;
	int status;

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

char **_strtok(char *s)
{
	int i = 0;
	char **array;

	array = malloc(1024);
	if (array == NULL)
		printf("error\n");

	array[i] = strtok(s, " ");
	while(array[i])
	{
		i++;
		array[i] = strtok(NULL, " ");
	}

	return (array);
}

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	printf("$ ");

	while ((nread = getline(&line, &len, stdin)) != -1) {
		_ls(_strtok(line));
		printf("$ ");
	}

	free(line);
	exit(EXIT_SUCCESS);
}
