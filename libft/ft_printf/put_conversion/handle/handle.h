#ifndef HANDLE_H
#define HANDLE_H

# include "../util/util.h"

char	*handle_minwidth(t_conversion *conv, char *str, size_t margin);
char	*handle_precision(t_conversion *conv, char *str, int len, size_t margin);
char	*handle_apostrophe(char *nbr);

#endif
