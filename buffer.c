#include "main.h"

/**
 * init_buffer - initialize a buffer
 * @buffer: buffer to initialize
 */
void init_buffer(buffer_t *buffer)
{
	int i = 0;
	mod_t mod = {0, 0, 0, 0};

	buffer->i = 0;
	buffer->counter = 0;
	while (i < BUFFER_SIZE)
		buffer->buf[i++] = '\0';
	buffer->mod = mod;
}

/**
 * flush_buffer - flush a buffer
 * @buffer: buffer to flush
 * Return: number of characters printed
 */
void flush_buffer(buffer_t *buffer)
{
	int i = 0;

	write(1, buffer->buf, buffer->i);
	while (i < buffer->i)
		buffer->buf[i++] = '\0';
	buffer->i = 0;
}

/**
 * write_buffer - write a character to a buffer
 * @buffer: buffer to write to
 * @c: character to write
 * Return: number of characters printed
 */
int write_buffer(buffer_t *buffer, char c)
{
	if (buffer->i == BUFFER_SIZE)
		flush_buffer(buffer);
	buffer->buf[buffer->i++] = c;
	buffer->counter++;
	return (1);
}

/**
 * write_buffer_str_n - write a string to a buffer
 * @buffer: buffer to write to
 * @str: string to write
 * @n: number of characters to write
 * Return: number of characters printed
 */
int write_buffer_str_n(buffer_t *buffer, char *str, int n)
{
	int i = 0;

	while (str[i] && i < n)
		write_buffer(buffer, str[i++]);
	return (i);
}
