#include "main.h"

/**
 * print_base_short - print a number in a given base
 * @n: number to print
 * @base: base to print in
 * @base_len: length of base
 * @buffer: buffer to write to
 */
void print_base_short(unsigned short int n, char *base,
					  int base_len, buffer_t *buffer)
{
	if (n / base_len)
		print_base_short(n / base_len, base, base_len, buffer);
	write_buffer(buffer, base[n % base_len]);
}

/**
 * print_base - print a number in a given base
 * @n: number to print
 * @base: base to print in
 * @base_len: length of base
 * @buffer: buffer to write to
 */
void print_base(unsigned int n, char *base, int base_len, buffer_t *buffer)
{
	if (n / base_len)
		print_base(n / base_len, base, base_len, buffer);
	write_buffer(buffer, base[n % base_len]);
}

/**
 * print_base_long - print a number in a given base
 * @n: number to print
 * @base: base to print in
 * @base_len: length of base
 * @buffer: buffer to write to
 */
void print_base_long(unsigned long n, char *base,
					 int base_len, buffer_t *buffer)
{
	if (n / base_len)
		print_base_long(n / base_len, base, base_len, buffer);
	write_buffer(buffer, base[n % base_len]);
}

/**
 * print_symbol - print a symbol for a number
 * @n: number to print symbol for
 * @buffer: buffer to write to
 */
void print_symbol(long n, buffer_t *buffer)
{
	if (n < 0)
		write_buffer(buffer, '-');
	else if (buffer->mod.flags & FLAG_PLUS)
		write_buffer(buffer, '+');
	else if (buffer->mod.flags & FLAG_SPACE)
		write_buffer(buffer, ' ');
}
