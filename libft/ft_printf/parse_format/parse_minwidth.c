/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_minwidth.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:14:50 by astepano          #+#    #+#             */
/*   Updated: 2017/03/04 21:14:51 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_all.h"

size_t	parse_minwidth(const char *format, size_t i, t_format *form)
{
	if (ft_isdigit(format[i]))
	{
		form->minimum_width = ft_atoi(format + i);
		while (ft_isdigit(format[i]))
			i++;
	}
	return (i);
}
