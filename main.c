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

	len = _printf("%ld\n", -1024L);
	len2 = printf("%ld\n", -1024L);
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