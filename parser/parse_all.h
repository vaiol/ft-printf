/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_all.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:14:29 by astepano          #+#    #+#             */
/*   Updated: 2017/03/04 21:14:32 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_ALL_H
# define PARSE_ALL_H
# include "../ft_printf.h"

size_t	parse_flags(const char *format, size_t i, t_format *form);
size_t	parse_specificator(const char *f, size_t i, t_format *form);
size_t	parse_minwidth(const char *format, size_t i, t_format *form);
size_t	parse_precision(const char *format, size_t i, t_format *form);
size_t	parse_modifier(const char *f, size_t i, t_format *form);
size_t	parser(const char *format, size_t i, va_list valist);

#endif
