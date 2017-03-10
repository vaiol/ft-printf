#ifndef HANDLE_H
#define HANDLE_H

# include "../../ft_printf.h"

char	*handle_minwidth(t_format *form, char *str, size_t margin);
char	*handle_precision(t_format *form, char *str, int len, size_t margin);
char	*handle_apostrophe(char *nbr);

#endif
