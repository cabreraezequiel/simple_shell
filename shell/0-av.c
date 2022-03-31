#include <stdio.h>

int main(int ac, char **av)
{
	int i = 0;

	for (i = 0; av[i] != NULL; i++)
	{
		printf("%s\n", av[i]);
	}
	return (0);
}
