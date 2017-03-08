/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_modifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:14:56 by astepano          #+#    #+#             */
/*   Updated: 2017/03/04 21:14:57 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_all.h"

size_t	parse_modifier(const char *f, size_t i, t_format *form)
{
	if (f[i] == 'h')
	{
		if (f[i + 1] == 'h' && i++)
			form->size = HH;
		else
			form->size = H;
	}
	else if (f[i] == 'l')
	{
		if (f[i + 1] == 'l' && i++)
			form->size = LL;
		else
			form->size = L;
	}
	else if (f[i] == 'j')
		form->size = J;
	else if (f[i] == 'z')
		form->size = Z;
	else
		return (i);
	return (i + 1);
}
