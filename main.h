#ifndef MAIN_H
#define MAIN_H
#include<stdio.h>
#include<unistd.h>
#include<stdarg.h>
#define BUF_SZ 1024
/* Functions */
int prints(va_list ar,
__attribute__((unused)) int flg,
__attribute__((unused)) int wdth,
__attribute__((unused)) int sz,
__attribute__((unused)) int pre);
int printc(va_list ar,
__attribute__((unused)) int flg,
__attribute__((unused)) int wdth,
__attribute__((unused)) int sz,
__attribute__((unused)) int pre);
int printpercent(va_list ar,
__attribute__((unused)) int flg,
__attribute__((unused)) int wdth,
__attribute__((unused)) int sz,
__attribute__((unused)) int pre);
int printint(va_list ar,
__attribute__((unused)) int flg,
__attribute__((unused)) int wdth,
__attribute__((unused)) int sz,
__attribute__((unused)) int pre);
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
/* Buffer */
int printbuf(char buf[], int l_ind);
#endif /* MAIN_H */
