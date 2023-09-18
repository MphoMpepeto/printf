#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, length = 0;
	char x = 0, *string = 0, percent = '%';

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			write(1, format, 1);
		}
		else if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
				{
					x = va_arg(args, int);
					write(1, &x, 1);
					count++;
					break;
				}
				case 's':
				{
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
					write(1, &percent, 1);
					count++;
					break;
				default:
					write(1, format, 1);
					count++;
					break;
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);

