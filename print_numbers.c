#include "main.h"

/**
 * print_number - prints numbers
 * @list: va_list of arguments from _printf
 * Return: number of char printed
 */

int print_number(va_list list, char f)
{
	int num = 0, count;

	num = va_arg(list, int);

	count = counter_number(num);
	if (num <= 0)
		count++;
	if (num >= 0)
	{
		if (f == '+')
			_putchar('+');
		if (f == ' ' && f != '+')
			_putchar(' ');
		count++;
	}
	loopNumber(num);
	return (count);
}

/**
 * print_un_number - prints positive numbers
 * @list: va_list of arguments from _printf
 * @f: flag
 * Return: number of char printed
 */

int print_un_number(va_list list, char f)
{
	unsigned int num = va_arg(list, unsigned int);
	char str[20], temp;
	int i = 0, len;

	if (f == '+')
		_putchar('+');
	if (f == ' ' && f != '+')
		_putchar(' ');

	do {
		str[i++] = num % 10 + '0';
		num /= 10;
	} while (num > 0);

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

/**
 * print_fnumber - prints positive numbers
 * @list: va_list of arguments from _printf
 * @f: flag
 * Return: number of char printed
 */

int print_fnumber(va_list list, char f)
{
	unsigned int num = va_arg(list, double);
	static char *rep;
	static char buffer[50];
	char *ptr;

	if (f == '+')
		_putchar('+');
	if (f == ' ' && f != '+')
		_putchar(' ');
	rep = "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';
	for (; num != 0; *--ptr = rep[num % 10])
		num /= 10;
	return (_puts(ptr));
}

/**
 * counter_number - returns the number of digits in an integer
 * for _printf
 * @num: integer to evaluate
 * Return: number of digits
 */
int counter_number(int num)
{
	unsigned int d = 0;
	unsigned int u;

	if (num < 0)
		u = num * -1;
	else
		u = num;
	while (u != 0)
	{
		u /= 10;
		d++;
	}
	return (d);
}

/**
 * loopNumber - returns the number of digits in an integer
 * for _printf
 * @num: integer to print
 * Return: number of digits
 */
void loopNumber(int num)
{
	unsigned int pn;

	if (num < 0)
	{
		_putchar('-');
		pn = -num;
	}
	else
		pn = num;

	if (pn / 10)
		loopNumber(pn / 10);
	_putchar((pn % 10) + '0');
}
