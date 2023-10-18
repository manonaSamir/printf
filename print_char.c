#include "main.h"

/**
 * print_string - prints string
 * @list: va_list of arguments from _printf
 * Return: number of char printed
 */

int print_string(va_list list)
{

	char *string = va_arg(list, char *);
	int i, count = 0;
	char temp[5];

	if (!string)
		string = "(null)";

	for (i = 0; string[i] != '\0'; i++)
	{
		sprintf(temp, "\\x%02x", (unsigned char)string[i]);
		count += _puts(temp);
	}
	return count;
}

/**
 * print_character - prints string
 * @list: va_list of arguments from _printf
 * Return: number of char printed
 */
int print_character(va_list list)
{
	_putchar(va_arg(list, int));
	return (1);
}
