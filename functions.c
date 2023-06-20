#include"main.h"
/**
 * printc - character to be printed
 * @flg: flag (integer)
 * @ar: (va_list) argument
 * @sz: (integer) size
 * @wdth: (integer) width
 * @pre: (integer) precision
 * Return: 1 -> Success, 0 -> Error
 */
int printc(va_list ar,
__attribute__((unused)) int flg,
__attribute__((unused)) int wdth,
__attribute__((unused)) int sz,
__attribute__((unused)) int pre)
{
char a;
a = (char) va_arg(ar, int);
write(1, &a, 1);
return (1);
}
/**
 * printpercent - percent (&) to be printed
 * @flg: flag (integer)
 * @ar: (va_list) argument
 * @sz: (integer) size
 * @wdth: (integer) width
 * @pre: (integer) precision
 * Return: 1 -> success, 0 -> Error
 */
int printpercent(__attribute__((unused)) va_list ar,
__attribute__((unused)) int flg,
__attribute__((unused)) int wdth,
__attribute__((unused)) int sz,
__attribute__((unused)) int pre)
{
int pt;
char a = '%';
pt = write(1, &a, 1);
return (pt);
}
/**
 * prints - string to be printed
 * @flg: flag (integer)
 * @ar: (va_list) argument
 * @sz: (integer) size
 * @wdth: (integer) width
 * @pre: (integer) precision
 * Return: 1 -> success, 0 -> Error
 */
int prints(va_list ar,
__attribute__((unused)) int flg,
__attribute__((unused)) int wdth,
__attribute__((unused)) int sz,
__attribute__((unused)) int pre)
{
char *s;
int pt_c = 0, a = 0, pt = 0;
s = va_arg(ar, char *);
if (s == NULL)
return (-1);
while (s[a] != '\0')
{
pt = write(1, &a, 1);
if (pt < 0)
return (-1);
pt_c++;
a++;
}
return (pt_c);
}
