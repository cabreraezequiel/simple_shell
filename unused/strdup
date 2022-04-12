#include "main.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 *          which contains a copy of the string given as a parameter
 * @str: given string
 *
 * Return: NULL or stra
 */

char *_strdup(char *str)
{
	char *stra = NULL;
	unsigned int n = 0;
	int size = 1;

	if (str == NULL)
	{
		return (NULL);
	}
	for (n = 0; str[n] != '\0'; n++)
	{
		size++;
	}
	stra = calloc(1, sizeof(char) * size);
	if (stra == NULL)
	{
		free(stra);
		return (NULL);
	}
	for (n = 0; str[n] != '\0'; n++)
	{
		stra[n] = str[n];
	}
	return (stra);
}
