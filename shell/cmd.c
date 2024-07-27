#include "shell.h"

/**
 * setup_cmd - sets up the command struct
 * @av: arguments
 * Return: command struct
 */
cmd_t *setup_cmd(char **av)
{
	cmd_t *cmd = NULL;

	cmd = malloc(sizeof(cmd_t));
	if (!cmd)
		return (NULL);
	cmd->vector = NULL, cmd->list = NULL, cmd->err = 0;
	cmd->buffer = NULL;
	cmd->env = map_environ(av);
	cmd->tty = isatty(STDIN_FILENO) == INTERACTIVE_MODE;
	cmd->path = map_path(_getenv(cmd->env, "PATH"));
	if (av[1])
	{
		cmd->fd = open(av[1], O_RDONLY);
		if (cmd->fd == -1)
			perror(av[1]), exit(EXIT_FAILURE);
	}
	else
		cmd->fd = STDIN_FILENO;

	return (cmd);
}

/**
 * free_cmd_items - frees the items in the command struct
 * @cmd: command struct
 */
void free_cmd_items(cmd_t **cmd)
{
	free_list((*cmd)->list);
	(*cmd)->list = NULL;
	if ((*cmd)->vector)
		free((*cmd)->vector);
	(*cmd)->vector = NULL;
}

/**
 * execute_cmd - executes the command
 * @cmd: command struct
 * Return: 0 on success, 1 on failure
 */
int execute_cmd(cmd_t **cmd)
{
	int child_pid = 0, status = 0, failed = 0;

	child_pid = fork();
	if (child_pid == -1)
		perror("Fork failed"), exit(EXIT_FAILURE);

	if (child_pid == 0)
		if (execve((*cmd)->vector[0], (*cmd)->vector, environ) == -1)
			perror((*cmd)->buffer), failed = 1, (*cmd)->err = errno;
	wait(&status);
	if (WIFEXITED(status))
		(*cmd)->err = WEXITSTATUS(status);
	return (failed);
}
