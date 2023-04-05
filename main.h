#ifndef PRINTF_H
#define PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * struct print - Struct print
 *
 * @type: The operator
 * @f: The function associated
 */
typedef struct print
{
	char type;
	int (*f)(va_list);
} print_t;

int _printf(const char *format, ...);
int _printf_helper(const char *format, print_t p[], va_list args);
int to_format(char c, print_t p[], va_list args);

/* strings.c */

int _stdout(char c);
int _strlen(char *s);

/* format_functions.c */

int p_str(va_list args);
int p_char(va_list args);
int p_int(va_list args);
int p_percent(va_list args);

#endif /* PRINTF_H */
