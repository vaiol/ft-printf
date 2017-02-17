/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 10:39:22 by exam              #+#    #+#             */
/*   Updated: 2017/01/10 11:05:03 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa_base(long long value, int base)
{
	char	*basement;
	char	*result;
	long long	v;
	long long	tmp;
	int		len;

	basement = "0123456789ABCDEF";
	len = 1;
	v = tmp = value;
	while ((tmp /= base))
		len++;
	if (v < 0)
	{
		if (base == 10)
			len++;
		v = -v;
	}
	result = (char *)malloc(sizeof(char) * (len + 1));
	result[len] = '\0';
	while (len--)
	{
		result[len] = basement[v % base];
		v /= base;
	}
	if (value < 0 && base == 10)
		result[0] = '-';
	return (result);
}

char 	*ft_utoa_puthash(char *result, int hash, char size, int base)
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
	v = tmp = value;
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
