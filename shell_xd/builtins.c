#include "shell.h"

/**
 * is_builtin - Determines if a command is a builtin
 * @cmd: command struct
 * Return: 1 if builtin, 0 if not builtin or error occured
 */
int is_builtin(cmd_t **cmd)
{
	int i = 0;
	builtin_t builtins[] = {
		{"exit", b_exit},
		{"env", b_env},
		{NULL, NULL},
	};

	for (; builtins[i].name; i++)
		if (_strcmp((*cmd)->list->s, builtins[i].name) == 0)
		{
			builtins[i].f(cmd);
			return (1);
		}
	return (0);
}

/**
 * b_exit - Builtin function to exit the shell
 * @cmd: command struct
 *
 * Return: exit value
 */
int b_exit(cmd_t **cmd)
{
	unsigned char err = 0, tmp = 0;

	if ((*cmd)->vector[1])
		tmp = (*cmd)->err = atoi((*cmd)->vector[1]);

	err = before_exit(cmd, 1);
	if (tmp)
		err = tmp;
	exit(err);
}

/**
 * b_env - Builtin function to print the environment
 * @cmd: command struct
 * Return: 0 always
 */
int b_env(cmd_t **cmd)
{
	hash_table_print((*cmd)->env, ENVIRONMENT);
	return (0);
}
