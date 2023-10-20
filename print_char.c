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
 * print_ascii - Non printable characters
 * @list: va_list arguments from _printf
 * Return: number of char printed
 */
int print_ascii(va_list list)
{
	int count = 0, i;
	char *s = va_arg(list, char *);

	if (!s)
		return (_puts("(null)"));

	for (i = 0; s[i]; i++)
	{
		if (s[i] > 0 && (s[i] < 32 || s[i] >= 127))
		{
			count += _puts("\\x");
			count += _putchar("0123456789ABCDEF"[s[i] / 16]);
			count += _putchar("0123456789ABCDEF"[s[i] % 16]);
		}
		else
		{
			count += _putchar(s[i]);
		}
	}
	return (count);
}

/**
 * print_character - prints string
 * @list: va_list of arguments from _printf
 * Return: number of char printed
 */
int print_character(va_list list, char f)
{
		if (f == '+')
			_putchar('+');
		if (f == ' ' && f != '+')
			_putchar(' ');
	_putchar(va_arg(list, int));
	return (1);
}
