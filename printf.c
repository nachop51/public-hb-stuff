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

	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			write_buffer(buffer, format[i]);
			continue;
		}
		if (!format[i + 1])
			return (-1);
		ret = to_format(format + i + 1, p, buffer, args), i++;
		if (ret == -1)
			return (-1);
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
 * Return: 1 on success, -1 on failure
 */
int to_format(const char *format, print_t p[], buffer_t *buffer, va_list args)
{
	int i = 0;

	while (p[i].type)
	{
		if (p[i].type == format[0])
		{
			p[i].f(buffer, args);
			return (1);
		}
		i++;
	}
	return (write_buffer(buffer, '%') + write_buffer(buffer, format[0]));
}
