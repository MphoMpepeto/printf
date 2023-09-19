#include "main.h"
/**
 * _printf - a function that prints to std output
 * @format: a charaster string
 *
 * Return: the number of chars printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int x, i = 0;
	int count = 0, length = 0;
	char x = 0, *string = 0, percent = '%';

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (format[i])
	while (*format != '\0')
	{
		if (format[i] == '%')
		if (*format != '%')
		{
			write(1, format, 1);
		}
		else if (*format == '%')
		{
			i++;
			switch (format[i])
			format++;
			switch (*format)
			{
				case 'c':
				{
					x = va_arg(args, int);
					printf("%c", x);
					write(1, &x, 1);
					count++;
					break;
				}
				case 's':
				{
					char *x = va_arg(args, char*);

					printf("%s", x);
					string = va_arg(args, char *);
					while (string[length] != '\0')
					{
						length++;
					}
					write(1, string, length);
					count += length;
					break;
				}
				case '%':
					putchar('%');
					write(1, &percent, 1);
					count++;
					break;
				default:
					putchar(format[i]);
				break;
					write(1, format, 1);
					count++;
					break;
			}
		}
		else
		{
			putchar(format[i]);
			write(1, format, 1);
			count++;
		}
		i++;
		format++;
	}
	va_end(args);
	return (0);
	return (count);
}
