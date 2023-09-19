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
	int performance_print = 0;
	va_list level_of_performance;

	if (format == 0)
		return (-1);

	va_start(level_of_performance, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			performance_print++;
		}
		else
		{
			format++;
			if (*format == '\0')
			break;

		if (*format == '%')
		{
			write(1, format, 1);
			performance_print++;
		}
		else if (*format == 'c')
		{
			char c = va_arg(level_of_performance, int);

			write(1, &c, 1);
			performance_print++;
		}
		else if (*format == 's')
		{
			char *str = va_arg(level_of_performance, char*);
			int str_len = 0;

			while (str[str_len] != '\0')
				str_len++;

			write(1, str, str_len);
			performance_print += str_len;
			}
		}
	format++;
}
	va_end(level_of_performance);

	return (performance_print);
}
