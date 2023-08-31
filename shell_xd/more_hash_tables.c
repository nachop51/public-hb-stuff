#include "shell.h"

/**
 * hash_table_set - Sets an item in a hash table
 *
 * @ht: Hash Table
 * @key: Key
 * @value: Value
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	ulint key_value = 0;

	if (!ht || !key)
		return (0);
	key_value = key_index((ucchar *)key, ht->size);
	if (check_key(&ht->array[key_value], (char *)key) == 1)
	{
		free(ht->array[key_value]->value);
		ht->array[key_value]->value = strdup(value);
	}
	else
		add_to_list(&ht->array[key_value], key, value);
	return (1);
}

/**
 * hash_table_get - Retrieves an element from the HashTable
 *
 * @ht: HashTable
 * @key: Key
 * Return: If the key exists returns the value, if not, null
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	ulint key_value = 0;
	hash_node_t **h = NULL, *aux = NULL;

	if (!ht || !key)
		return (NULL);
	key_value = key_index((ucchar *)key, ht->size);
	if (check_key(&ht->array[key_value], (char *)key) == 0)
		return (NULL);
	h = &ht->array[key_value];
	aux = *h;
	while (aux)
	{
		if (strcmp(aux->key, key) == 0)
			return (aux->value);
		aux = aux->next;
	}
	return (NULL);
}

/**
 * hash_table_print - Prints out a HashTable
 *
 * @ht: Hash table to print
 * @flag: Flag to print
 */
void hash_table_print(const hash_table_t *ht, int flag)
{
	size_t ht_size = 0;
	hash_node_t *aux = NULL;

	if (!ht)
		return;

	while (ht_size < ht->size)
	{
		aux = ht->array[ht_size];
		if (aux && aux->key)
		{
			while (aux)
			{
				if (flag)
					printf("%s='%s'\n", aux->key, aux->value);
				else
					printf("%s=%s\n", aux->key, aux->value);
				if (!aux->next)
					break;
				aux = aux->next;
			}
		}
		ht_size++;
	}
}

/**
 * hash_table_delete - Frees an entire HashTable
 *
 * @ht: Hash table to delete
 */
void hash_table_delete(hash_table_t *ht)
{
	size_t ht_size = 0;
	hash_node_t *aux = NULL, *tmp = NULL;

	if (!ht)
		return;

	while (ht_size < ht->size)
	{
		aux = ht->array[ht_size];
		while (aux)
		{
			tmp = aux;
			aux = aux->next;
			free(tmp->value);
			free(tmp->key);
			free(tmp);
		}
		ht_size++;
	}
	free(ht->array);
	free(ht);
}

/**
 * hash_table_delete_key - Deletes a key from a HashTable
 * @ht: Hash table
 * @key: Key to delete
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_delete_key(hash_table_t *ht, char *key)
{
	ulint key_value = 0;
	hash_node_t **h = NULL, *aux = NULL, *tmp = NULL;

	if (!ht || !key)
		return (0);
	key_value = key_index((ucchar *)key, ht->size);
	if (check_key(&ht->array[key_value], (char *)key) == 0)
		return (0);
	h = &ht->array[key_value];
	tmp = *h;
	if (strcmp(tmp->key, key) == 0 || !tmp->next)
	{
		*h = tmp->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
		return (1);
	}
	while (tmp && tmp->next && strcmp(tmp->next->key, key) != 0)
		tmp = tmp->next;
	if (!tmp->next)
		return (0);
	aux = tmp;
	tmp = tmp->next;
	tmp = tmp->next;
	free(aux->next->key);
	free(aux->next->value);
	free(aux->next);
	aux->next = tmp;
	return (1);
}
