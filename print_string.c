#include "main.h"

/**
 * print_string - Print string
 * @list: list.
 *
 * Return: String length.
 */

int print_string(va_list list)
{
	char *p;
	int pLen;

	p = va_arg(list, char*);
	pLen = print((p != NULL) ? p : "(null)");

	return (pLen);
}
