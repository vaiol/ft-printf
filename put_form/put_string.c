/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:28:29 by astepano          #+#    #+#             */
/*   Updated: 2017/03/04 21:28:31 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put_form.h"

void		put_string(t_format *form, va_list valist)
{
	char	*str;
	int		count;

	if (form->size == L)
		str = ft_strdup(
				ft_wchar_to_str(va_arg(valist, wchar_t *), form->precision));
	else
	{
		str = va_arg(valist, char *);
		if (!str)
			str = ft_strdup("(null)");
		else
			str = ft_strdup(str);
	}
	str = ft_strcut(str, form->precision);
	count = form->minimum_width - (int)ft_strlen(str);
	if (count > 0)
	{
		if (form->padding == '-')
			str = ft_strjoinchr_end(' ', count, str);
		else if (form->padding == '0')
			str = ft_strjoinchr_start('0', count, str);
		else
			str = ft_strjoinchr_start(' ', count, str);
	}
	ft_putstr(str);
	free(str);
}
