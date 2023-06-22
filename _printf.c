#include "main.h"
/**
 * _printf - prints everything
 * @format: string's format
 * Return: printed string
 */
int _printf(const char *format, ...)
{
va_list ar;
int flg = 0, sz = 0, pre = 0, wdth = 0, a = 0, buff_ind = 0, pr_c = 0, pr = 0;
char buf[OUTPUT_BUF_SIZE];
if (format == NULL)
return (-1);
va_start(ar, format);
while (format[a] != '\0')
{
if (format[a] != '%')
buf[buff_ind] = format[a];
buff_ind++;
if (buff_ind == OUTPUT_BUF_SIZE - 1 || buff_ind > 0
&& (printbuf(buf, buff_ind) <= 0)
return (-1);
buff_ind = 0;
pr_c++;
}
if (buff_ind > 0)
{
pr = printsp(format, a + 1, ar, wdth, sz, pre, flg);
if (pr <= 0)
return (-1);
pr_c += pr;
a++;
buff_ind = 0;
}
a++;
}
if (buff_ind > 0)
{
va_end(ar);
return (pr_c);
}
/**
 * printbuf - buffer's content to be printed
 * @buf: buffer
 * @l_ind: last index
 * Return: 1 -> success, -1 -> Error
 */
int printbuf(char buf[], int l_ind)
{
int a;
if (l_ind > 0)
{
for (a = 0; a < l_ind; a++)
{
write(1, &buf[a], 1);
}
return (1);
}
else
return (-1);
}
/**
 * printsp - specifier to be printed
 * @f: format (string)
 * @f_ind: last format index (integer)
 * @ar: argument (integer)
 * @flg: integer
 * @sz: integer
 * @pre: integer
 * @wdth: integer
 * @&printc: charchter to be printed
 * @&prints: string to be printed
 * @&printpercent: percent to be printed
 * Return: 1 -> Success, 0 -> Error
 */
int printsp(const char *f, int f_ind, va_list ar,
__attribute__((unused)) int flg,
__attribute__((unused)) int wdth,
__attribute__((unused)) int sz,
__attribute__((unused)) int pre)
{
char sp[] = {'c', 's', '%', 'd', 'i'};
int (*pr_f[]) (va_list, int, int, int, int) = {&printc, &prints,
&printpercent, &printint, &printint};
int a;
for (a = 0; sp[a] != '\0'; a++)
{
if (f[f_ind] == sp[a])
{
return (pr_f[a](ar, flg, wdth, sz, pre));
}
}
return (-1);
}
