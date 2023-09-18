#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	va_list args;
	int x, i = 0;

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
				{
					x = va_arg(args, int);
					printf("%c", x);
					break;
				}
				case 's':
				{
					char *x = va_arg(args, char*);

					printf("%s", x);
					break;
				}
				case '%':
					putchar('%');
					break;
				default:
					putchar(format[i]);
				break;
			}
		}
		else
		{
			putchar(format[i]);
		}
		i++;
	}
	va_end(args);
	return (0);
}
