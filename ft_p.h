/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 20:40:42 by astepano          #+#    #+#             */
/*   Updated: 2017/03/07 20:40:43 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "ft_put/ft_put.h"
# include "libft/libft.h"

/*
** minimum_width: NBR
** precision	: .NBR
** hashtag		: #
** apostrophe	: '
** padding		: -0
** sign			: + (space)
** modifier		: hh, h, l, ll, z, j
** conversion	:
*/

typedef enum	e_size
{
	N,
	HH,
	H,
	L,
	LL,
	J,
	Z
}				t_size;

typedef struct	s_format
{
	int			minimum_width;
	int			precision;
	int			hashtag;
	int			apostrophe;
	char		padding;
	char		sign;
	t_size		size;
	char		type;

}				t_format;

size_t			parser(const char *format, size_t i, va_list valist);
void			put_form(t_format *form, va_list valist);
int				ft_printf(const char *restrict format, ...);

#endif
