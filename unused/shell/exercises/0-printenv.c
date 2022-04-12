#include <stdio.h>
#include <string.h>

extern char **environ;

int main (int ac, char **av, char **env)
{
	int i, n, bol = 0;
	char *s;


	s = av[1];
	printf("Adress of environ: %p\n", environ);
	printf("Adress of env: %p\n", env);


	for (i = 0; environ[i] != NULL; i++)
	{
		bol = 0;
		for (n = 0; environ[i][n] != '=' || s[n] != '\0'; n++)
		{
			if (s[n] == environ[i][n])
			{
				bol++;
			}
			else
			{
				bol = 0;
				break;
			}
		}
		if (bol > 0)
			printf("%s\n", environ[i]);
	}
}
