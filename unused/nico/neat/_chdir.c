#include "main.h"

void _chdir(char *path)
{
	char s[100];

	if (path == NULL)
		chdir("/root");

	else if ((strcmp(path, "-") == 0))
	{
	    	chdir("..");
	    	printf("%s\n", getcwd(s, 100));
	}

	else
		chdir(path);
}
