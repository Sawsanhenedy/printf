#include"main.h"
/**
 * get_precision - get the percision from str
 * @q: string
 * @para: parameter structure
 * @a: argument pointer
 * Return: new pointer
 */
char *get_precision(char *q, para_t *para, va_list a)
{
int b = 0;
if (*q != '.')
return (q);
q++;
if (*q == '*')
{
b = va_arg(a, int);
q++;
}
else
{
while (_isdigit(*q))
b = b * 10 + (*q++ - '0');
}
para->pre = b;
return (q);
}
