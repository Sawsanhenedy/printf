#include "main.h"
#include <stdarg.h>

/**
 * print_hex - find format functions
 * @a: num
 * @para: struc
 * Return: Always 0
 */
int print_hex(va_list a, para_t *para)
{
	unsigned long lo;
	int w = 0;
	char *st;

	if (para->l_modi)
		lo = (unsigned long)va_arg(a, unsigned long);
	else if (para->h_modi)
		lo = (unsigned short int)va_arg(a, unsigned int);
	else
		lo = (unsigned int)va_arg(a, unsigned int);
	st = convert(lo, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, para);
	if (para->hash_flag && lo)
	{
		*--st = 'x';
		*--st = '0';
	}
	para->unsign = 1;
	return (w += print_number(st, para));
}
/**
 * print_HEX - find format functions
 * @a: num
 * @para: struc
 * Return: Always 0
 */
int print_HEX(va_list a, para_t *para)
{
	unsigned long lo;
	int w = 0;
	char *st;

	if (para->l_modi)
		lo = (unsigned long)va_arg(a, unsigned long);
	else if (para->h_modi)
		lo = (unsigned short int)va_arg(a, unsigned int);
	else
		lo = (unsigned int)va_arg(a, unsigned int);
	st = convert(lo, 16, CONVERT_UNSIGNED, para);
	if (para->hash_flag && lo)
	{
		*--st = 'x';
		*--st = '0';
	}
	para->unsign = 1;
	return (w += print_number(st, para));
}
/**
 * print_bin - find format functions
 * @a: num
 * @para: struc
 * Return: Always 0
 */
int print_bin(va_list a, para_t *para)
{
	unsigned int o = va_arg(a, unsigned int);
	char *st = convert(o, 2, CONVERT_UNSIGNED, para);
	int w = 0;

	if (para->hash_flag && w)
		*--st = '0';
	para->unsign = 1;
	return (w += print_number(st, para));
}
/**
 * print_oct - find format functions
 * @a: num
 * @para: struc
 * Return: Always 0
 */
int print_oct(va_list a, para_t *para)
{
	unsigned long lo;
	int w = 0;
	char *st;

	if (para->l_modi)
		lo = (unsigned long)va_arg(a, unsigned long);
	else if (para->h_modi)
		lo = (unsigned short int)va_arg(a, unsigned int);
	st = convert(lo, 8, CONVERT_UNSIGNED, para);
	if (para->hash_flag && lo)
		*--st = '0';
	para->unsign = 1;
	return (w += print_number(st, para));
}
