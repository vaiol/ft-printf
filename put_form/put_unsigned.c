/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:28:36 by astepano          #+#    #+#             */
/*   Updated: 2017/03/04 21:28:38 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put_form.h"

static char	*add_padding(t_format *form, char *nbr, int count)
{
	if (form->padding == '-')
		nbr = ft_strjoinchr_end(' ', count, nbr);
	else if (form->padding == '0' && !form->precision)
		nbr = ft_strjoinchr_start('0', count, nbr);
	else
		nbr = ft_strjoinchr_start(' ', count, nbr);
	return (nbr);
}

static char	*get_oxx(t_format *form, unsigned long long number)
{
	int		count;
	char	*nbr;

	nbr = NULL;
	if (form->unsigned_type == 'o')
		nbr = ft_utoa_base(number, 8, 'x', form->hashtag);
	else if (ft_strcchr("xX", form->unsigned_type))
		nbr = ft_utoa_base(number, 16, form->unsigned_type, form->hashtag);
	if (form->apostrophe && form->unsigned_type == 'o')
		nbr = put_apostrophe(nbr);
	count = form->precision - (int)ft_strlen(nbr);
	if (count > 0)
		nbr = ft_strjoinchr_start('0', count, nbr);
	count = form->minimum_width - (int)ft_strlen(nbr);
	if (count > 0)
		nbr = add_padding(form, nbr, count);
	return (nbr);
}

void		put_unsigned(t_format *form, unsigned long long number)
{
	int		count;
	char	*nbr;

	if (form->unsigned_type == 'u')
	{
		nbr = ft_utoa_base(number, 10, ' ', form->hashtag);
		if (form->apostrophe)
			nbr = put_apostrophe(nbr);
		count = form->precision - (int)ft_nbrlen(nbr);
		if (count > 0)
			nbr = ft_nbrjoinchr_count('0', count, nbr);
		count = form->minimum_width - (int)ft_strlen(nbr);
		if (count > 0)
			nbr = add_padding(form, nbr, count);
	}
	else
		nbr = get_oxx(form, number);
	ft_putstr(nbr);
	free(nbr);
}
