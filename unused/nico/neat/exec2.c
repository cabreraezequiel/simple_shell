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
	&history
};

int launch(char **args)
{
  pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid == 0) {
    /* Child process*/
    if (execvp(args[0], args) == -1) {
      perror("lsh");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    /* Error forking*/
    perror("lsh");
  } else {
    /* Parent process*/
    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}

int execute(char **args)
{
  int i;

  if (args[0] == NULL) {
    /* An empty command was entered.*/
    return 1;
  }

  for (i = 0; i < num_builtins(); i++) {
    if (strcmp(args[0], builtin_str[i]) == 0) {
      return (*builtin_func[i])(args);
    }
  }

  return launch(args);
}
