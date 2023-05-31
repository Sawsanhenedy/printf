#include "main.h"

/**
 * get_speci - find format functions
 * @x: format string
 * Return: Always 0
 */
int (*get_speci(char *x))(va_list a, para_t *para)
{
	specifier_t specifier[] = {
		{"c", print_c},
		{"d", print_int},
		{"i", print_int},
		{"s", print_str},
		{"b", print_bin},
		{"%", print_percent},
		{"o", print_oct},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_ad},
		{"S", print_S},
		{"R", print_rot},
		{"r", print_rev},
		{NULL, NULL}
	};
	int i = 0;

	while (specifier[i].specifier)
	{
		if (*x == specifier[i].specifier[0])
		{
			return (specifier[i].f);
		}
	i++;
	}
	return (NULL);
}
/**
 * get_print_func - find format functions
 * @x: format string
 * @a: argument pointer
 * @para: parameter struc
 * Return: Always 0
 */
int get_print_func(char *x, va_list a, para_t *para)
{
	int (*fi)(va_list, para_t *) = get_speci(x);

	if (fi)
		return (fi(a, para));
	return (0);
}

/**
 * get_flag - find format functions
 * @x: format string
 * @para: parameter struc
 * Return: Always 0
 */
int get_flag(char *x, para_t *para)
{
	int k = 0;

	switch (*x)
	{
		case '+':
			k = para->plus_flag = 1;
			break;
		case ' ':
			k = para->space_flag = 1;
			break;
		case '#':
			k = para->hash_flag = 1;
			break;
		case '-':
			k = para->minus_flag = 1;
			break;
		case '0':
			k = para->zero_flag = 1;
			break;
	}
	return (k);
}

/**
 * get_modi - find format functions
 * @x: format string
 * @para: parameter struc
 * Return: Always 0
 */
int get_modi(char *x, para_t *para)
{
	int i = 0;
switch (*x)
{
	case 'h':
		i = para->h_modi = 1;
		break;
	case 'l':
		i = para->l_modi = 1;
		break;
}
return (i);
}

/**
 * get_w - find format functions
 * @x: format string
 * @para: parameter struc
 * @a: argument pointer
 * Return: Always 0
 */
char get_w(char *x, para_t *para, va_list a)
{
	int o = 0;

	if (*x == '*')
	{
		o = va_arg(a, int);
	       x++;
	}
	else
	{
	while (_isdigit(*x))
	o = o * 10 + (*x++ - '0');
	}
para->w = o;
return (*x);
}
