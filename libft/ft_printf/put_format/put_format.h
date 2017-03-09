/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_format.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 19:28:21 by astepano          #+#    #+#             */
/*   Updated: 2017/03/08 19:29:24 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT_FORMAT_H
# define PUT_FORMAT_H

# include "handle/handle.h"

void	put_char(t_format *form, va_list valist);
void	put_string(t_format *form, va_list valist);
void	put_decimal(t_format *form, va_list valist);
void	put_unsigned(t_format *form, unsigned long long number);
void	put_signed(t_format *form, long long number);
void	put_memory(t_format *form, va_list valist);

#endif
