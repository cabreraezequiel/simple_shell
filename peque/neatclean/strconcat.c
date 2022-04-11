#include "main.h"

/**
 * str_concat - concatenates two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: NULL or stra
 */

char *str_concat(char *s1, char *s2)
{
	char *strcnct;
	int n = 0;
	int m = 0;
	int size = 1;

	if (s1 != NULL)
	{
	for (n = 0; s1[n] != '\0'; n++)
	{
		size++;
	}
	}
	if (s2!= NULL)
	{
	for (n = 0; s2[n] != '\0'; n++)
	{
		size++;
	}
	}

	strcnct = malloc(sizeof(char) * size);
	if (strcnct == NULL)
	{
		return (NULL);
	}
	if (s1 != NULL)
	{
		for (n = 0; s1[n] != '\0'; n++, m++)
		{
			strcnct[m] = s1[n];
		}
	}

	if (s2 != NULL)
	{
		for (n = 0; s2[n] != '\0'; n++, m++)
		{
			strcnct[m] = s2[n];
		}
	}
	return (strcnct);
}
