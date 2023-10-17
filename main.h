#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>
#include <ctype.h>

int _putchar(char c);
int _puts(char *str);
int _printf(const char *format, ...);
int (*print_specifier(char s))(va_list);
int print_percent(va_list list);
int print_address(va_list list);
int print_rot13(va_list list);
int print_binary(va_list list);
int print_octal(va_list list);
int print_hex(va_list list);
int print_Big_hex(va_list list);
int print_character(va_list list);
int print_string(va_list list);
int print_fnumber(va_list list);
int print_un_number(va_list list);
int print_number(va_list list);
int counter_number(int num);
void loopNumber(int num);

#endif
