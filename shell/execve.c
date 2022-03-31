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
			perror("Error:");
	}
	else
		wait(&status);

	return (0);
}

char **_strtok(char *s)
{
	int n = 0, i = 0;
	char **array;


	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ')
			n++;
	}

	array = malloc(sizeof(char *) * (n));
	if (array == NULL)
		printf("error\n");
	i = 0;
	array[i] = strtok(s, " ");
	while(array[i] != NULL)
	{
		array[++i] = strtok(NULL, " ");
	}

	return (array);
}


int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	printf("$ ");

	if ((nread = getline(&line, &len, stdin)) != -1) {
		fwrite(line, nread, 1, stdout);
		_ls(_strtok(line));
	}

	free(line);
	exit(EXIT_SUCCESS);
}
