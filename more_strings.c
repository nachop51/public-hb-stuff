#include "shell.h"

/**
 * _str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to the new string
 */
char *_str_concat(const char *s1, const char *s2)
{
	char *new = NULL;
	int len_s1 = 0, len_s2 = 0, i = 0, j = 0;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	len_s1 = _strlen(s1), len_s2 = _strlen(s2);
	new = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!new)
		return (NULL);
	for (; i < len_s1; i++)
		new[i] = s1[i];
	for (; j < len_s2; j++)
		new[i + j] = s2[j];
	new[i + j] = '\0';
	return (new);
}
