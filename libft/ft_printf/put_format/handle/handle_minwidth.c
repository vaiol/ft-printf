#include "handle.h"

char		*handle_minwidth(t_format *form, char *str, size_t margin)
{
	int	count;

	count = form->minimum_width - (int)ft_strlen(str);
	if (count > 0)
	{
		if (form->padding == '-')
			str = strjoinchr(str, ' ', count, END);
		else if (form->padding == '0' && form->precision < 0)
			str = strjoinchr_begin(str, '0', count, margin);
		else
			str = strjoinchr(str, ' ', count, BEGIN);
	}
	return (str);
}

