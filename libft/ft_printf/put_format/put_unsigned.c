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

#include "put_format.h"

static char	*get_xx(t_format *form, unsigned long long number, int hash)
{
	int		count;
	char	*nbr;

	nbr = ft_utoa_base(number, 16, form->type, hash);
	count = form->precision - (int)ft_strlen(nbr);
	if (hash)
		count += 2;
	if (count > 0)
		nbr = ft_xxjoinchr_start('0', count, nbr, hash);
	if (!form->precision)
		nbr = strclear(nbr);
	count = form->minimum_width - (int)ft_strlen(nbr);
	if (count > 0)
		nbr = add_padding(form, nbr, count, hash);
	return (nbr);
}

static char	*get_o(t_format *form, unsigned long long number, int hash)
{
	int		count;
	char	*nbr;

	nbr = ft_utoa_base(number, 8, 'x', hash);
	if (form->apostrophe)
		nbr = lib_get_apostrophe(nbr);
	count = form->precision - (int)ft_strlen(nbr);
	if (count > 0)
		nbr = ft_strjoinchr_start('0', count, nbr);
	if (!form->precision && !form->hashtag)
		nbr = strclear(nbr);
	count = form->minimum_width - (int)ft_strlen(nbr);
	if (count > 0)
		nbr = add_padding(form, nbr, count, 0);
	return (nbr);
}

static char	*get_u(t_format *form, unsigned long long number, int hash)
{
	int		count;
	char	*nbr;

	nbr = ft_utoa_base(number, 10, ' ', hash);
	if (form->apostrophe)
		nbr = lib_get_apostrophe(nbr);
	count = form->precision - (int)ft_nbrlen(nbr);
	if (count > 0)
		nbr = ft_nbrjoinchr_count('0', count, nbr);
	if (!form->precision && !form->hashtag)
		nbr = strclear(nbr);
	count = form->minimum_width - (int)ft_strlen(nbr);
	if (count > 0)
		nbr = add_padding(form, nbr, count, 0);
	return (nbr);
}

void		put_unsigned(t_format *form, unsigned long long number)
{
	char	*nbr;
	int		hash;

	nbr = NULL;
	if (number == 0)
		hash = 0;
	else
		hash = form->hashtag;
	if (form->type == 'u')
		nbr = get_u(form, number, hash);
	else if (form->type == 'o')
		nbr = get_o(form, number, hash);
	else if (ft_strcchr("xX", form->type))
		nbr = get_xx(form, number, hash);
	putstr(nbr);
	free(nbr);
}
