#ifndef MAIN_H
#define MAIN_H
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdarg.h>
#include<limits.h>
#define PARA_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0} /* zero for each parameter */
#define NULL_STRING "(null)"
#define BUF_FLUSH -1
#define OUTPUT_BUF_SIZE 1024
#define CONVERT_UNSIGNED
#define CONVERT_LOWERCASE
/**
 * struct para - structure of parameters
 * @plus_flag: in case a plus_flag is specified
 * @minus_flag: in case a minus_flag is specified
 * @hash_flag: in case a hashtag_flag is specified
 * @unsign: for unsigned value
 * @zero_flag: in case a zero_flag is specified
 * @space_flag: in case a space_flag is specified
 * @h_modi: if short modifier is specified
 * @l_modi: if long modifier is specified
 * @w: specified width
 * @pre: specified precision
 * Description: everything is mentioned above
 * Return: everything is mentioned above
 */
typedef struct para
{
unsigned int plus_flag : 1;
unsigned int minus_flag : 1;
unsigned int hash_flag : 1;
unsigned int unsign : 1;
unsigned int zero_flag : 1;
unsigned int space_flag : 1;
unsigned int h_modi : 1;
unsigned int l_modi : 1;
unsigned int w : 1;
unsigned int pre : 1;
} para_t;
/**
 * struct specifier - structure specifier
 * @f: function
 * @speci: token format
 * Description: speci = specifier and f = function
 * Return: everything is mentioned above
 */
typedef struct specifier
{
char *speci;
int (*f)(va_list, para_t *);
} specifier_t;
/*  _printf.c */
int _printf(const char *format, ...);
/* para.c */
void init_para(para_t *para, va_list a);
/* str_field.c */
char *get_precision(char *q, para_t *para, va_list a);
/* functions.c */
int print_int(va_list a, para_t *para);
int print_c(va_list a, para_t *para);
int print_str(va_list a, para_t *para);
int print_percent(va_list a, para_t *para);
int print_S(va_list a, para_t *para);
/* number_converter.c */
int print_oct(va_list a, para_t *para);
int print_bin(va_list a, para_t *para);
int print_hex(va_list a, para_t *para);
int print_HEX(va_list a, para_t *para);
/* numbers.c */
int print_unsigned(va_list a, para_t *para);
int print_ad(va_list a, para_t *para);
char *convert(long int n, int b, int flag, para_t *para);
/* printers.c */
int print_rev(va_list a, para_t *para);
int print_rot(va_list a, para_t *para);
int print_convert(char *from, char *to, char *ex);
/* specifiers.c */
int (*get_speci(char *x))(va_list a, para_t *para);
int get_modi(char *x, para_t *para);
int get_flag(char *x, para_t *para);
int get_print_func(char *x, va_list a, para_t *para);
char get_w(char *x, para_t *para, va_list a);
/* print_numbers.c */
int _isdigit(int f);
int _strlen(char *d);
int print_number(char *str, para_t *para);
int number_r(char *str, para_t *para);
int numver_l(char *str, para_t *para);
/* _put.c */
int _put(char *str);
int _putchar(int c);
#endif /* MAIN_H */
