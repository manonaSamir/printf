#include "main.h"

/**
 * print_hex - prints hexadecimal
 * @list: va_list of arguments from _printf
 * Return: number of char printed
 */

int print_hex(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	int i = 0, len, remainder;
	char hex_str[20], temp;

	for (; num > 0; num /= 16, i++)
	{
		remainder = num % 16;
		if (remainder < 10)
			hex_str[i] = remainder + '0';
		else
			hex_str[i] = remainder - 10 + 'a';
	}

	hex_str[i] = '\0';
	len = i;
	for (i = 0; i < len / 2; i++)
	{
		temp = hex_str[i];
		hex_str[i] = hex_str[len - i - 1];
		hex_str[len - i - 1] = temp;
	}
	return (_puts(hex_str));
}

/**
 * print_Big_hex - prints uppercase hexadecimal
 * @list: va_list of arguments from _printf
 * Return: number of char printed
 */

int print_Big_hex(va_list list)
{
	unsigned int num = va_arg(list, unsigned int);
	int i = 0, len, remainder;
	char hex_str[20], temp;

	for (; num > 0; num /= 16, i++)
	{
		remainder = num % 16;
		if (remainder < 10)
			hex_str[i] = remainder + '0';
		else
			hex_str[i] = remainder - 10 + 'A';
	}

	hex_str[i] = '\0';
	len = i;
	for (i = 0; i < len / 2; i++)
	{
		temp = hex_str[i];
		hex_str[i] = hex_str[len - i - 1];
		hex_str[len - i - 1] = temp;
	}
	return (_puts(hex_str));
}

/**
 * print_binary - prints binary
 * @list: va_list of arguments from _printf
 * Return: number of char printed
 */

int print_binary(va_list list)
{
	int number = va_arg(list, int);
	int bits = sizeof(number) * 8, foundSetBit = 0, i, count = 0;
	if (number == 0)
	{
		_putchar('0');
		return (1);
	}
	for (i = bits - 1; i >= 0; i--)
	{
		if ((number >> i) & 1)
		{
			foundSetBit = 1;
			_putchar('1');
			count++;
		}
		else if (foundSetBit)
		{
			_putchar('0');
			count++;
		}
	}
	return (count);
}

/**
 * print_percent - prints a percent
 * @list: va_list arguments from _printf
 * Return: number of char printed
 */
int print_percent(va_list list)
{
	(void)list;
	return (_putchar('%'));
}

/**
 * print_octal - prints octal
 * @list: va_list of arguments from _printf
 * Return: number of char printed
 */

int print_octal(va_list list)
{
	unsigned int oct = va_arg(list, unsigned int);
	char str[20], temp;

	int i = 0, len;

	do
	{
		str[i++] = (oct % 8) + '0';
		oct /= 8;
	} while (oct > 0);

	str[i] = '\0';

	len = i;
	for (i = 0; i < len / 2; i++)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
	return (_puts(str));
}
