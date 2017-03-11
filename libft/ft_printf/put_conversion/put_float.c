#include "put_conversion.h"

void	put_float(t_conversion *conv, va_list valist)
{
	char	*str;

	if (conv->precision < 0)
		conv->precision = 6;
	str = handle_float(va_arg(valist, double), conv->precision);
	str = handle_minwidth(conv, str, 0);
	putstr(str);
	free(str);
}
