/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:15:05 by astepano          #+#    #+#             */
/*   Updated: 2017/03/04 21:15:06 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_all.h"

size_t	parse_precision(const char *format, size_t i, t_format *form)
{
	if (format[i] == '.')
	{
		i++;
		form->precision = 0;
		if (ft_isdigit(format[i]))
		{
			form->precision = ft_atoi(format + i);
			while (ft_isdigit(format[i]))
				i++;
		}
	}
	return (i);
}
