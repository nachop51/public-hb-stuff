#include "main.h"

/**
 * _stdout - write a character to stdout
 * @c: character to write
 *
 * Return: 1 on success, -1 on error
 */
int _stdout(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strlen - return the length of a string
 * @s: string to measure
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}
