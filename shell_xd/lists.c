#include "shell.h"

/**
 * free_list -  frees a list
 * @head: list to free
 */
void free_list(list_t *head)
{
	list_t *tmp = NULL;

	while (head != NULL)
	{
		tmp = head;
		free(tmp->s);
		head = head->next;
		free(tmp);
	}
}

/**
 * add_node_end - adds a node to the end of a list
 * @h: list
 * @value: value to add
 * Return: pointer to the new node
 */
list_t *add_node_end(list_t **h, char *value)
{
	list_t *new = NULL, *last = NULL;

	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);
	new->s = _strdup(value);
	new->next = NULL;
	if (!*h)
	{
		*h = new;
		return (new);
	}
	last = *h;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = new;

	return (new);
}

/**
 * list_len - returns the number of elements in a linked list
 * @h: list
 * Return: number of elements
 */
size_t list_len(list_t *h)
{
	size_t i = 0;

	while (h)
		h = h->next, i++;
	return (i);
}

/**
 * print_list - prints a linked list
 * @h: list
 */
void print_list(list_t *h)
{
	int i = 0;

	while (h)
	{
		printf("%d -> .%s.\n", i, h->s);
		h = h->next, i++;
	}
}
