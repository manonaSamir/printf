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

	const char *spec;
	int (*pfunc)(va_list, char);
	va_list prints;
	char flag = '\0';
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
					flag = '+';
				else if (*spec == ' ')
					flag = ' ';
				else if (*spec == '#')
					flag = '#';
				spec++;
			}
			pfunc = print_specifier(*spec);
			if (pfunc)
			{
				i += pfunc(prints, flag);
			}
			else
				i += _printf("%%%c", *spec);
		}
		else
			i += _putchar(*spec);
	}
	_putchar(-1);
	va_end(prints);
	return (i);
}
