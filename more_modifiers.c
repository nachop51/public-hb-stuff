#include "main.h"

/**
 * print_width - print the width
 * @buffer: buffer to write to
 * @length: Length of the object
 *
 * Return: 1 if number has a sign, 0 otherwise
 */
void print_width(buffer_t *buffer, int length)
{
	int i = 0;
	char c = buffer->mod.flags & FLAG_ZERO ? '0' : ' ';

	if (buffer->mod.flags & FLAG_ZERO && buffer->mod.precision >= 0)
		c = ' ';

	if (buffer->mod.width > length)
		while (i++ < buffer->mod.width - length)
			write_buffer(buffer, c);
}

/**
 * print_precision - print the precision
 * @buffer: buffer to write to
 * @length: Length of the object
 */
void print_precision(buffer_t *buffer, int length)
{
	int i = 0;

	if (buffer->mod.precision > length)
	{
		for (i = 0; i < buffer->mod.precision - length; i++)
			write_buffer(buffer, '0');
	}
}

/**
 * format_number - Format a number
 * @n: number to format
 * @base: base of the number
 * @buffer: buffer to write to
 */
void format_number(long int long_n, int base, buffer_t *buffer, int upper)
{
	int n_len = 0, old_len = 0;

	n_len = number_length(long_n, base);
	old_len = n_len;

	if (buffer->mod.precision > n_len)
		n_len = buffer->mod.precision;

	n_len += has_sign(long_n, buffer);

	if (buffer->mod.flags & FLAG_ZERO)
	{
		print_symbol(long_n, buffer);
		print_width(buffer, n_len);
	}
	else
	{
		print_width(buffer, n_len);
		print_symbol(long_n, buffer);
	}

	/* print the precision using the old length */
	print_precision(buffer, old_len);

	print_number(long_n, base, buffer, upper);
}

/**
 * print_number - print a number in a given base
 * @n: number to print
 * @base_len: length of base
 * @buffer: buffer to write to
 */
void print_number(long n, int base_len, buffer_t *buffer, int upper)
{
	char *base = BASE_16;
	unsigned long unsigned_n = n;

	if (upper)
		base = BASE_16_UPPER;

	if (n < 0)
		unsigned_n = -n;

	if (buffer->mod.length & LENGTH_L)
		print_base_long(unsigned_n, base, base_len, buffer);
	else if (buffer->mod.length & LENGTH_H)
		print_base_short(unsigned_n, base, base_len, buffer);
	else
		print_base(unsigned_n, base, base_len, buffer);
}

/**
 * has_sign - Determine if a number has a sign
 * @n: number to check
 * @buffer: buffer to write to
 *
 * Return: 1 if number has a sign, 0 otherwise
 */
int has_sign(long int n, buffer_t *buffer)
{
	char sign = 0;

	if (n >= 0)
	{
		if (buffer->mod.flags & FLAG_PLUS)
			++sign;
		else if (buffer->mod.flags & FLAG_SPACE)
			++sign;
	}
	else
		++sign;
	return (sign);
}
