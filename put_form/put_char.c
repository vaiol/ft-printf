/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:27:17 by astepano          #+#    #+#             */
/*   Updated: 2017/03/04 21:27:18 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put_form.h"

//TODO 25 lines in putchar

void		put_char(t_format *form, va_list valist)
{
	char	*chr;
	int		count;

	if (form->modifier == L)
		chr = ft_wint_to_str(va_arg(valist, wint_t));
	else
	{
		chr = (char *)malloc(sizeof(char) * 2);
		if (form->null_type)
			chr[0] = form->null_type;
		else
			chr[0] = va_arg(valist, int);
		chr[1] = '\0';
	}
	count = form->minimum_width - (int)ft_strlen(chr);
	if (count > 0)
	{
		if (form->padding == '-')
			chr = ft_strjoinchr_end(' ', count, chr);
		else if (form->padding == '0')
			chr = ft_strjoinchr_start('0', count, chr);
		else
			chr = ft_strjoinchr_start(' ', count, chr);
	}
	ft_putstr(chr);
	free(chr);
}
