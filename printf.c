#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: a character string
 * @...: a variable number of arguments
 * Return: number of characters printed
 */


int _printf(const char *format, ...)
{	va_list args;
	int printed_chars = 0;
	int c;
	char *s;

	va_start(args, format);

	while (*format != '\0')
	{
	if (*format == '%')
	{
	format++;
	if (*format == 'c')
	{
	c = va_arg(args, int);
	putchar(c);
	printed_chars++;
	}
	else if (*format == 's')
	{
	s  = va_arg(args, char *);
	while (*s != '\0')
	{
	putchar(*s);
	s++;
	printed_chars++;
	}
	}
	else if (*format == '%')
	{
	putchar('%');
	printed_chars++;
	}
	}
	else
	{
	putchar(*format);
	printed_chars++;
	}
	format++;
	}
	va_end(args);
	return printed_chars;
}
