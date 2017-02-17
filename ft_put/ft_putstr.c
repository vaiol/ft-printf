/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 13:33:01 by astepano          #+#    #+#             */
/*   Updated: 2016/12/04 13:33:03 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_put.h"

size_t	ft_putstr(char const *s)
{
	size_t size;

	if (!s)
	{
		ft_putstr("(null)");
		return (0);
	}
	size = 0;
	while (s[size])
		size++;
	return (ft_write(1, s, size));
}

size_t	ft_putwstr(wchar_t *s)
{
	size_t printed;
	size_t size;

	if (!s)
	{
		ft_putstr("(null)");
		return (0);
	}
	printed = 0;
	size = 0;
	while (s[size])
		printed += ft_putwint(s[size++]);
}
