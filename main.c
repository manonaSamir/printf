#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len, len2;

	len = _printf("%x", 0);
	len2 = printf("%x", 0);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		printf("%d\n", len);
		printf("%d", len2);
		fflush(stdout);
		return (1);
	}
	return (0);
}
