#include "main.h"
/**
 * _printf - prints everything
 * @format: string's format
 * Return: printed string
 */
int _printf(const char *format, ...)
{
int add = 0;
va_list a;
char *p, *first;
para_t para = PARA_INIT;
va_start(a, format);
if (!format || (format[0] == '%' && !format[1]))
return (-1);
if (format[0] == '%' && format[1] == ' ' && !format[2])
return (-1);
for (p = (char *)format; *p; p++)
{
init_para(&para, a);
if (*p != '%')
{
add += _putchar(*p);
continue;
}
first = p;
p++;
while (get_flag(p, &para))
{
p++;
}
p = get_w(p, &para, a);
p = get_precision(p, &para, a);
if (get_modi(p, &para))
p++;
if (get_speci(p))
add += print_convert(first, p,
para.l_modi || para.h_modi ? p - 1 : 0);
else
add += get_print_func(p, a, &para);
}
_putchar(BUF_FLUSH);
va_end(a);
return (add);
}
