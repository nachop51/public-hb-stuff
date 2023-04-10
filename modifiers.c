#include "main.h"

/**
 * reset_modifiers - reset modifiers
 * @buffer: buffer to reset
 */
void reset_modifiers(buffer_t *buffer)
{
	buffer->mod.flags = 0;
	buffer->mod.width = 0;
	buffer->mod.precision = 0;
	buffer->mod.length = 0;
}

/**
 * detect_modifiers - Detects modifiers in a format string
 * @format: Format string
 * @buffer: Buffer to write to
 * @j: Index of format string
 *
 * Return: How much to increment i in
 * _printf_helper, or -1 on error
 */
int detect_modifiers(const char *format, buffer_t *buffer, int j)
{
	int i = 1, increment = 0;

	for (; format[i] && format[i] != '%' && i < j; i++)
	{
		if (is_flag(format[i], buffer))
		{
			increment++;
			continue;
		}
		else if (format[i] >= '0' && format[i] <= '9')
		{
			buffer->mod.width = _atoi(format + i);
			while (format[i] >= '0' && format[i] <= '9')
			{
				i++;
				increment++;
			}
			i--;
			continue;
		}
		else if (format[i] == '.')
		{
			buffer->mod.precision = _atoi(format + i + 1);
			while (format[i] >= '0' && format[i] <= '9')
			{
				i++;
				increment++;
			}
			i--;
			continue;
		}
		if (is_length(format[i], buffer))
		{
			increment++;
			continue;
		}
	}

	return (increment);
}

/**
 * is_flag - Checks if a character is a flag
 * @c: Character to check
 * Return: 1 if flag, 0 if not
 */
int is_flag(char c, buffer_t *buffer)
{
	char *flags = "-0+ #";
	int i = 0;

	if (buffer->mod.width != 0 ||
		buffer->mod.precision != 0 ||
		buffer->mod.length != 0)
		return (0);
	for (; flags[i]; i++)
	{
		if (c == flags[i])
		{
			buffer->mod.flags |= 1 << i;
			return (1);
		}
	}
	return (0);
}

/**
 * is_length - Checks if a character is a length
 * @c: Character to check
 * Return: 1 if length, 0 if not
 */
int is_length(char c, buffer_t *buffer)
{
	char *lengths = "hl";
	int i = 0;

	for (; lengths[i]; i++)
	{
		if (c == lengths[i])
		{
			buffer->mod.length |= 1 << i;
			return (1);
		}
	}
	return (0);
}

/**
 * possible_modifier - Check if a character is a possible modifier
 * @c: Character to check
 * Return: 1 if it is, 0 if it isn't
 */
int possible_modifier(char c, buffer_t *buffer)
{
	if (is_flag(c, buffer) || is_length(c, buffer) ||
		(c >= '0' && c <= '9') || c == '.')
		return (1);
	return (0);
}
