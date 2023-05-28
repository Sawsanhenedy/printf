#include "main.h"

/**
 * get_speci - find format functions
 * @x: format string
 * Return: Always 0
 */
int (*get_speci(char *x))(va_list a, para_t *para)
{
	specifier_t speci[] = {
		{"c", print_c},
		{"d", print_int},
		{"i", print_int},
		{"s", print_str},
		{"b", print_bin},
		{"%", print_percent},
		{"o", print_oct},
		{"u", print_print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_addrs},
		{"S", print_S},
		{"R", print_rt13},
		{"r", print_rev},
		{NULL, NULL}
	};
	int i = 0;

	while (speci[i].specifier)
	{
		if (*x == speci[i].specifier[0])
		{
			return (speci[i].fi);
		}
	i++;
	}
	return (NULL);
}

