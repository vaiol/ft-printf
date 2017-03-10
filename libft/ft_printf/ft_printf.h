/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 20:40:42 by astepano          #+#    #+#             */
/*   Updated: 2017/03/08 16:24:21 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "../libft.h"
# include "put_conversion/put/put.h"

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

typedef struct	s_conversion
{
	int			minimum_width;
	int			precision;
	int			hashtag;
	int			apostrophe;
	char		padding;
	char		sign;
	t_size		size;
	char		type;

}				t_conversion;

size_t			parse(const char *f, size_t i, va_list valist);
void			put_conversion(t_conversion *conv, va_list valist);

#endif
