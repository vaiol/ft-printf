/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:42:11 by astepano          #+#    #+#             */
/*   Updated: 2017/03/10 17:42:12 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put.h"

void	ft_write(const void *buf, size_t nbyte)
{
	if (g_fd == 0)
		g_fd = 1;
	g_count += write(g_fd, buf, nbyte);
}
