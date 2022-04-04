#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

typedef struct list_s
{
	char *s;
	struct list_s *next;
} list_t;


/**
 * main - execve example
 *
 * Return: Always 0.
 */
int exec(char *s)
{
	pid_t child_pid;
	int status, i = 0;
	list_t *av;

	av = malloc(sizeof(list_t));

	(av)->s[i] = strtok(s, " " "\n");
	while(av->s[i + 1] != '\0')
	{
		i++;
		(av)->s[i] = strtok(NULL, " ");
		free(av->s);
	}

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(av[0], av, NULL) == -1)
			perror("Error");
	}
	else
		wait(&status);

	free(av);

	return (0);
}

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	printf("#cisfun$ ");

	while ((nread = getline(&line, &len, stdin)) != -1) {
		if (!strcmp("exit", line) == -1)
			break;
		exec(line);
		printf("#cisfun$ ");
	}

	free(line);
	exit(EXIT_SUCCESS);
}
