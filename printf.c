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
			pfunc = print_specifier(*spec);
			if (pfunc)
				i += pfunc(prints);
			else
				i += _printf("%%%c", *spec);
		}
		else if (*spec == '\\')
		{
			spec++;
			if (*spec == 'x')
			{
				char literal[] = "\\x";
				literal[2] = *++spec;
				i += print_literal(literal);
			}
			else
			{
				i += print_literal("\\");
				i += print_literal(spec);
			}
		}
		else
			i += _putchar(*spec);
	}
	_putchar(-1);
	va_end(prints);
	return (i);
}
