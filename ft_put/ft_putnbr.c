/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 14:04:52 by astepano          #+#    #+#             */
/*   Updated: 2017/02/16 20:11:03 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_put.h"

size_t	ft_putnbr(long long n)
{
	size_t	minus;

	minus = 0;
	if (n == -9223372036854775808l)
		return (ft_putstr("-9223372036854775808"));
	if (n < 0)
	{
		minus = ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		return (ft_putnbr(n / 10) + ft_putnbr(n % 10));
	return (ft_putchar(n + 48) + minus);
}

size_t	ft_putnbr_unsigned(unsigned long long n)
{
	if (n > 9)
		return (ft_putnbr_unsigned(n / 10) + ft_putnbr_unsigned(n % 10));
	return (ft_putchar(n + 48));
}

size_t	ft_putb(unsigned long long n, int base, char size)
{
	char	*basement;

	if (size == 'X')
		basement = "0123456789ABCDEF";
	else
		basement = "0123456789abcdef";
	if (n >= base)
		return (ft_putb(n / base, base, size) + ft_putb(n % base, base, size));
	return (ft_putchar(basement[n]));
}
