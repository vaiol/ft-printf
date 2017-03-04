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
# include "ft_handlers/ft_handlers.h"
# include "ft_put/ft_put.h"
# include "libft/libft.h"

/*
** minimum_width: an_unsigned
** precision	: .an_unsigned
** hashtag		: #
** apostrophe	: '
** padding		: -0
** sign			: + (space)
** flag			: hh, h, l, ll, z, j
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
	UNDEFINED,
	DECIMAL,
	DOUBLE,
	STRING,
	CHAR,
	POINTER
}				t_type;

typedef enum	e_unsigned
{
	d,
	o,
	u,
	x,
	X
}				t_unsigned;

typedef struct	s_convers
{
	t_flag 		flag;
	t_type		type;
	t_unsigned	an_unsigned;
	char 		undefined;

}				t_convers;

typedef struct	s_format
{
	int			minimum_width;
	int			precision;
	int			hashtag;
	int			apostrophe;
	char		padding;
	char		sign;
	t_convers	conversion;

}				t_format;


size_t			parser(const char *format, size_t i, va_list valist);
void			put_form(t_format *form, va_list valist);
int				ft_printf(const char *restrict format, ...);

#endif
