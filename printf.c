#include "main.h"

/**
 * _printf - Print a formatted string to stdout
 * @format: Format string
 * @...: Arguments to format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	int counter = 0;
	va_list args;
	print_t p[] = {
		{'s', p_str},
		{'c', p_char},
		{'d', p_int},
		{'i', p_int},
		{'%', p_percent},
		{'\0', NULL}
	};

	if (!format)
		return (-1);

	va_start(args, format);
	counter = _printf_helper(format, p, args);
	va_end(args);

	return (counter);
}

/**
 * _printf_helper - Print a formatted string to stdout
 * @format: Format string
 * @p: Array of print_t structs
 * @args: Arguments to format string
 *
 * Return: Number of characters printed
 */
int _printf_helper(const char *format, print_t p[], va_list args)
{
	int i = 0, counter = 0;

	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			counter += _stdout(format[i]);
			continue;
		}
		if (!format[i + 1])
			return (-1);
		counter += to_format(format[i + 1], p, args), i++;
	}
	return (counter);
}

/**
 * to_format - Print a formatted string to stdout
 * @c: Format character
 * @p: Array of print_t structs
 * @args: Arguments to format string
 *
 * Return: Number of characters printed
 */
int to_format(char c, print_t p[], va_list args)
{
	int i = 0;

	while (p[i].type)
	{
		if (p[i].type == c)
			return (p[i].f(args));
		i++;
	}
	return (_stdout('%') + _stdout(c));
}
