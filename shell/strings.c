#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length of string
 */
int _strlen(const char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: 0 if strings are equal, otherwise the difference
 */
int _strcmp(const char *s1, const char *s2)
{
	int i = 0;

	for (; s1[i] && s2[i]; i++)
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	return (s1[i] - s2[i]);
}

/**
 * _strdup - duplicates a string
 * @str: string
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	char *dup = NULL;
	int i = 0, len = 0;

	if (!str)
		return (NULL);
	len = _strlen(str);
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	for (; i < len; i++)
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}

/**
 * _strcpy - copies a string
 * @dest: destination
 * @src: source
 */
void _strcpy(char *dest, const char *src)
{
	int i = 0;

	for (; src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';
}

/**
 * _atoi - convert a string to an integer
 * @s: string to convert
 * Return: integer value of string
 */
int _atoi(const char *s)
{
	int i = 0, sign = 1, num = 0;

	while (s[i] && (s[i] < '0' || s[i] > '9'))
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	i = 0;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		num *= 10;
		num += (s[i] - '0');
		i++;
	}
	return (num * sign);
}
