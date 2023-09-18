#include <stdio.h>
#include <stdarg.h>

int _myprintf(const char *ptr, ...)
{
	va_list args;

	va_start(args, ptr);

	int count = 0;

	while (*ptr)
	{
		if (*ptr != '%')
		{
			putchar(*ptr);
			count++;
		}
		else
		{
			ptr++;
			switch (*ptr)
			{
				case 'c':
					putchar (va_arg(args, int));
					count++;
					break;
				case 's':
					{
						const char *s = va_arg(args, const char *);

						while (*s)
						{
							putchar(*s);
							s++;
							count++;
						}
					}
					break;
				case '%':
					putchar ('%');
					count++;
					break;
				default:
					putchar('?');
					count++;
					break;
			}
		}
		ptr++;
	}

	va_end(args);
	return (count);
}

int main(void)
{
	const char *message = "I'm not going anywhere. You can print that wherever you want to. I'm here and I'm a Spur for life";
	int chars_printed = _myprintf("%c %s %%\n", message);
	printf("\n total characters pinted: %d\n", chars_printed);
	return (0);
}
