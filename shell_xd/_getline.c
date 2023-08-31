#include "shell.h"

/**
 * solve_getline - gets a line from stdin
 * @cmd: command struct
 * Return: 0 on EOF, 1 otherwise
 */
int solve_getline(cmd_t **cmd)
{
	size_t i = 0;

	if ((*cmd)->tty == INTERACTIVE_MODE)
		write(STDOUT_FILENO, PROMPT, _strlen(PROMPT));
	if (getline(&(*cmd)->buffer, &i, stdin) == EOF)
		return (0);
	return (1);
}
