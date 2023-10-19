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
	int i, count = 0, temp;
	static char buffer[50], *rep;
	char *ptr;
	char *s = va_arg(list, char *);

	if (!s)
		return (_puts("(null)"));

	for (i = 0; s[i]; i++)
	{
		if (s[i] > 0 && (s[i] < 32 || s[i] >= 127))
		{
			temp = s[i];
			_puts("\\x");
			count += 2;
			rep = "0123456789ABCDEF";
			ptr = &buffer[49];
			*ptr = '\0';
			do
			{
				*--ptr = rep[temp % 16];
				temp /= 16;
			} while (temp != 0);

			if (!ptr)
				count += _putchar('0');
			else
			{
				count += _putchar('0');
				count += _puts(ptr);
			}
		}
		else
			count += _putchar(s[i]);
	}
	return (count);
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
