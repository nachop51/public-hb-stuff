#include "shell.h"

/**
 * add_node_end_no_malloc - adds a node to the end of a list
 * @h: list
 * @value: value to add
 * Description: does not malloc
 * Return: pointer to the new node
 */
list_t *add_node_end_no_malloc(list_t **h, char *value)
{
	list_t *new = NULL, *last = NULL;

	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);
	new->s = value;
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
 * map_path - maps the path
 * @path: path
 * Return: list
 */
list_t *map_path(char *path)
{
	list_t *head = NULL;
	char *token = NULL, *dup = NULL, *concat = NULL;

	if (!path)
		return (NULL);
	dup = _strdup(path);
	if (!dup)
		return (NULL);
	token = strtok(dup, ":");
	while (token)
	{
		concat = _str_concat(token, "/");
		if (!concat)
			return (NULL);
		if (!add_node_end_no_malloc(&head, concat))
			return (NULL);
		token = strtok(NULL, ":");
	}
	free(dup);
	return (head);
}
