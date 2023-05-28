#include"main.h"
/**
 * print_convert - prints character addresses
 * @from: starting from
 * @to: end address
 * @ex: except
 * Return: printed number bytes
 */
int print_convert(char *from, char *to, char *ex)
{
int add = 0;
while (from <= to)
{
if (from != ex)
add += _putchar(*from);
from++;
}
return (add);
}
/**
 * print_rev - print the revers of string
 * @a: string
 * @para: parameter's structure
 * Return: printed number of bytes
 */
int print_rev(va_list a, para_t *para)
{
int l, add = 0;
char *s = va_arg(a, char *);
(void)para;
if (s)
{
for (l = 0; *s; s++)
l++;
s--;
for (; l > 0; l--, s--)
add += _putchar(*s);
}
return (add);
}
/**
 * print_rot - prints string in rot13
 * @a: string
 * @para: parameter's structure
 * Return: printed number of bytes
 */
int print_rot(va_list a, para_t *para)
{
int f, x;
int c = 0;
char ar[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
char *b = va_arg(a, char *);
(void)para;
f = 0;
x = 0;
while (b[f])
{
if ((b[f] >= 'A' && b[f] <= 'Z') || (b[f] >= 'a' && b[f] <= 'z'))
{
x = b[f] - 65;
c += _putchar(ar[x]);
}
else
c += _putchar(b[f]);
f++;
}
return (c);
}
