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
	count = form->precision - (int)ft_nbrlen(nbr);
	if (count > 0)
		nbr = ft_nbrjoinchr_count('0', count, nbr);
	if (!form->precision && !number)
		nbr = ft_strdup("");
	count = form->minimum_width - (int)ft_strlen(nbr);
	if (count > 0)
	{
		if (form->padding == '-')
			nbr = ft_strjoinchr_end(' ', count, nbr);
		else if (form->padding == '0' && form->precision < 0)
			nbr = ft_nbrjoinchr_count('0', count, nbr);
		else
			nbr = ft_strjoinchr_start(' ', count, nbr);
	}
	lib_putstr(nbr);
	free(nbr);
}
