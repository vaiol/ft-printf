#ifndef PUT_FORMAT_H
# define PUT_FORMAT_H

# include "handle/handle.h"

void	put_char(t_conversion *conv, va_list valist);
void	put_string(t_conversion *conv, va_list valist);
void	put_unsigned(t_conversion *conv, unsigned long long number);
void	put_signed(t_conversion *conv, long long number);
void	put_memory(t_conversion *conv, va_list valist);

#endif
