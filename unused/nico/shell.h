#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int exec(char *s);
int f_cd(char **args);
int check_for_EOF();

#endif
