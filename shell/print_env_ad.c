#include <stdio.h>

/**
*
*
*
*
*
*/
extern char **environ;

int main(int ac, char **av, char **env)
{
	printf("Adress of environ: %p\n", environ);
	printf("Adress of env: %p\n", env);

	return (0);
}
