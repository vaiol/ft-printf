/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_form.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:28:10 by astepano          #+#    #+#             */
/*   Updated: 2017/03/04 21:28:14 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT_FORM_H
# define PUT_FORM_H

# include "../ft_printf.h"

void	put_char(t_format *form, va_list valist);
void	put_string(t_format *form, va_list valist);
void	put_decimal(t_format *form, va_list valist);
void	put_unsigned(t_format *form, unsigned long long number);
void	put_signed(t_format *form, long long number);
char	*put_apostrophe(char *nbr);

#endif
