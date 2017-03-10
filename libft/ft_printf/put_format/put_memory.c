/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_memory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 19:28:43 by astepano          #+#    #+#             */
/*   Updated: 2017/03/08 19:30:03 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put_format.h"

void		put_memory(t_format *form, va_list valist)
{
	char				*str;
	unsigned long long	memory;

	memory = (unsigned long long)va_arg(valist, void *);
	form->type = 'x';
	form->hashtag = 2;
	str = ft_utoa_base(memory, 16, form->type, form->hashtag);
	str = handle_precision(form, str, form->hashtag, (size_t)form->hashtag);
	if (!form->precision)
		str = ft_strcut(str, 2);
	str = handle_minwidth(form, str, (size_t) form->hashtag);
	putstr(str);
	free(str);
}
