#include "main.h"

/**
 * p_str - print a string
 * @args: argument list
 *
 * Return: number of characters printed
 */
int p_str(va_list args)
{
	char *str = va_arg(args, char *);

	if (!str)
		str = "(null)";
	return (write(1, str, _strlen(str)));
}

/**
 * p_char - print a character
 * @args: argument list
 *
 * Return: number of characters printed
 */
int p_char(va_list args)
{
	char c = va_arg(args, int);

	return (_stdout(c));
}

/**
 * p_percent - print a percent sign
 * @args: argument list
 *
 * Return: number of characters printed
 */
int p_percent(va_list args)
{
	(void)args;
	return (_stdout('%'));
}

int p_int_helper(int n)
{
	int counter = 0;

	while (n / 10)
	{
		counter += p_int_helper(n / 10);
		n %= 10;
	}
	counter += _stdout(abs(n) + '0');
	return (counter);
}

/**
 * p_int - print an integer
 * @args: argument list
 * Return: number of characters printed
 */
int p_int(va_list args)
{
	int n = va_arg(args, int);

	return ((n >= 0 ? 0 : _stdout('-')) + p_int_helper(n));
}
