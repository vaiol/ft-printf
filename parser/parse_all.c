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

size_t			parser(const char *format, size_t i, va_list valist)
{
	t_format	*form;

	form = create_form();
	i = parse_flags(format, i, form);
	i = parse_minwidth(format, i, form);
	i = parse_flags(format, i, form);
	i = parse_precision(format, i, form);
	i = parse_flags(format, i, form);
	i = parse_modifier(format, i, form);
	i = parse_type(format, i, form);
	put_form(form, valist);
	return (i);
}
