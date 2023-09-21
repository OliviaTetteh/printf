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

	if (format == NULL)
		return (-1);

	va_start(format_of_output, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			output_print++;
		}
		else
		{
			format++;
			if (*format == '\0')
			break;

		if (*format == '%')
		{
			write(1, format, 1);
			output_print++;
		}
		else if (*format == 'c')
		{
			char c = va_arg(format_of_output, int);

			write(1, &c, 1);
			output_print++;
		}
		else if (*format == 's')
		{
			char *str = va_arg(format_of_output, char*);
			int str_len = 0;

			while (str[str_len] != '\0')
				str_len++;

			write(1, str, str_len);
			output_print += str_len;
		}
		else if (*format == 'd' || *format == 'i')
		{
			int num = va_arg(format_of_output, int);

			printf("%d", num);
			output_print++;
		}
		}
	format++;
	}

	va_end(format_of_output);

	return (output_print);
}
