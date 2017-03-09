#include "handle.h"

char		*handle_precision(t_format *form, char *str, int len, size_t margin)
{
	int	count;

	count = form->precision - ((int)ft_strlen(str) + len);
	if (count > 0)
		str = strjoinchr_begin(str, '0', count, margin);
	return (str);
}
