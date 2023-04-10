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
 * number_length - get the length of a number
 * @n: number to get length of
 * @base_len: length of base
 * Return: length of number
 */
int number_length(long n, int base_len)
{
	int len = 0;

	n < 0 ? ++len : 0;
	while (n / base_len)
	{
		n /= base_len;
		++len;
	}
	return (len + 1);
}
