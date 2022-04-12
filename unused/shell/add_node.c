#include "lists.h"
#include <string.h>

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: head of list
 * @str: str
 * Return: new head
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *nend;
	list_t *naux = *head;

	nend = malloc(sizeof(list_t));
	if (nend == NULL)
	{
		return (NULL);
	}
	nend->str = strdup(str);
	nend->len = strlen(str);
	nend->next = NULL;

	if (*head == NULL)
	{
		*head = nend;
	}
	else
	{
		while (naux->next != NULL)
		{
			naux = naux->next;
		}
		naux->next = nend;
	}
	return (nend);
}
