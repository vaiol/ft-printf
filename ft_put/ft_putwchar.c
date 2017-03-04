/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 20:11:10 by astepano          #+#    #+#             */
/*   Updated: 2017/02/16 20:11:15 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_put.h"

size_t	ft_putwint(wint_t wint)
{
	char	str[4];

	if (wint <= 0x7F)
		return (ft_write(1, wint, 1));
	if (wint <= 0x7FF)
	{
		str[0] = (char)(((wint & 0x07c0) >> 6) + 0xc0);
		str[1] = (char)((wint & 0x003F) + 0x80);
		return (ft_write(1, str, 2));
	}
	if (wint <= 0xFFFF)
	{
		str[0] = (char)(((wint & 0xF000) >> 12) + 0xE0);
		str[1] = (char)(((wint & 0x0Fc0) >> 6) + 0x80);
		str[2] = (char)((wint & 0x003F) + 0x80);
		return (ft_write(1, str, 3));
	}
	if (wint <= 0x10FFFF)
	{
		str[0] = (char)(((wint & 0x1c0000) >> 18) + 0xF0);
		str[1] = (char)(((wint & 0x03F000) >> 12) + 0x80);
		str[2] = (char)(((wint & 0x0Fc0) >> 6) + 0x80);
		str[3] = (char)((wint & 0x003F) + 0x80);
		return (ft_write(1, str, 4));
	}
}

size_t	ft_putwstr(wchar_t *s)
{
	size_t printed;
	size_t size;

	if (!s)
		return (ft_putstr("(null)"));
	printed = 0;
	size = 0;
	while (s[size])
		printed += ft_putwint(s[size++]);
	return (printed);
}
