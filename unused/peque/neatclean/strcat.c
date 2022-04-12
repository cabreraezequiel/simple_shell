#include "main.h"

/**
 * _strcat - concadenates two strings
 * @dest: string dest
 * @src: string src
 *
 * Return: pointer to the resulting string dest
 */

char *_strcat(char *dest, char *src)
{
	int n = 0;
	int m = 0;

	for (n = 0; dest[n] != '\0'; n++)
	{
	}
	n--;
	for (m = 0; src[m] != '\0'; m++)
	{
		n++;
		dest[n] = src[m];
	}
	return (dest);
}
