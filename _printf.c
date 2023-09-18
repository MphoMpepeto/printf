#include "main.h"

/**
 * _printf - a function that prints to std output
 * @format: a charaster string
 *
 * Return: the number of chars printed
 */

int _printf(const char *format, ...)
{
	int count = 0, string_len = 0;
	char x, *string;
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
			if (*format == 'c')
			{
				x = va_arg(arg_list, int);
				write(1, &x, 1);
				count++;
			}
			if (*format == 's')
			{
				string = va_arg(arg_list, char*);
				while (string[string_len] != '\0')
				{
					string_len++;
				}
				write(1, string, string_len);
				count = count + string_len;
			}
			if (*format == '%')
			{
				write(1, format, 1);
				count++;
			}

		}
		format++;
	}
	va_end(arg_list);
	return (count);
}
