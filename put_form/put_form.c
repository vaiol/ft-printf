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

void	put_form(t_format *form, va_list valist)
{
	if (form->type == DECIMAL)
		put_decimal(form, valist);
	else if (form->type == STRING)
		put_string(form, valist);
	else if (form->type == CHAR)
		put_char(form, valist);
}
