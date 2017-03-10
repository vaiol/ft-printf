/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:14:20 by astepano          #+#    #+#             */
/*   Updated: 2017/03/04 21:14:22 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_all.h"

static t_format	*create_form(void)
{
	t_format	*form;

	form = (t_format *)malloc(sizeof(t_format));
	form->precision = -1;
	form->minimum_width = 0;
	form->hashtag = 0;
	form->apostrophe = 0;
	form->padding = '\0';
	form->sign = '\0';
	form->type = '\0';
	form->size = N;
	return (form);
}

size_t			parse(const char *f, size_t i, va_list valist)
{
	size_t		tmp;
	t_format	*form;

	form = create_form();
	tmp = 0;
	while (f[i] && tmp != i)
	{
		tmp = i;
		i = parse_flags(f, i, form);
		i = parse_minwidth(f, i, form, valist);
		i = parse_precision(f, i, form, valist);
		i = parse_size(f, i, form);
	}
	if (f[i])
	{
		i = parse_type(f, i, form);
		put_form(form, valist);
	}
	free(form);
	return (i);
}
