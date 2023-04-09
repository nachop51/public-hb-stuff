#include "main.h"

/**
 * p_binary - print a number in binary
 * @buffer: buffer to write to
 * @args: argument list
 */
void p_binary(buffer_t *buffer, va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned long long_n;

	if (buffer->mod.length & LENGTH_L)
		long_n = va_arg(args, long);
	else
		n = va_arg(args, unsigned int);

	if (n != 0 && buffer->mod.flags & FLAG_HASH)
		write_buffer_str_n(buffer, "0b", 2);

	if (buffer->mod.length & LENGTH_L)
		print_base_long(long_n, "01", 2, buffer);
	else if (buffer->mod.length & LENGTH_H)
		print_base_short(n, "01", 2, buffer);
	else
		print_base(n, "01", 2, buffer);
}

/**
 * p_octal - print a number in octal
 * @buffer: buffer to write to
 * @args: argument list
 */
void p_octal(buffer_t *buffer, va_list args)
{
	unsigned int n;
	unsigned long long_n;

	if (buffer->mod.length & LENGTH_L)
		long_n = va_arg(args, long);
	else
		n = va_arg(args, unsigned int);

	if (n != 0 && buffer->mod.flags & FLAG_HASH)
		write_buffer(buffer, '0');
	if (buffer->mod.length & LENGTH_L)
		print_base_long(long_n, "01234567", 8, buffer);
	else if (buffer->mod.length & LENGTH_H)
		print_base_short(n, "01234567", 8, buffer);
	else
		print_base(n, "01234567", 8, buffer);
}

/**
 * p_hex - print a number in hexadecimal
 * @buffer: buffer to write to
 * @args: argument list
 */
void p_hex(buffer_t *buffer, va_list args)
{
	unsigned int n;
	unsigned long long_n;

	if (buffer->mod.length & LENGTH_L)
		long_n = va_arg(args, long);
	else
		n = va_arg(args, unsigned int);

	if (n != 0 && buffer->mod.flags & FLAG_HASH)
		write_buffer_str_n(buffer, "0x", 2);

	if (buffer->mod.length & LENGTH_L)
		print_base_long(long_n, "0123456789abcdef", 16, buffer);
	else if (buffer->mod.length & LENGTH_H)
		print_base_short(n, "0123456789abcdef", 16, buffer);
	else
		print_base(n, "0123456789abcdef", 16, buffer);
}

/**
 * p_hex_upper - print a number in hexadecimal
 * @buffer: buffer to write to
 * @args: argument list
 */
void p_hex_upper(buffer_t *buffer, va_list args)
{
	unsigned int n;
	unsigned long long_n;

	if (buffer->mod.length & LENGTH_L)
		long_n = va_arg(args, long);
	else
		n = va_arg(args, unsigned int);

	if (n != 0 && buffer->mod.flags & FLAG_HASH)
		write_buffer_str_n(buffer, "0X", 2);
	if (buffer->mod.length & LENGTH_L)
		print_base_long(long_n, "0123456789ABCDEF", 16, buffer);
	else if (buffer->mod.length & LENGTH_H)
		print_base_short(n, "0123456789ABCDEF", 16, buffer);
	else
		print_base(n, "0123456789ABCDEF", 16, buffer);
}
