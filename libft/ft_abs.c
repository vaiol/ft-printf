/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 23:39:21 by astepano          #+#    #+#             */
/*   Updated: 2017/03/11 23:39:22 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_abs(long long nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}