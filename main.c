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

	len = _printf("%b", 1024);
	len2 = printf("10000000000");
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);

		printf("%d\n",len);
		printf("%d",len2);
		return (1);
	}

	return (0);
}
