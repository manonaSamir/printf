

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
