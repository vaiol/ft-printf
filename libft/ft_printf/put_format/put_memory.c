/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_memory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 19:28:43 by astepano          #+#    #+#             */
/*   Updated: 2017/03/08 19:30:03 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put_format.h"

char		*ft_xxjoinchr_start(char const c1, int count, char *s2, int hash)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s2)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s2) + count + 1));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	if (hash)
	{
		while (i < 2)
			str[j++] = s2[i++];
	}
	while ((count--) > 0)
		str[j++] = c1;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	free(s2);
	return (str);
}

char		*add_padding(t_format *form, char *nbr, int count, int hash)
{
	if (form->padding == '-')
		nbr = ft_strjoinchr_end(' ', count, nbr);
	else if (form->padding == '0' && form->precision < 0)
		nbr = ft_xxjoinchr_start('0', count, nbr, hash);
	else
		nbr = ft_strjoinchr_start(' ', count, nbr);
	return (nbr);
}

static char	*get_xx(t_format *form, unsigned long long number, int hash)
{
	int		count;
	char	*nbr;

	nbr = ft_utoa_base(number, 16, form->type, hash);
	count = form->precision - (int)ft_strlen(nbr);
	if (hash)
		count += 2;
	if (count > 0)
		nbr = ft_xxjoinchr_start('0', count, nbr, hash);
	if (!form->precision)
		nbr = ft_strcut(nbr, 2);
	count = form->minimum_width - (int)ft_strlen(nbr);
	if (count > 0)
		nbr = add_padding(form, nbr, count, hash);
	return (nbr);
}

void		put_memory(t_format *form, va_list valist)
{
	char				*str;
	unsigned long long	memory;

	memory = (unsigned long long)va_arg(valist, void *);
	form->type = 'x';
	form->hashtag = 1;
	str = get_xx(form, memory, form->hashtag);
	putstr(str);
	free(str);
}
