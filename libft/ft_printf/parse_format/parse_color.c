/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 21:21:42 by astepano          #+#    #+#             */
/*   Updated: 2017/03/14 21:21:43 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_all.h"

char	**create_colors(void)
{
	char	**array;

	array = (char **)malloc(sizeof(char *) * 10);
	array[0] = "black}";
	array[1] = "red}";
	array[2] = "green}";
	array[3] = "yellow}";
	array[4] = "blue}";
	array[5] = "magenta}";
	array[6] = "cyan}";
	array[7] = "white}";
	array[8] = "eoc}";
	array[9] = NULL;
	return (array);
}

char	**create_escapes(void)
{
	char	**array;

	array = (char **)malloc(sizeof(char *) * 10);
	array[0] = "\x1B[30m\0";
	array[1] = "\x1B[31m\0";
	array[2] = "\x1B[32m\0";
	array[3] = "\x1B[33m\0";
	array[4] = "\x1B[34m\0";
	array[5] = "\x1B[35m\0";
	array[6] = "\x1B[36m\0";
	array[7] = "\x1B[37m\0";
	array[8] = "\x1B[0m\0";
	array[9] = NULL;
	return (array);
}

size_t	equal(char *str, char *format)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ft_tolower(format[i]))
			return (0);
		i++;
	}
	return (i);
}

size_t	parse_color(const char *f, size_t i)
{
	char	*format;
	char	**colors;
	char	**escapes;
	size_t	len;
	size_t	index;

	format = (char *)f + i;
	colors = create_colors();
	escapes = create_escapes();
	index = 0;
	while (colors[index])
	{
		if ((len = equal(colors[index], format)))
		{
			putstr(escapes[index]);
			return (i + len);
		}
		index++;
	}
	putstr("{");
	return (i);
}
