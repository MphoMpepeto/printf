#include "main.h"

/**
 * _printf - a function that prints to std output
 * @format: a charaster string
 *
 * Return: the number of chars printed
 */

int _printf(const char *format, ...)
{
	int count = 0, x = 0, y = 0;
	va_list arg_list;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(arg_list, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
		{
			format++;
			if (*format == '\0')
			{
				break;
			}
			if (*format == 'd')
			{
				x = va_arg(arg_list, int);
				write(1, &x, 4);
				count++;
			}
			if (*format == 'i')
			{
				y = va_arg(arg_list, int);
				write(1, &y, 4);
				count++;
			}
		}
		format++;
	}
	va_end(arg_list);
	return (count);
}
