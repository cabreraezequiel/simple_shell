#include "main.h"

int filecheck(char *filename)
{
	char *s = getenv("PATH");
	int i = 0;
	char *argv[1024];
	char *str;

	argv[i] = strtok(s, ":\n");
	  
	while (argv[i] != NULL)
	{
		str = strcat(argv[i], filename);

		if (access(str, F_OK) == 0)
			return (0);

		argv[++i] = strtok(NULL, ":\n");
	}
	printf("%s", s);

	return (1);
}

int main(void)
{
	if (filecheck("ls") == 0)
		printf("funciona\n");


	return (0);
}
