/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printed_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:42:18 by astepano          #+#    #+#             */
/*   Updated: 2017/03/10 17:42:20 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put.h"

int		printed_count(void)
{
	int	count;

	count = (int)g_count;
	g_count = 0;
	return (count);
}
