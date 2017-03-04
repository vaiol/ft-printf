/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:06:26 by astepano          #+#    #+#             */
/*   Updated: 2017/03/04 21:06:28 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa_puthash(char *result, int hash, char size, int base)
{
	if (size == 'X' && hash)
	{
		result[0] = '0';
		if (base == 16)
			result[1] = 'X';
	}
	else if (size == 'x' && hash)
	{
		result[0] = '0';
		if (base == 16)
			result[1] = 'x';
	}
	return (result);
}

char	*ft_utoa_base(unsigned long long value, int base, char size, int hash)
{
	char		*basement;
	char		*result;
	long long	v;
	long long	tmp;
	int			len;

	if (size == 'X')
		basement = "0123456789ABCDEF";
	else
		basement = "0123456789abcdef";
	len = (hash && (base == 16)) ? 3 : 1;
	len = (hash && (base == 8)) ? 2 : len;
	v = value;
	tmp = value;
	while ((tmp /= base))
		len++;
	result = (char *)malloc(sizeof(char) * (len + 1));
	result[len] = '\0';
	while (len--)
	{
		result[len] = basement[v % base];
		v /= base;
	}
	result = ft_utoa_puthash(result, hash, size, base);
	return (result);
}
