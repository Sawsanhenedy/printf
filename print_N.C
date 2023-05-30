/**
 * _isdigit - check
 * @f: char
 * Return: Always 0
 */
int _isdigit(int f)
{
	return (f >= '0' &&f <= '9');
}
/**
 * _strlen - return
 * @d: char
 * Return: Always 0
 */
int _strlen(char *d)
{
	int o = 0;
	while (*d++)
		o++;
	return (o);
}
/**
 * print_number - return
 * @str: number
 * @para: parameter struc
 * Return: Always 0
 */
int print_number(char *str, para_t *para)
{
	unsigned int o = _strlen(str);
	int ngv = (!para->unsign && *str == '-');

	if (!para->pre && *str == '0' && !str[1])
		str = "";
	if (ngv)
	{
		str++;
		j--;
	}
	if (para->pre != UINT_MAX)
		while (j++ < para->pre)
			*--str = '0';
	if (ngv)
		*--str = '-';
	if (!para-> minus_flag)
		return (number_r(str, para));
	else
		return (numver_l(str, para));
}
/**
 * number_r - return
 * @str: number
 * @para: parameter struc
 * Return: Always 0
 */
int number_r(char *str, para_t *para)
{
	unsigned int o = 0, ngv1, ngv2, j = _strlen(str);
	char pd_ch = ' ';

	if (para->zero_flag && !para->minus_flag)
		pd_ch = '0';
	ngv1 = ngv2 = (!para->unsign && *str == '-');
	if (ngv1 && j < para->w && pd_ch == '0' && !para->minus_flag)
		str++;
	else
		ngv1 = 0;
	if ((para->plus_flag && !ngv2) || (!para->plus_flag && para->space_flag && !ngv2))
		j++;
	if (ngv1 && pd_ch == '0')
		o += _putchar('-');
	if (para->plus_flag && ngv2 && pd_ch == '0' && !para->unsign)
		o += _putchar('+');
	else if (!para->plus_flag && para->space_flag && !ngv2 && !para->unsign && para->zero_flag)
		 o += _putchar('_');
	while (j++ < para->w)
		o += _putchar(pd_ch);
	if (ngv1 && pd_ch == ' ')
		o += _putchar('-');
	if (para->plus_flag && !ngv2 && pd_ch == ' ' && !para->unsign)
		o += _putchar('+');
	else if (!para->plus_flag && para->space_flag && !ngv2 && !para->unsign && para->zero_flag)
		o += _putchar(' ');
	o += _put(str);
	return (o);
}
/**
 * numver_l - return
 * @str: number
 * @para: parameter struc
 * Return: Always 0
 */
int numver_l(char *str, para_t *para)
{
	unsigned int o = 0, ngv1, ngv2, j = _strlen(str);
        char pd_ch = ' ';

	if (para->zero_flag && !para->minus_flag)
                pd_ch = '0';
	ngv1 = ngv2 = (!para->unsign && *str == '-');
        if (ngv1 && j < para->w && pd_ch == '0' && !para->minus_flag)
                str++;
	else
                ngv1 = 0;
	if (para->plus_flag && !ngv2 && !para->unsign)
		o += _putchar('+'), j++;
	else if (para->space_flag && !ngv2 !para->unsign)
		o += _putchar(' '), j++;
	o += _put(str);
	while (j++ < para->w)
		n += _putchar(pd_ch);
	return (o);
}
