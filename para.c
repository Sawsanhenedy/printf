#include"main.h"
/**
 * init_para - reset buffer and clear fields of structure
 * @para: parameters
 * @a: pointer of argument
 */
void init_para(para_t *para, va_list a)
{
para->unsign = 0;
para->plus_flag = 0;
para->minus_flag = 0;
para->hash_flag = 0;
para->zero_flag = 0;
para->space_flag = 0;
para->h_modi = 0;
para->l_modi = 0;
para->w = 0;
para->pre = UINT_MAX;
(void)a;
}
