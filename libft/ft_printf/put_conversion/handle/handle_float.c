/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 23:31:03 by astepano          #+#    #+#             */
/*   Updated: 2017/03/11 23:31:05 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle.h"

static int		nbrlen(long long nbr)
{
	int	len;

	if (nbr == 0)
		return (1);
	len = 0;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

static int		put_exponent(char *result, long long exponent)
{
	char	*tmp;
	int		i;

	tmp = ft_itoa_base(exponent, 10);
	i = 0;
	while (tmp[i])
	{
		result[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (i);
}

static void		put_fraction(char *result, int index, int precision, double nbr)
{
	int			i;
	double		exponent;
	long long	value;

	exponent = (double)((long long)nbr);
	if (precision > 0)
	{
		result[index++] = '.';
		i = 1;
		while (i <= precision)
		{
			value = ft_abs((long long)((nbr - exponent) * ft_pow(10.0, i)));
			result[index] = (char)(((value) % 10) + 48);
			index++;
			i++;
		}
	}
}

static void		ft_round(char *str, int index)
{
	if (str[index] == '.')
	{
		ft_round(str, index - 1);
		return ;
	}
	if (str[index] == '9')
	{
		ft_round(str, index - 1);
		str[index] = '0';
		return ;
	}
	str[index]++;
}

char			*handle_float(double nbr, int precision)
{
	long long	exponent;
	char		*result;
	int			e_count;
	int			i;

	exponent = (long long)nbr;
	e_count = nbrlen(exponent);
	precision = nbr < 0 ? precision + 1 : precision;
	result = malloc(sizeof(char) * (e_count + (++precision) + 2));
	i = put_exponent(result, exponent);
	put_fraction(result, i, precision, nbr);
	i = 0;
	if (precision > 0)
		i = 1;
	if (result[e_count + precision + i - 1] >= '5')
		ft_round(result, e_count + precision + i - 2);
	precision = precision == 1 ? 0 : precision;
	result[e_count + precision + i - 1] = '\0';
	return (result);
}
