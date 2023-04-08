#include "main.h"

/**
 * p_str - print a string
 * @args: argument list
 * @buffer: buffer to write to
 */
void p_str(buffer_t *buffer, va_list args)
{
	char *str = va_arg(args, char *);

	if (!str)
		str = "(null)";
	write_buffer_str_n(buffer, str, _strlen(str));
}

/**
 * p_char - print a character
 * @args: argument list
 * @buffer: buffer to write to
 */
void p_char(buffer_t *buffer, va_list args)
{
	char c = va_arg(args, int);

	write_buffer(buffer, c);
}

/**
 * p_percent - print a percent sign
 * @args: argument list
 * @buffer: buffer to write to
 */
void p_percent(buffer_t *buffer, va_list args)
{
	(void)args;
	write_buffer(buffer, '%');
}

/**
 * p_int - print an integer
 * @args: argument list
 * @buffer: buffer to write to
 */
void p_int(buffer_t *buffer, va_list args)
{
	int n = va_arg(args, int);
	long int i;

	n < 0 ? write_buffer(buffer, '-') : 0;
	n = (n < 0 ? -n : n);
	i = n;
	print_base(i, "0123456789", 10, buffer);
}
