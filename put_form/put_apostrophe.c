/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_apostrophe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:27:07 by astepano          #+#    #+#             */
/*   Updated: 2017/03/04 21:27:09 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put_form.h"

//TODO 25 lines in apostrophe (norm)

char		*put_apostrophe(char *nbr)
{
	char	*result;
	size_t	a;
	int		len;
	int		nlen;
	int		sl;

	if (!nbr && !(a = 0))
		return (NULL);
	len = (int)ft_strlen(nbr);
	nlen = (int)ft_nbrlen(nbr);
	result = (char *)malloc(sizeof(char) * ((sl = len + ((nlen - 1) / 3)) + 1));
	result[sl--] = '\0';
	len--;
	while (sl >= 0 && ++a)
	{
		if (a && !(a % 4) && nlen > 0)
			result[sl--] = ',';
		else
		{
			result[sl--] = nbr[len--];
			nlen--;
		}
	}
	free(nbr);
	return (result);
}
