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
int count;
va_list args;

va_start(args, format);

count = 0;
while (*format != '\0')
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
putchar(va_arg(args, int));
count++;
break;
case 's':
count += puts(va_arg(args, char *));
break;
case '%':
putchar('%');
count++;
break;
case 'd':
case 'i':
printf("%d", va_arg(args, int));
count++;
break;
default:
break;
}
}
else
{
putchar(*format);
count++;
}
format++;
}
va_end(args);
return (count);
}
