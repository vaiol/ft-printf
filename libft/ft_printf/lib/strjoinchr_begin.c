/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_strjoinchr_end.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 19:26:23 by astepano          #+#    #+#             */
/*   Updated: 2017/03/08 19:26:25 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*strjoinchr_begin(char *str, char const chr, int count, size_t margin)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!str)
		return (0);
	result = (char *)malloc(sizeof(char) * (ft_strlen(str) + count + 1));
	if (!result)
		return (0);
	j = 0;
	i = 0;
	while (str[i] && j < margin)
		result[j++] = str[i++];
	while ((count--) > 0)
		result[j++] = chr;
	while (str[i])
		result[j++] = str[i++];
	result[j] = '\0';
	free(str);
	return (result);
}
