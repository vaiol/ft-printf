/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_signed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:28:21 by astepano          #+#    #+#             */
/*   Updated: 2017/03/04 21:28:23 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put_format.h"

void		put_signed(t_format *form, long long number)
{
	size_t	margin;
	char	*nbr;

	margin = (size_t)(form->sign || number < 0);
	nbr = ft_itoa_base(number, 10);
	if (form->sign && number >= 0)
		nbr = strjoinchr(nbr, form->sign, 1, BEGIN);
	if (form->apostrophe)
		nbr = handle_apostrophe(nbr);
	nbr = handle_precision(form, nbr, (int)margin, margin);
	if (!form->precision && !number)
		nbr = strclear(nbr);
	nbr = handle_minwidth(form, nbr, margin);
	putstr(nbr);
	free(nbr);
}