#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

int main()
{
	while (1)
	{
		char command[100];
		printf("$ ");
		scanf(" %99[^\n]", command);

		if (!strcmp("exit", command))
			break;

		pid_t pid = fork();

		if (pid == -1)
		{
			perror("Error:");
			return (1);
		}

		if (!pid)
		{
			exec(command);
			break;
		}
		else
			wait(NULL);
	}
	return (0);
}
