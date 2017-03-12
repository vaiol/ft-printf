/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_float.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 23:45:02 by astepano          #+#    #+#             */
/*   Updated: 2017/03/11 23:45:04 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put_conversion.h"

void	put_float(t_conversion *conv, va_list valist)
{
	size_t	margin;
	char	*str;

	if (conv->precision < 0)
		conv->precision = 6;
	str = handle_double(va_arg(valist, double), conv->precision);
	margin = (size_t)(conv->sign || str[0] == '-');
	if (conv->sign && str[0] != '-')
		str = strjoinchr(str, conv->sign, 1, BEGIN);
	conv->precision = -1;
	str = handle_minwidth(conv, str, margin);
	putstr(str);
	free(str);
}
