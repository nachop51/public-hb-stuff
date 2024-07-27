#include "shell.h"

/**
 * list_to_vector - converts a list to a vector
 * @h: list
 * Return: pointer to a vector
 */
char **list_to_vector(list_t *h)
{
	int i = 0;
	char **v = NULL;

	if (!h)
		return (NULL);
	v = malloc(sizeof(char *) * (list_len(h) + 1));
	if (!v)
		return (NULL);
	while (h)
	{
		v[i] = h->s;
		h = h->next, i++;
	}
	v[i] = NULL;
	return (v);
}

/**
 * print_vector - prints a linked vector
 * @v: vector
 */
void print_vector(char **v)
{
	int i = 0;

	while (v[i])
		printf("%d -> .%s.\n", i, v[i]), i++;
}

/**
 * free_vector - frees a vector
 * @v: vector
 */
void free_vector(char **v)
{
	int i = 0;

	while (v[i])
		free(v[i]), i++;
	free(v);
}
