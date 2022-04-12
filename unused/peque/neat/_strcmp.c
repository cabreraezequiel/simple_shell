#include "main.h"

int _strcmp(char *s1, char *s2)
{
	int i = 0, res = 0;

	while (s1[i] == s2[i] && s1[i] && s2[i])
	{
		i++;
	}
	res = (s1[i] - '0') -  (s2[i] - '0');
	return (res);
}
