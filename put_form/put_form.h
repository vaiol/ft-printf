#ifndef PUT_FORM_H
# define PUT_FORM_H

#include "../ft_printf.h"

void			put_char(t_format *form, va_list valist);
void			put_string(t_format *form, va_list valist);
void			put_decimal(t_format *form, va_list valist);
void			put_unsigned(t_format *form, unsigned long long number);
void			put_signed(t_format *form, long long number);
char			*get_apostrophe(char *nbr);
char			*ft_getwstr(wchar_t *s, int max_len);
char			*ft_getwint(wint_t wint);
char 			*ft_strcut(char *str, size_t max_len);

#endif
