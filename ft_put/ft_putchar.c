/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 12:24:38 by astepano          #+#    #+#             */
/*   Updated: 2017/02/16 20:10:56 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_put.h"

size_t	ft_putchar(char c)
{
	ft_write(1, &c, 1);
}

size_t	ft_putchr_count(char c, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}

size_t	ft_putmem(void *memory)
{
	unsigned long long address;

	address = memory - NULL;
	ft_putstr("0x");
	ft_putb(address, 16, ' ');
}

size_t	ft_putwint(wint_t wint)
{
	char	str[4];

	if (wint <= 0x7F)
		ft_write(1, str, 1);
	else if (wint <= 0x7FF)
	{
		str[0] = (char)(((wint & 0x07c0) >> 6) + 0xc0);
		str[1] = (char)((wint & 0x003F) + 0x80);
		ft_write(1, str, 2);
	}
	else if (wint <= 0xFFFF)
	{
		str[0] = (char)(((wint & 0xF000) >> 12) + 0xE0);
		str[1] = (char)(((wint & 0x0Fc0) >> 6) + 0x80);
		str[2] = (char)((wint & 0x003F) + 0x80);
		ft_write(1, str, 3);
	}
	else if (wint <= 0x10FFFF)
	{
		str[0] = (char)(((wint & 0x1c0000) >> 18) + 0xF0);
		str[1] = (char)(((wint & 0x03F000) >> 12) + 0x80);
		str[2] = (char)(((wint & 0x0Fc0) >> 6) + 0x80);
		str[3] = (char)((wint & 0x003F) + 0x80);
		ft_write(1, str, 4);
	}
}
