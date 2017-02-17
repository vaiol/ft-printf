#include "put_form.h"

void		put_signed(t_format *form, long long number)
{
	int		count;
	char	*nbr;

	nbr = ft_itoa_base(number, 10);
	if (form->sign && number >= 0)
		nbr = ft_strjoinchr(form->sign, nbr);
	if (form->apostrophe)
		nbr = get_apostrophe(nbr);
	count = form->precision - ft_nbrlen(nbr);
	if (count > 0)
		nbr = ft_nbrjoinchr_count('0', count, nbr);
	count = form->minimum_width - ft_strlen(nbr);
	if (count > 0)
	{
		if (form->padding == '-')
			nbr = ft_strjoinchr_end(' ', count, nbr);
		else if (form->padding == '0' && !form->precision)
			nbr = ft_nbrjoinchr_count('0', count, nbr);
		else
			nbr = ft_strjoinchr_start(' ', count, nbr);
	}
	ft_putstr(nbr);
}
