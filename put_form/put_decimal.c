/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_decimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:27:25 by astepano          #+#    #+#             */
/*   Updated: 2017/03/04 21:27:27 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put_form.h"

static unsigned long long	get_unsigned(t_format *form, va_list valist)
{
	unsigned long long	result;

	result = 0;
	if (form->size == N)
		result = va_arg(valist, unsigned int);
	else if (form->size == HH)
		result = va_arg(valist, unsigned char);
	else if (form->size == H)
		result = va_arg(valist, unsigned short);
	else if (form->size == L)
		result = va_arg(valist, unsigned long);
	else if (form->size == LL)
		result = va_arg(valist, unsigned long long);
	else if (form->size == Z)
		result = va_arg(valist, size_t);
	else if (form->size == J)
		result = va_arg(valist, uintmax_t);
	return (result);
}

static long long			get_signed(t_format *form, va_list valist)
{
	long long	result;

	result = 0;
	if (form->size == N)
		result = va_arg(valist, int);
	else if (form->size == HH)
		result = va_arg(valist, char);
	else if (form->size == H)
		result = va_arg(valist, short);
	else if (form->size == L)
		result = va_arg(valist, long);
	else if (form->size == LL)
		result = va_arg(valist, long long);
	else if (form->size == Z)
		result = va_arg(valist, ssize_t);
	else if (form->size == J)
		result = va_arg(valist, intmax_t);
	return (result);
}

void						put_decimal(t_format *form, va_list valist)
{
	if (ft_strcchr("ouxX", form->type))
		put_unsigned(form, get_unsigned(form, valist));
	else
		put_signed(form, get_signed(form, valist));
}
