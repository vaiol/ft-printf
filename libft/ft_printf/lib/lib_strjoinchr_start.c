/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_strjoinchr_start.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 19:26:33 by astepano          #+#    #+#             */
/*   Updated: 2017/03/08 19:26:34 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*ft_strjoinchr_start(char const c1, int count, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s2)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s2) + count + 1));
	if (!str)
		return (0);
	j = 0;
	while ((count--) > 0)
		str[j++] = c1;
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	free(s2);
	return (str);
}
