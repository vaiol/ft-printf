/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_to_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:05:52 by astepano          #+#    #+#             */
/*   Updated: 2017/03/04 21:05:53 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_wchar_to_str(wchar_t *s, int max_len)
{
	char	*tmp;
	char	*str;
	size_t	size;

	if (!s)
		return (ft_strdup("(null)"));
	size = 0;
	str = ft_strdup("");
	while (s[size])
	{
		tmp = str;
		str = ft_strjoin(str, ft_wint_to_str(s[size]));
		if (max_len >= 0 && (int)ft_strlen(str) > max_len)
		{
			free(str);
			str = tmp;
			break ;
		}
		free(tmp);
		size++;
	}
	return (str);
}