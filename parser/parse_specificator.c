/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_specificator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:15:14 by astepano          #+#    #+#             */
/*   Updated: 2017/03/04 21:15:15 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_all.h"

size_t		parse_specificator(const char *f, size_t i, t_format *form)
{
	char	spec;

	spec = f[i];
	if (ft_strcchr("SDOUC", spec))
	{
		form->modifier = L;
		spec = (char)ft_tolower(spec);
	}
	if (spec == 's')
		form->type = STRING;
	else if (spec == 'c')
		form->type = CHAR;
	else if (spec == 'p')
		form->type = POINTER;
	else if (ft_strcchr("diouxX", spec))
	{
		form->type = DECIMAL;
		if (!ft_strcchr("di", spec))
			form->unsigned_type = spec;
	}
	else
		form->null_type = f[i];
	return (i + 1);
}
