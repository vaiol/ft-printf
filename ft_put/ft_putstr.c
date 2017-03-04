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

void	ft_putstr(char const *s)
{
	size_t size;

	if (!s)
	{
		ft_putstr("(null)");
		return ;
	}
	size = 0;
	while (s[size])
		size++;
	ft_write(1, s, size);
}
