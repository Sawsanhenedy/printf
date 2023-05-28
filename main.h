#ifndef MAIN_H
#define MAIN_H
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdarg.h>
#include<limits.h>
#define PARA_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0} /* zero for each parameter */
#define NULL_STRING "(null)"
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
} para_t
/**
 * struct speci - token structure
 * @f: function
 * @speci: token format
 */
typedef struct specifier
{
char *speci;
int (*f)(va_list, para_t *);
} specifier_t
/* task 0: _printf.c */
int _printf(const char *format, ...);
<<<<<<< HEAD
/* functions */
/*salma */
=======
#endif /* MAIN_H */
>>>>>>>
