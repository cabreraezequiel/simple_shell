#include "main.h"
char *builtin_str[] = {
	"chdir",
	"help",
	"exit",
	"history"
};

int (*builtin_func[]) (char **) = {
	&_chdir,
	&_help,
	&_exit,
	&print_history
};

int num_builtins() {
  return sizeof(builtin_str) / sizeof(char *);
}

int _help(char **args)
{
  int i;
  printf("Stephen Brennan's LSH\n");
  printf("Type program names and arguments, and hit enter.\n");
  printf("The following are built in:\n");

  for (i = 0; i < num_builtins(); i++) {
    printf("  %s\n", builtin_str[i]);
  }

  printf("Use the man command for information on other programs.\n");
  return 1;
}
