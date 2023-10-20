
#include "main.h"

/**
 * print_specifier - prints anything.
 * @str: arguments.
 * Return: 1.
 */

int (*print_specifier(char str))(va_list, char flag)
{
	switch (str)
	{
	case 'i':
		return (print_number);
	case 'd':
		return (print_number);
	case 'c':
		return (print_character);
	case 'u':
		return (print_un_number);
	case 'f':
		return (print_fnumber);
	case 's':
		return (print_string);
	case 'S':
		return (print_ascii);
	case 'x':
		return (print_hex);
	case 'X':
		return (print_Big_hex);
	case 'o':
		return (print_octal);
	case 'b':
		return (print_binary);
	case 'R':
		return (print_rot13);
	case 'p':
		return (print_address);
	case 'r':
		return (print_reversed);
	case '%':
		return (print_percent);
	default:
		return (0);
	}
	return (NULL);
}
