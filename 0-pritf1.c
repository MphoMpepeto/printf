#include <stdio.h>
#include <stdarg.h>

int _myprintf(const char *ptr, ...);
{
	va_list args;
	va_start(args, *ptr);

	int i = 0;

	while (*ptr);
	if (*ptr != '%')
	{
		putchar(*ptr);
		ptr++;
	}
	
	else
	{
		ptr++;
		switch (ptr)
		{
			case 'c': i = (va_arg(args, int));
				  putchar (i);
				  break;
			case 's': const char *s = va_arg(args, const char *);
				  while (*s)
				  {
					  putchar (*s);
					  s++;
					  i++;
				  }
		}
		break;
		case '%': 
		putchar ('%');
		i++;
		break;
		default:
		putchar ('?');
		i++;
		break;
	}
}
va_end(args);
return i;
}
int main ()
{
	const char *message = "I'm not going anywhere. You can print that wherever you want to. I'm here and I'm a Spur for life";
	int chars_printed = _myprintf("%c %s %%\n", message);
	printf("\n total chars printed: %d\n", chars_printed);
	return 0;
}

