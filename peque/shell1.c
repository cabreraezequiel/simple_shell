#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

extern char **environ;
void printenv(void);
void _chdir(const char *path);

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
/*	char *path[1024];
 	char *subpath = getenv("PATH");

	path[i] = strtok(subpath, ":" "\n");
	while(path[i] != NULL)
	{
		path[++i] = strtok(NULL, ":" "\n");
	}
	i = 0;

	argv = malloc(sizeof(*s));
*/
	*argv = NULL;
	argv[i] = strtok(s, " " "\n" "\t");

	while(argv[i] != NULL)
	{
		argv[++i] = strtok(NULL, " " "\n" "\t");
	}

	if(argv[0] == "env")
	{
		printenv();
		return(0);
	}

	if(argv[0] == "cd")
	{
		_chdir(argv[1]);
		return(0);
	}

/*	if (stat(argv[0], ) != -1)*/
	child_pid = fork();
	if (child_pid == 0)
	{
		if (execvp(argv[0], argv) == -1)
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

	printf("#cisfun$ ");

	while ((nread = getline(&line, &len, stdin)) != -1)
	{
		exec(line);
		printf("#cisfun$ ");
	}

	free(line);
	exit(EXIT_SUCCESS);
}

void printenv(void)
{
	int i;

	for(i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}

void _chdir(const char *path)
{
	printf("%s\n", path);
}
