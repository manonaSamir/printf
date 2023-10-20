#include "main.h"

/**
 * _printf -  prints the string pointed out by the format
 * to the standard output stdout
 * @format: the string of characters to write to buffer
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */

int _printf(const char *format, ...)
{
	register int i = 0;
	int plus_flag = 0;
	int space_flag = 0;
	int hash_flag = 0;

	const char *spec;
	int (*pfunc)(va_list);
	va_list prints;

	va_start(prints, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (spec = format; *spec; spec++)
	{
		if (*spec == '%')
		{
			spec++;
			if (*spec == '%')
			{
				i += _putchar('%');
				continue;
			}
			while (*spec == '+' || *spec == ' ' || *spec == '#')
			{
				if (*spec == '+')
					plus_flag = 1;
				else if (*spec == ' ')
					space_flag = 1;
				else if (*spec == '#')
					hash_flag = 1;
				spec++;
			}
			pfunc = print_specifier(*spec);
			if (pfunc)
			{
				if (plus_flag)
					i += _putchar('+');
				if (space_flag && !plus_flag)
					i += _putchar(' ');
				if (hash_flag)
				{
					if (*spec == 'o')
					{
						i += _putchar('0');
					}
					else if (*spec == 'x')
					{
						i += _putchar('0');
						i += _putchar(*spec);
					}
				}
				i += pfunc(prints);
			}
			else
			{
				i += _printf("%%%c", *spec);
			}
		}
		else
			i += _putchar(*spec);
	}
	_putchar(-1);
	va_end(prints);
	return (i);
}
