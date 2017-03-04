#include "put_form.h"

void		put_char(t_format *form, va_list valist)
{
	char	*chr;
	int 	count;

	if (form->conversion.flag == L)
		chr = ft_getwint(va_arg(valist, wint_t));
	else
	{
		chr = (char *)malloc(sizeof(char) * 2);
		if (form->conversion.type == UNDEFINED)
			chr[0] = form->conversion.undefined;
		else
			chr[0] = va_arg(valist, int);
		chr[1] = '\0';
 	}
	count = form->minimum_width - (int)ft_strlen(chr);
	if (count > 0)
	{
		if (form->padding == '-')
			chr = ft_strjoinchr_end(' ', count, chr);
		else if (form->padding == '0')
			chr = ft_strjoinchr_start('0', count, chr);
		else
			chr = ft_strjoinchr_start(' ', count, chr);
	}
	ft_putstr(chr);
	free(chr);
}
