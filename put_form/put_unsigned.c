/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:28:36 by astepano          #+#    #+#             */
/*   Updated: 2017/03/04 21:28:38 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put_form.h"

//TODO refactor

static char	*ft_xxjoinchr_start(char const c1, int count, char *s2, int hash)
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
		nbr = ft_strdup("");
	count = form->minimum_width - (int)ft_strlen(nbr);
	if (count > 0)
	{
		if (form->padding == '-')
			nbr = ft_strjoinchr_end(' ', count, nbr);
		else if (form->padding == '0' && form->precision < 0)
			nbr = ft_xxjoinchr_start('0', count, nbr, hash);
		else
			nbr = ft_strjoinchr_start(' ', count, nbr);
	}
	return (nbr);
}

static char	*add_padding(t_format *form, char *nbr, int count)
{
	if (form->padding == '-')
		nbr = ft_strjoinchr_end(' ', count, nbr);
	else if (form->padding == '0' && form->precision < 0)
		nbr = ft_strjoinchr_start('0', count, nbr);
	else
		nbr = ft_strjoinchr_start(' ', count, nbr);
	return (nbr);
}

static char	*get_o(t_format *form, unsigned long long number, int hash)
{
	int		count;
	char	*nbr;

	nbr = ft_utoa_base(number, 8, 'x', hash);
	if (form->apostrophe)
		nbr = put_apostrophe(nbr);
	count = form->precision - (int)ft_strlen(nbr);
	if (count > 0)
		nbr = ft_strjoinchr_start('0', count, nbr);
	if (!form->precision && !form->hashtag)
		nbr = ft_strdup("");
	count = form->minimum_width - (int)ft_strlen(nbr);
	if (count > 0)
		nbr = add_padding(form, nbr, count);
	return (nbr);
}

static char	*get_u(t_format *form, unsigned long long number, int hash)
{
	int		count;
	char	*nbr;

	nbr = ft_utoa_base(number, 10, ' ', hash);
	if (form->apostrophe)
		nbr = put_apostrophe(nbr);
	count = form->precision - (int)ft_nbrlen(nbr);
	if (count > 0)
		nbr = ft_nbrjoinchr_count('0', count, nbr);
	if (!form->precision && !form->hashtag)
		nbr = ft_strdup("");
	count = form->minimum_width - (int)ft_strlen(nbr);
	if (count > 0)
		nbr = add_padding(form, nbr, count);
	return (nbr);
}



void		put_unsigned(t_format *form, unsigned long long number)
{
	char	*nbr;
	int 	hash;

	nbr = NULL;
	if (number == 0)
		hash = 0;
	else
		hash = form->hashtag;
	if (form->type == 'u')
		nbr = get_u(form, number, hash);
	else if (form->type == 'o')
		nbr = get_o(form, number, hash);
	else if (ft_strcchr("xX", form->type))
		nbr = get_xx(form, number, hash);
	ft_putstr(nbr);
	free(nbr);
}
