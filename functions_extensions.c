#include"main.h"
/**
 * _putchar - writes and prints an output
 * @c: printed character
 * Return: 0 -> success, 1 -> Error
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}
/**
 * printint - integer to be printed
 * @ar: argument (va_list
 * @flg: flag (integer)
 * @pre: precision (integer)
 * @sz: size (integer)
 * @wdth: width (integer)
 * Return: 1 -> success, 0 -> Error
 */
int printint(va_list ar,
__attribute__((unused)) int flg,
__attribute__((unused)) int wdth,
__attribute__((unused)) int sz,
__attribute__((unused)) int pre)
{
char buff_n[20];
int a, n, pt_n = 0;
n = va_arg(ar, int);
if (n < 0)
{
_putchar('-');
pt_n++;
n = (n * -1);
}
if (n == 0)
{
return (_putchar('0'));
}
for (a = 0; n > 0; a++)
{
buff_n[a] = n % 10 + '0';
n = n / 10;
}
while (a > 0)
{
pt_n = pt_n + write(1, &buff_n[--a], 1);
}
return (pt_n);
}
