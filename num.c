#include "main.h"

/**
 * convert - convert num
 * @n: num
 * @b: base
 * @flag: argument pointer
 * @para: paramater struc
 * Return: Always 0
 */
char *convert(long int n, int b, int flag, para_t *para)
{
	static char *ar;
	static char buff[50];
	char si = 0;
	char *pt;
	unsigned long nu = n;
	(void)para;

	if (!(flag & CONVERT_UNSIGNED) && n < 0)
	{
		nu = -n;
		si = '-';
	}
	ar = flag & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	pt = &buff[49];
	*pt = '\0';

	do {
		*--pt = ar[nu % b];
		nu /= b;
	} while (nu != 0);

	if (si)
		*--pt = si;
	return (pt);
}
/**
 *  print_unsigned -  print unsigned num
 * @a: num
 * @para: paramater struc
 * Return: Always 0
 */
int print_unsigned(va_list a, para_t *para)
{
	unsigned long lo;

	if (para->l_modi)
		lo = (unsigned long)va_arg(a, unsigned long);
	else if (para->h_modi)
		lo = (unsigned short int)va_arg(a, unsigned int);
	else
		lo = (unsigned int)va_arg(a, unsigned int);
	para->unsign = 1;
	return (print_number(convert(lo, 10, CONVERT_UNSIGNED, para), para));
}
/**
 *  print_ad -  print address
 * @a: argu pointer
 * @para: paramater struc
 * Return: Always 0
 */
int print_ad(va_list a, para_t *para)
{
	unsigned long int nu = va_arg(a, unsigned long int);
	char *st;

	if (!nu)
		return (_put("(nil)"));
	st = convert(nu, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, para);
	*--st = 'x';
	*--st = '0';
	return (print_number(st, para));
}
