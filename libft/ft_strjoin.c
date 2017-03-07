/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 11:58:14 by astepano          #+#    #+#             */
/*   Updated: 2016/12/14 11:58:25 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//TODO refactor

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoinchr(char const c1, char *s2)
{
	char	*str;
	size_t	i;

	if (!s2)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s2) + 2));
	if (!str)
		return (0);
	i = 0;
	str[i] = c1;
	while (s2[i])
	{
		str[i + 1] = s2[i];
		i++;
	}
	str[i + 1] = '\0';
	free(s2);
	return (str);
}

char	*ft_nbrjoinchr_count(char const c1, int count, char *s2)
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
	while (s2[i] && (s2[i] > '9' || s2[i] < '0'))
		str[j++] = s2[i++];
	while ((count--) > 0)
		str[j++] = c1;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	free(s2);
	return (str);
}

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

char	*ft_strjoinchr_end(char const c1, int count, char *s2)
{
	char	*str;
	size_t	i;

	if (!s2)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s2) + count + 1));
	if (!str)
		return (0);
	i = 0;
	while (s2[i])
	{
		str[i] = s2[i];
		i++;
	}
	while ((count--) > 0)
		str[i++] = c1;
	str[i] = '\0';
	free(s2);
	return (str);
}
