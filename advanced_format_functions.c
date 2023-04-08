#include "main.h"

/**
 * p_binary - print a number in binary
 * @buffer: buffer to write to
 * @args: argument list
 */
void p_binary(buffer_t *buffer, va_list args)
{
	print_base(va_arg(args, unsigned int), "01", 2, buffer);
}

/**
 * p_octal - print a number in octal
 * @buffer: buffer to write to
 * @args: argument list
 */
void p_octal(buffer_t *buffer, va_list args)
{
	print_base(va_arg(args, unsigned int), "01234567", 8, buffer);
}

/**
 * p_hex - print a number in hexadecimal
 * @buffer: buffer to write to
 * @args: argument list
 */
void p_hex(buffer_t *buffer, va_list args)
{
	print_base(va_arg(args, unsigned int), "0123456789abcdef", 16, buffer);
}

/**
 * p_hex_upper - print a number in hexadecimal
 * @buffer: buffer to write to
 * @args: argument list
 */
void p_hex_upper(buffer_t *buffer, va_list args)
{
	print_base(va_arg(args, unsigned int), "0123456789ABCDEF", 16, buffer);
}
