/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 20:11:41 by astepano          #+#    #+#             */
/*   Updated: 2017/02/16 20:11:43 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_put.h"

size_t	ft_write(int fildes, const void *buf, size_t nbyte)
{
	ssize_t	printed;

	if (!g_count)
	{
		g_count = (size_t *)malloc(sizeof(size_t));
		*g_count = 0;
	}
	printed = write(fildes, buf, nbyte);
	*g_count += printed;
	return ((size_t)printed);
}

int		get_count_symbols(void)
{
	return ((int)*g_count);
}
