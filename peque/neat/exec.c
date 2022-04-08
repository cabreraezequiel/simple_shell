#include "main.h"


int exec(char *s)
{
	pid_t child_pid;
	int status, i = 0, rv = 0;
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
		argv[++i] = strtok(NULL, " " "\n" "\t");

	if((_strcmp(argv[0], "cd") == 0))
		return(_chdir(argv));

/*	if((strcmp(argv[0], "$?") == 0))
	{
		printf("%d\n", rv);
		return(0);
	}
*/
	if((_strcmp(argv[0], "exit") == 0))
		_exit_(argv[1], s);

/*	if ((strcmp(argv[0], "history") == 0))
	{
		print_history(".simple_shell_history");
		return (0);
	}
*/
/*	if (stat(argv[0], ) != -1)*/
	child_pid = fork();
	if (child_pid == 0) {
		if ((rv = execvp(argv[0], argv)) == -1)
			perror("Error"); }

	else
		wait(&status);

	return (0);
}
