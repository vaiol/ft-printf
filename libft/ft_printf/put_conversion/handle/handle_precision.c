#include "handle.h"

char		*handle_precision(t_conversion *conv, char *str, int len, size_t margin)
{
	int	count;

	count = conv->precision - ((int)ft_strlen(str) - len);
	if (count > 0)
		str = strjoinchr_begin(str, '0', count, margin);
	return (str);
}
