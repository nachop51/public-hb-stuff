#include "shell.h"

/**
 * map_environ - Maps environ to a hash table
 * Return: Hash table that contains environ variables
 */
hash_table_t *map_environ(char **av)
{
	ulint i = 0;
	hash_table_t *new = NULL;
	char *key = NULL, *value = NULL, *dup = NULL;

	new = hash_table_create(HASH_ARRAY_LENGTH);
	if (!new)
		perror("Malloc failed"), exit(EXIT_FAILURE);

	while (environ[i])
	{
		dup = strdup(environ[i]);
		if (!dup)
			perror("Malloc failed"), exit(EXIT_FAILURE);
		key = strtok(dup, "="), value = strtok(NULL, "=");
		if (!value)
			value = "";
		hash_table_set(new, key, value);
		free(dup);
		i++;
	}
	hash_table_set(new, "SHELL", av[0]);
	return (new);
}

/**
 * _getenv - gets the value of an environment variable
 * @env: hash table
 * @name: name of the variable
 * Return: value of the variable
 */
char *_getenv(hash_table_t *env, const char *name)
{
	if (!name)
		return (NULL);
	return (hash_table_get(env, name));
}

/**
 * ht_to_array - converts a hash table to an array
 * @ht: hash table
 * Return: array
 */
char **ht_to_array(hash_table_t *ht)
{
	ulint i = 0, j = 0, k_len = 0, v_len = 0;
	char **array = NULL;

	array = malloc(sizeof(char *) * (ht->size + 1));
	if (!array)
		return (NULL);
	for (i = 0; i < ht->size; i++)
	{
		if (ht->array[i])
		{
			k_len = _strlen(ht->array[i]->key);
			v_len = _strlen(ht->array[i]->value);
			array[j] = malloc(sizeof(char) * (k_len + v_len + 2));
			if (!array[j])
				return (NULL);
			_strcpy(array[j], ht->array[i]->key);
			strcat(array[j], "=");
			strcat(array[j], ht->array[i]->value);
			if (!array[j])
				return (NULL);
			j++;
		}
	}
	array[j] = NULL;
	return (array);
}
