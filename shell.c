#include "shell.h"

/**
 * main - Entry point
 * @ac: argument count
 * @av: argument vector
 *
 * Return: Status code of the last command executed
 */
int main(__attribute__((unused)) int ac, char **av)
{
	int i = 0, failed = 0;
	cmd_t *cmd = NULL;
	size_t n = 0;

	cmd = setup_cmd(av);
	for (; 1; i++)
	{
		if (cmd->tty == INTERACTIVE_MODE)
			write(STDOUT_FILENO, PROMPT, _strlen(PROMPT));
		if (getline(&cmd->buffer, &n, stdin) == EOF)
			break;
		if (!evaluate_input(&cmd))
		{
			free_cmd_items(&cmd);
			continue;
		}
		failed = execute_cmd(&cmd);
		free_cmd_items(&cmd);
		if (failed)
			break;
	}
	return (before_exit(&cmd, 0));
}

/**
 * evaluate_input - Tokenizes the input
 * @cmd: command struct
 *
 * Return: 0 not valid, positive integer if valid
 */
int evaluate_input(cmd_t **cmd)
{
	char *tok = NULL, *dup = _strdup(strtok((*cmd)->buffer, "\n"));
	int ret = 0;

	if (!dup)
		perror("Malloc failed"), exit(EXIT_FAILURE);
	tok = strtok(dup, "\n"), tok = strtok(dup, " \t\r");
	while (tok)
	{
		if (tok[0] == '#')
			break;
		add_node_end(&(*cmd)->list, tok);
		tok = strtok(NULL, " \t\r");
	}
	free(dup);
	if (!(*cmd)->list) /* Empty line */
		return (0);

	(*cmd)->vector = list_to_vector((*cmd)->list);

	if (is_builtin(cmd))
		return (0);

	ret = solve_path(cmd);
	if (ret == 1 && !valid_file((*cmd)->list->s))
	{
		perror((*cmd)->list->s), (*cmd)->err = 127; /* Command not found */
		return (0);									/* Not found error */
	}

	return (1);
}

/**
 * solve_path - Solve path
 * @cmd: command struct
 * Return: 1 if the input is route, 0 otherwise
 */
int solve_path(cmd_t **cmd)
{
	list_t *path = NULL;
	char *tmp = NULL;

	if ((*cmd)->list->s[0] == '/')
		return (1);

	for (path = (*cmd)->path; path; path = path->next)
	{
		tmp = _str_concat(path->s, (*cmd)->list->s);
		if (!tmp)
			perror("Malloc failed"), exit(EXIT_FAILURE);
		if (valid_file(tmp))
		{
			free((*cmd)->list->s);
			(*cmd)->list->s = tmp, (*cmd)->vector[0] = tmp;
			return (0);
		}
		free(tmp);
	}

	return (1);
}
