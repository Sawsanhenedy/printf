#include "main.h"

/**
 * _put - find format functions
 * @str: string
 * Return: Always 0
 */
int _put(char *str)
{
	char *aa = str;

	while (*str)
		_putchar(*str++);
	return (str - aa);
}
/**
 * _putchar - write char
 * @c: char
 * Return: Always 0
 */
int _putchar(int c)
{
	static int u;
	static char buff[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || u >= OUTPUT_BUF_SIZE)
	{
		write(1, buff, u);
		u = 0;
	}
	if (c != BUF_FLUSH)
		buff[u++] = c;
	return (1);
}

