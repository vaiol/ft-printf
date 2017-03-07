/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_form.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:27:33 by astepano          #+#    #+#             */
/*   Updated: 2017/03/04 21:27:35 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put_form.h"

static void	put_memory(t_format *form, va_list valist)
{
	unsigned long long	memory;

	memory = (unsigned long long)va_arg(valist, void *);
	form->type = 'x';
	form->hashtag = 1;
	put_unsigned(form, memory);
}

void		put_form(t_format *form, va_list valist)
{
	if (ft_strcchr("diouxX", form->type))
		put_decimal(form, valist);
	else if (form->type == 's')
		put_string(form, valist);
	else if (form->type == 'p')
		put_memory(form, valist);
	else
		put_char(form, valist);
}
