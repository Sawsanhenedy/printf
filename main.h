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
#define CONVERT_UNSIGNED  1
#define CONVERT_LOWERCASE 2
/* Functions to be printed */
/**
 * prints - string to be printed
 * @flg: flag (integer)
 * @ar: argument (va_list)
 * @sz: size (integer)
 * @wdth: width (integer)
 * @pre: precision (integer)
 * Return: 1 -> Success, 0 -> Error
 */
int prints(va_list ar,
__attribute__((unused)) int flg,
__attribute__((unused)) int wdth,
__attribute__((unused)) int sz,
__attribute__((unused)) int pre);
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
__attribute__((unused)) int pre);
/**
 * printint - integer to be printed
 * @flg: integer
 * @ar: va_list
 * @sz: integer
 * @wdth: integer
 * @pre: integer
 * Return: 1 -> Success, 0 -> Error
 */
int printint(va_list ar,
__attribute__((unused)) int flg,
__attribute__((unused)) int wdth,
__attribute__((unused)) int sz,
__attribute__((unused)) int pre);
/**
 * printbin - binary to be printed
 * @flg: integer
 * @ar: va_list
 * @sz: integer
 * @wdth: integer
 * @pre: integer
 * Return: 1 -> Success, 0 -> Error
 */
int printbin(va_list ar,
__attribute__((unused)) int flg,
__attribute__((unused)) int wdth,
__attribute__((unused)) int sz,
__attribute__((unused)) int pre);
long int asgn(long int lnum, int sz);
/* Specifier */
int printsp(const char *f, int f_ind, va_list ar,
__attribute__((unused)) int flg,
__attribute__((unused)) int wdth,
__attribute__((unused)) int sz,
__attribute__((unused)) int pre);
/*  _printf.c */
int _printf(const char *format, ...);
/* _putchar */
int _putchar(int c);
/* Buffer */
int printbuf(char buf[], int l_ind);
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
unsigned int w;
unsigned int pre;
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
char *specifier;
int (*f)(va_list, para_t *);
} specifier_t;
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
#endif /* MAIN_H */
