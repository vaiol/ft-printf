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
