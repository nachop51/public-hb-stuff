#include "shell.h"

/**
 * is_exec - Checks if the path is executable
 * @path: Route of the file
 *
 * Return: If it is executable or not
 */
int is_exec(char *path)
{
	if (access(path, X_OK) == 0)
		return (1);
	return (0);
}

/**
 * valid_file - Checks if a file exists, is regular and executable
 * @path: Route of the file
 *
 * Return: If the file exists or not
 */
int valid_file(char *path)
{
	struct stat st = {0};

	if (!path)
		return (0);
	if (path[0] != '.' && path[0] != '/')
		return (0);
	if (stat(path, &st) != 0) /* File exists ? */
		return (0);
	if (!(S_ISREG(st.st_mode))) /* Is a regular file ? */
		return (0);
	if (!(st.st_mode & S_IXUSR)) /* Is executable ? */
		return (0);
	return (1);
}
