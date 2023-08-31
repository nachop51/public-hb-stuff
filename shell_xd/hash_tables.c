#include "shell.h"

/**
 * hash_table_create - Creates a Hash Table
 *
 * @size: Size of the array
 * Return: A pointer to the Hash Table
 */
hash_table_t *hash_table_create(ulint size)
{
	hash_table_t *new = NULL;

	new = malloc(sizeof(hash_table_t));
	if (!new)
		exit(EXIT_FAILURE);
	new->array = calloc(size, sizeof(hash_node_t *));
	if (!new->array)
	{
		free(new);
		exit(EXIT_FAILURE);
	}
	new->size = size;
	return (new);
}

/**
 * hash_djb2 - implementation of the djb2 algorithm
 * @str: string used to generate hash value
 *
 * Return: hash value
 */
ulint hash_djb2(ucchar *str)
{
	ulint hash;
	int c;

	hash = 5381;
	while ((c = *str++))
	{
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}
	return (hash);
}

/**
 * key_index - Returns an index of a key
 *
 * @key: Key to hash
 * @size: size of the array
 * Return: index at which key/value pair should be stored
 */
ulint key_index(ucchar *key, ulint size)
{
	ulint result = 0;

	if (size == 0)
		return (0);

	result = hash_djb2(key);

	return (result % size);
}

/**
 * add_to_list - Inserts a node in the beginning of a list
 *
 * @list: Head of the linked list
 * @k: Key to insert
 * @v: Value
 * Return: A pointer to the head of the list
 */
hash_node_t *add_to_list(hash_node_t **list, const char *k, const char *v)
{
	hash_node_t *new;

	new = malloc(sizeof(hash_node_t));
	if (new == NULL)
		return (0);
	new->key = _strdup(k);
	new->value = _strdup(v);
	new->next = *list;
	*list = new;

	return (new);
}

/**
 * check_key - Looks if there is a key inside a list or not
 *
 * @hash_table: List
 * @key: key to check
 * Return: 1 if found or 0
 */
int check_key(hash_node_t **hash_table, char *key)
{
	hash_node_t *ht = *hash_table;

	while (ht)
	{
		if (_strcmp(ht->key, key) == 0)
			return (1);
		ht = ht->next;
	}
	return (0);
}
