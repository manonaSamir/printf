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
 * print_binary - prints octal
 * @list: va_list of arguments from _printf
 * Return: number of char printed
 */

int print_binary(va_list list)
{
	int number = va_arg(list, unsigned int);
	static char *rep;
	static char buffer[50];
	char *ptr;

	rep = "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	for (; number != 0; *--ptr = rep[number % 2])
		number /= 2;
	return (_puts(ptr));
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

	do {
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
