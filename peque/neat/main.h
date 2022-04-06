#ifndef MAIN
#define MAIN

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <stddef.h>


/**
 * struct format - Struct
 *
 * @command: The command
 * @f: The function associated
 */
typedef struct format
{
	char *command;
	int (*f)(va_list);

} Tformat;


void _chdir(char *path);
void _exit_(char *stat);
int exec(char *s);

extern char **environ;

#endif /* MAIN */
