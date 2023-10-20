#include "main.h"

/**
 * print_address - prints address of input
 * @list: va_list arguments from _printf
 * @f: flag
 * Return: number of char printed
 */
int print_address(va_list list, char f)
{
	void *pointer = va_arg(list, void *);
	int count = 0, i, hexDigit, shift;
	unsigned long int addr = (uintptr_t)pointer;
	int digits = 0;
	unsigned long int temp = addr;

	if (f == '+')
		_putchar('+');
	if (f == ' ' && f != '+')
		_putchar(' ');
	if (!pointer)
		return (_puts("(nil)"));
	count += _putchar('0');
	count += _putchar('x');
	for (; temp != 0; temp >>= 4, digits++)
		;
	for (i = digits - 1; i >= 0; i--)
	{
		shift = i * 4;
		hexDigit = (addr >> shift) & 0xF;
		count += _putchar("0123456789abcdef"[hexDigit]);
	}
	return (count);
}

/**
 * print_reversed - prints the reversed string
 * @list: va_list arguments from _printf
 * @f: flag
 * Return: reversed string
 */
int print_reversed(va_list list, char f)
{
	int i = 0, x;
	char *str = va_arg(list, char *);

	if (f == '+')
		_putchar('+');
	if (f == ' ' && f != '+')
		_putchar(' ');
	if (!str)
		str = "(null)";

	while (str[i])
		i++;

	for (x = i - 1; x >= 0; x--)
		_putchar(str[x]);

	return (i);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * as little as possible
 */
int _putchar(char c)
{
	static char buf[1024];

	static int i;

	if (c == -1 || i >= 1024)
	{
		write(1, &buf, i);
		i = 0;
	}
	if (c != -1)
	{
		buf[i] = c;
		i++;
	}
	return (1);
}

/**
 * _puts - writes the character
 * @str: The character to print
 * Return: On success 1.
 * as little as possible
 */
int _puts(char *str)
{
	register int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}

/**
 * print_rot13 - prints octal
 * @list: va_list of arguments from _printf
 * @f: flag
 * Return: number of char printed
 */

int print_rot13(va_list list, char f)
{
	char sep[2][52] = {
		{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
		 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd',
		 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
		 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'},
		{'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B',
		 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
		 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b',
		 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'}};
	char *str = va_arg(list, char *);
	int i, sepLen = strlen(str), j;

	if (f == '+')
		_putchar('+');
	if (f == ' ' && f != '+')
		_putchar(' ');
	for (i = 0; i < sepLen && str[i] != '\0'; i++)
	{
		if ((str[i] > 'a' || str[i] < 'z') && (str[i] > 'A' || str[i] < 'Z'))
		{
			for (j = 0; j <= 52; j++)
			{
				if (str[i] == sep[0][j])
					_putchar(sep[1][j]);
			}
		}
		_putchar(str[i]);
	}
	return (i);
}
