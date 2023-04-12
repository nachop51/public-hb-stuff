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
	int ret = 0;
	va_list args;
	print_t p[] = {
		{'s', p_str},
		{'c', p_char},
		{'d', p_int},
		{'i', p_int},
		{'u', p_u_int},
		{'%', p_percent},
		{'b', p_binary},
		{'o', p_octal},
		{'x', p_hex},
		{'X', p_hex_upper},
		{'p', p_pointer},
		{'r', p_reverse},
		{'S', p_string_ascii},
		{'R', p_rot13},
		{'\0', NULL}
	};
	buffer_t buffer = {0};

	if (!format)
		return (-1);

	init_buffer(&buffer);
	va_start(args, format);
	ret = _printf_helper(format, p, &buffer, args);
	va_end(args);
	if (ret == -1)
		return (ret);

	flush_buffer(&buffer);
	return (buffer.counter);
}

/**
 * _printf_helper - Print a formatted string to stdout
 * @format: Format string
 * @p: Array of print_t structs
 * @buffer: Buffer to write to
 * @args: Arguments to format string
 *
 * Return: Number of characters printed
 */
int _printf_helper(const char *format, print_t p[],
				   buffer_t *buffer, va_list args)
{
	int i = 0, ret = 0;

	while (format[i])
	{
		if (format[i] != '%')
		{
			i += write_buffer(buffer, format[i]);
			continue;
		}
		ret = to_format(format + i, p, buffer, args);
		if (ret == -1)
			return (-1);
		i += ret;
	}
	return (ret);
}

/**
 * to_format - Print a formatted string to stdout
 * @format: Format string
 * @p: Array of print_t structs
 * @buffer: Buffer to write to
 * @args: Arguments to format string
 *
 * Return: How much to increment i in
 * _printf_helper, or -1 on error
 */
int to_format(const char *format, print_t p[], buffer_t *buffer, va_list args)
{
	int i = 0, j = 1, increment = 2; /* j starts in 1 beacuse 0 is the '%' */
	int flag = 0;
	/* increment starts in 2 because we already have the '%' and the type */

	reset_modifiers(buffer);
	for (; format[j]; j++, i = 0)
	{
		if (possible_modifier(format[j], buffer))
			continue;
		while (p[i].type)
		{
			if (p[i].type == format[j])
			{
				increment += detect_modifiers(format, buffer, j);
				p[i].f(buffer, args);
				return (increment);
			}
			i++;
		}
		if (_is_alpha(format[j]))
		{
			flag = 1;
			break;
		}
	}
	if (!flag)
		return (-1);
	write_buffer(buffer, '%');
	for (j = 1; flag && format[j] && format[j] != '%'; j++)
	{
		/* this need better evaluation than this */
		if (!is_length(format[j], buffer))
		{
			write_buffer(buffer, format[j]);
		}
	}
	return (j);
}
