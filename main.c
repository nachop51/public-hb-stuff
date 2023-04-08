#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len, len2;
	void *p = (void *)0x7fff5100b608;

	len = _printf("%p\n", p);
	len2 = printf("%p\n", p);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		printf("Actual: %d\n", len);
		printf("Expected: %d\n", len2);
		fflush(stdout);
		return (1);
	}
	return (0);
}
