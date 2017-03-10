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
	char	*nbr;

	nbr = ft_utoa_base(number, 16, form->type, hash);
	nbr = handle_precision(form, nbr, hash, (size_t)hash);
	if (!form->precision)
		nbr = strclear(nbr);
	nbr = handle_minwidth(form, nbr, (size_t)hash);
	return (nbr);
}

static char	*get_o(t_format *form, unsigned long long number, int hash, int base)
{
	char	*nbr;

	nbr = ft_utoa_base(number, base, form->type, hash);
	if (form->apostrophe)
		nbr = handle_apostrophe(nbr);
	nbr = handle_precision(form, nbr, 0, 0);
	if (!form->precision && !form->hashtag)
		nbr = strclear(nbr);
	nbr = handle_minwidth(form, nbr, 0);
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
		nbr = get_o(form, number, hash, 10);
	else if (form->type == 'o')
		nbr = get_o(form, number, hash, 8);
	else if (ft_strcchr("xX", form->type))
		nbr = get_xx(form, number, hash);
	putstr(nbr);
	free(nbr);
}
