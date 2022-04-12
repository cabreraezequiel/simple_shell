#include <stdio.h>
#include <stdlib.h>

/**
*
*
*
*/
int main(void)
{
	char *path = getenv("PATH");
	int i;

	for (i = 0; path[i] != '\0'; i++)
	{
		if (path[i] == ':')
			putchar('\n');
		else
			printf("%c", path[i]);
	}
	putchar('\n');

	return (0);
}
