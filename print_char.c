#include "main.h"

/**
 * print_string - prints string
 * @list: va_list of arguments from _printf
 * Return: number of char printed
 */

int print_string(va_list list)
{
	char *string = va_arg(list, char *);

	if (!string)
		string = "(null)";

	return (_puts(string));
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
