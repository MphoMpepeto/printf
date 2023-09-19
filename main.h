#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define BUFF_SIZE 1024
int _printf(const char *format, ...);

#endif
