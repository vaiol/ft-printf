/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:18:11 by astepano          #+#    #+#             */
/*   Updated: 2017/02/13 17:18:13 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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

typedef enum	e_flag
{
	N,
	HH,
	H,
	L,
	LL,
	J,
	Z
}				t_flag;

typedef enum	e_type
{
	DECIMAL,
	STRING,
	CHAR,
	POINTER
}				t_type;

typedef struct	s_format
{
	int			minimum_width;
	int			precision;
	int			hashtag;
	int			apostrophe;
	char		padding;
	char		sign;
	char		null_type;
	char		unsigned_type;
	t_flag		modifier;
	t_type		type;

}				t_format;

size_t			parser(const char *format, size_t i, va_list valist);
void			put_form(t_format *form, va_list valist);
int				ft_printf(const char *restrict format, ...);

#endif
