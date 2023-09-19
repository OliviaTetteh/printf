#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - returns the number of char printed
 * excluding the null byte.
 * @format : lists types of arg passed to the function.
 * Return: the number of printed characters
 */

int _printf(const char *format, ...);
int _printf(const char *format, ...)
{
	int output_print = 0;
	va_list format_of_output;

	if (format == 0)
	return (-1);

	va_start(format_of_output, format);

	while (*format)
	{
		if (*format == 'd')
		{
			char d = va_arg(format_of_output, int);

			write(1, &d, 1);
			output_print++;
		}
		else if (*format == 'i')
		{
			char i = va_arg(format_of_output, int);

			write(1, &i, 1);
			output_print++;
		}
	}
	format++;

	va_end(format_of_output);

	return (output_print);
}
