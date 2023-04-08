#include "main.h"

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
 * print_base - print a number in a given base
 * @n: number to print
 * @base: base to print in
 * @base_len: length of base
 * @buffer: buffer to write to
 */
void print_base_long(unsigned long n, char *base,
					 int base_len, buffer_t *buffer)
{
	if (n / base_len)
		print_base(n / base_len, base, base_len, buffer);
	write_buffer(buffer, base[n % base_len]);
}
