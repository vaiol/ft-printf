#include "put_form.h"

static char		*get_oxX(t_format *form, unsigned long long number)
{
	int		count;
	char	*nbr;

	if (form->conversion.an_unsigned == o)
		nbr = ft_utoa_base(number, 8, 'x', form->hashtag);
	else if (form->conversion.an_unsigned == x)
		nbr = ft_utoa_base(number, 16, 'x', form->hashtag);
	else if (form->conversion.an_unsigned == X)
		nbr = ft_utoa_base(number, 16, 'X', form->hashtag);

	if (form->apostrophe && form->conversion.an_unsigned == o)
		nbr = get_apostrophe(nbr);
	count = form->precision - ft_strlen(nbr);
	if (count > 0)
		nbr = ft_strjoinchr_start('0', count, nbr);
	count = form->minimum_width - ft_strlen(nbr);
	if (count > 0)
	{
		if (form->padding == '-')
			nbr = ft_strjoinchr_end(' ', count, nbr);
		else if (form->padding == '0' && !form->precision)
			nbr = ft_strjoinchr_start('0', count, nbr);
		else
			nbr = ft_strjoinchr_start(' ', count, nbr);
	}
	return (nbr);
}

void			put_unsigned(t_format *form, unsigned long long number)
{
	int		count;
	char	*nbr;

	if (form->conversion.an_unsigned == u)
	{
		nbr = ft_utoa_base(number, 10, ' ', form->hashtag);
		if (form->apostrophe)
			nbr = get_apostrophe(nbr);
		count = form->precision - (int)ft_nbrlen(nbr);
		if (count > 0)
			nbr = ft_nbrjoinchr_count('0', count, nbr);
		count = form->minimum_width - (int)ft_strlen(nbr);
		if (count > 0)
		{
			if (form->padding == '-')
				nbr = ft_strjoinchr_end(' ', count, nbr);
			else if (form->padding == '0' && !form->precision)
				nbr = ft_nbrjoinchr_count('0', count, nbr);
			else
				nbr = ft_strjoinchr_start(' ', count, nbr);
		}
	}
	else
		nbr = get_oxX(form, number);
	ft_putstr(nbr);
	free(nbr);
}