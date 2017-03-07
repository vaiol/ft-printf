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

static char	*char_to_str(char c)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

void		put_char(t_format *form, va_list valist)
{
	char	*chr;
	int		count;

	if (form->size == L)
		chr = ft_wint_to_str(va_arg(valist, wint_t));
	else
	{
		if (form->type)
			chr = char_to_str(va_arg(valist, int));
		else
			chr = char_to_str(form->type);
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
