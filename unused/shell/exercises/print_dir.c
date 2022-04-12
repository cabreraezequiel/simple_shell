#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;


int main(void)
{
	char *path = getenv("PATH");
	list_t *head;
	int i = 0;

	head = malloc(sizeof(list_t));
	head->str = (strdup(strtok(path, ":" "\n")));
	while(head->next != NULL)
	{
		head = head->next;
		head->str = (strdup(strtok(NULL, ":" "\n")));
	}

	return (0);
}
