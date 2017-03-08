/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_write.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 19:27:33 by astepano          #+#    #+#             */
/*   Updated: 2017/03/08 19:27:34 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_write(int fildes, const void *buf, size_t nbyte)
{
	g_count += write(fildes, buf, nbyte);
}

int		get_count_symbols(void)
{
	int	count;

	count = (int)g_count;
	g_count = 0;
	return (count);
}
