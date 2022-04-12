#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

/**
*
*
*
*
*/
int _setenv(const char *name, const char *value, int overwrite)
{
	char *newvalue = "newvalue";

	printf("The value of name is: %s\n", value);

	if (name == NULL)
	{
		name = value;
		printf("Variable name created with the value %s\n", value);
	}

	else if (name != NULL)
	{
		if (overwrite != 0)
		{
			name = newvalue;
			printf("Value of name changed from %s to %s\n", getenv(value), getenv(newvalue));
		}
	}
	return (0);
}

void main(void)
{
	char *name = getenv(name);
	char *value = getenv(value);
	int overwrite = 2;

	_setenv(name, value, overwrite);
}
