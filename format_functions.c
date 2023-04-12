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
	int i = 0, n_len = 0;
	long int long_n = 0;

	if (buffer->mod.length & LENGTH_L)
		long_n = va_arg(args, long int);
	else
		long_n = va_arg(args, int);

	n_len = number_length(long_n, 10, buffer->mod.flags);

	if (buffer->mod.width > n_len)
	{
		if (buffer->mod.flags & FLAG_ZERO)
			print_symbol(long_n, buffer);
		while (i++ < buffer->mod.width - n_len)
		{
			if (buffer->mod.flags & FLAG_ZERO)
				write_buffer(buffer, '0');
			else
				write_buffer(buffer, ' ');
		}
	}
	if (!(buffer->mod.flags & FLAG_ZERO))
		print_symbol(long_n, buffer);
	print_number(long_n, 10, buffer, 0);
}

void print_number(long n, int base_len, buffer_t *buffer, int upper)
{
	char *base = "0123456789abcdef";
	unsigned long unsigned_n = n;

	if (upper)
		base = "0123456789ABCDEF";

	if (n < 0)
		unsigned_n = -n;

	if (buffer->mod.length & LENGTH_L)
		print_base_long(unsigned_n, base, base_len, buffer);
	else if (buffer->mod.length & LENGTH_H)
		print_base_short(unsigned_n, base, base_len, buffer);
	else
		print_base(unsigned_n, base, base_len, buffer);
}
