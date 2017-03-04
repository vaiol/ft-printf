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

//TODO 25 lines

char	*ft_itoa_base(long long value, int base)
{
	char		*basement;
	char		*result;
	long long	v;
	long long	tmp;
	int			len;

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
