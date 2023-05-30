#include"main.h"
/**
 * print_c - prints character
 * @a: argument pointer
 * @para: parameter structure
 * Return: character
 */
int print_c(va_list a, para_t *para)
{
char p_c = ' ';
unsigned int p = 1, add = 0, d = va_arg(a, int);
if (para->minus_flag)
add += _putchar(d);
while (p++ < para->w)
add += _putchar(p_c);
if (!para->minus_flag)
add += _putchar(d);
return (add);
}
/**
 * print_int - prints int
 * @a: argument pointer
 * @para: parameter structure
 * Return: int
 */
int print_int(va_list a, para_t *para)
{
long l;
if (para->l_modi)
l = va_arg(a, long);
else if (para->h_modi)
l = (short int)va_arg(a, int);
else
l = (int)va_arg(a, int);
return (print_number(convert(l, 10, 0, para), para));
}
/**
 * print_str - prints string
 * @a: argument pointer
 * @para: parameter structure
 * Return: string
 */
int print_str(va_list a, para_t *para)
{
char *s = va_arg(a, char *), p_c = ' ';
unsigned int p = 0, add = 0, f = 0, r;
(void)para;
switch ((int)(!s))
case 1:
s = NULL_STRING;
r = p = _strlen(s);
if (para->pre < p)
r = p = para->pre;
if (para->minus_flag)
{
if (para->pre != UINT_MAX)
for (f = 0; f < p; f++)
add += _putchar(*s++);
else
add += _put(s);
}
while (r++ < para->w)
add += _putchar(p_c);
if (!para->minus_flag)
{
if (para->pre != UINT_MAX)
for (f = 0; f < p; f++)
add += _putchar(*s++);
else
add += _put(s);
}
return (add);
}
/**
 * print_percent - prints percent
 * @a: argument pointer
 * @para: parameter structure
 * Return: percent
 */
int print_percent(va_list a, para_t *para)
{
(void)a;
(void)para;
return (_putchar('%'));
}
/**
 * print_S - specifier customizer
 * @a: argument pointer
 * @para: parameter structure
 * Return: specifier
 */
int print_S(va_list a, para_t *para)
{
char *s = va_arg(a, char *);
char *hx;
int add = 0;
if ((int)(!s))
return (_put(NULL_STRING));
for (; *s; s++)
{
if ((*s > 0 && *s < 32) || *s >= 127)
{
add += _putchar('\\');
add += _putchar('x');
hx = convert(*s, 16, 0, para);
if (!hx[1])
add += _putchar('0');
add += _put(hx);
}
else
{
add += _putchar(*s);
}
}
return (add);
}
