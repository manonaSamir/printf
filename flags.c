

#include "main.h"

/**
 * get_flag - choose what's flag sent.
 * @str: arguments.
 * Return: 1.
 */

char get_flag(char str)
{
	switch (str)
	{
	case '+':
		return '+';
	case ' ':
		return ' ';
	case 'o':
	case 'x':
		return '#';
	default:
		return '\0';
	}
}

/*
if (flag[0])
	i += _putchar('+');
if (flag[1] && !flag[0])
	i += _putchar(' ');
if (flag[2])
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
*/