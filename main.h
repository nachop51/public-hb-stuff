#ifndef PRINTF_H
#define PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

#define BUFFER_SIZE 1024

/**
 * struct buffer - Struct buffer
 * @buf: The buffer
 * @i: The index
 */
typedef struct buffer
{
	char buf[BUFFER_SIZE];
	int i;
	int counter;
} buffer_t;

/**
 * struct print - Struct print
 *
 * @type: The operator
 * @f: The function associated
 */
typedef struct print
{
	char type;
	void (*f)(buffer_t *, va_list);
} print_t;

/* buffer.c */

void init_buffer(buffer_t *buffer);
void flush_buffer(buffer_t *buffer);
int write_buffer(buffer_t *buffer, char c);
int write_buffer_str_n(buffer_t *buffer, char *str, int n);

/* printf.c */

int _printf(const char *format, ...);
int _printf_helper(const char *format, print_t p[], buffer_t *, va_list args);
int to_format(const char *format, print_t p[], buffer_t *buffer, va_list args);

/* strings.c */

int _stdout(char c);
int _strlen(char *s);
int _is_alpha(char c);

/* format_functions.c */

void p_str(buffer_t *buffer, va_list args);
void p_char(buffer_t *buffer, va_list args);
void p_int(buffer_t *buffer, va_list args);
void p_percent(buffer_t *buffer, va_list args);
void p_u_int(buffer_t *buffer, va_list args);
void p_binary(buffer_t *buffer, va_list args);
void p_octal(buffer_t *buffer, va_list args);
void p_hex(buffer_t *buffer, va_list args);
void p_hex_upper(buffer_t *buffer, va_list args);
void p_pointer(buffer_t *buffer, va_list args);
void p_reverse(buffer_t *buffer, va_list args);
void p_string_ascii(buffer_t *buffer, va_list args);
void p_rot13(buffer_t *buffer, va_list args);

void print_base(unsigned int n, char *base, int base_len, buffer_t *buffer);
void print_base_long(unsigned long n, char *base,
					 int base_len, buffer_t *buffer);

#endif /* PRINTF_H */
