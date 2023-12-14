#include "shell.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	int count;
	va_list args;
	va_start(args, format);

	if (format == NULL)
		return (-1);

	count = 0;  /* Count of characters printed */

	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++;  /* Move to the character after '%' */
			switch (*format)
			{
				case 'c':
					count += _putchar(va_arg(args, int));
					break;
				case 's':
					count += _print_str(va_arg(args, char *));
					break;
				case 'd':
				case 'i':
					count += _print_int(va_arg(args, int));
					break;
				case 'u':
					count += _print_uint(va_arg(args, unsigned int));
					break;
				case 'o':
					count += _print_oct(va_arg(args, unsigned int));
					break;
				case 'p':
					count += _print_ptr(va_arg(args, void *));
					break;
				case 'x':
					count += _print_hex(va_arg(args, unsigned int), 0);
					break;
				case 'X':
					count += _print_hex(va_arg(args, unsigned int), 1);
					break;
				case 'r':
					count += _print_rev_str(va_arg(args, char *));
					break;
				case '%':
					count += _putchar('%');
					break;
				default:
					_putchar('%');
					_putchar(*format);
					count += 2;
					break;
			}
			format++;
		}
		else
		{
			count += _putchar(*format);
			format++;
		}
	}

	va_end(args);
	return (count);
}
