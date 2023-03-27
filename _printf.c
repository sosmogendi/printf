#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - prints output according to a format
 * @format: is a character string
 * @...: variable args
 * Return: Number of characters printed
 */


int _printf(const char *format, ...)
{
	int i = 0, count = 0, chars;
	va_list args;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	while (format[i])
	{
		chars = 0;
		if (format[i] == '%')
		{
			if (!format[i + 1] || (format[i + 1] == ' ' && !format[i + 2]))
			{
				count = -1;
				break;
			}
			chars += get_function(format[i + 1], args);
			if (chars == 0)
				count += _putchar(format[i + 1]);
			if (chars == -1)
				count = -1;
			i++;
		}
		else
		{
			(count == -1) ? (_putchar(format[i])) : (count += _putchar(format[i]));
		}
		i++;
		if (count != -1)
			count += chars;
	}
	va_end(args);
	return (count);
}
