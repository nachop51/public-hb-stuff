#include "shell.h"

/**
 * before_exit - frees memory before exiting
 * @cmd: command struct
 * @free_items: flag to free cmd items
 *
 * Return: Exit value
 */
unsigned char before_exit(cmd_t **cmd, char free_items)
{
	unsigned char exit_value = (*cmd)->err;

	if (free_items)
		free_cmd_items(cmd);
	free_list((*cmd)->path);
	hash_table_delete((*cmd)->env);
	free((*cmd)->buffer), free(*cmd);
	return (exit_value);
}
