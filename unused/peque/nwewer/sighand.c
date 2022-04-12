#include "main.h"

void sighand(__attribute__((unused)) int sighandv)
{
	write(STDIN_FILENO, "\n$ ", 4);
}
