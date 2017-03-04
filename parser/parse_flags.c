/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:14:40 by astepano          #+#    #+#             */
/*   Updated: 2017/03/04 21:14:41 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_all.h"

size_t	parse_flags(const char *format, size_t i, t_format *form)
{
	while (format[i])
	{
		if (format[i] == '#')
			form->hashtag = 1;
		else if (format[i] == '\'')
			form->apostrophe = 1;
		else if (format[i] == ' ' && form->sign != '+')
			form->sign = ' ';
		else if (format[i] == '+')
			form->sign = '+';
		else if (format[i] == '0' && form->padding != '-')
			form->padding = '0';
		else if (format[i] == '-')
			form->padding = '-';
		else
			break ;
		i++;
	}
	return (i);
}
