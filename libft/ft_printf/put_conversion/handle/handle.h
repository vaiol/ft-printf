/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:37:44 by astepano          #+#    #+#             */
/*   Updated: 2017/03/10 17:41:18 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_H
# define HANDLE_H

# include "../util/util.h"

char	*handle_minwidth(t_conversion *conv, char *str, size_t margin);
char	*handle_precision(t_conversion *conv, char *str, int l, size_t margin);
char	*handle_apostrophe(char *nbr);
char	*handle_float(double nbr, int precision);
char	*handle_double(long double nbr, int precision);
void	ftoa(char *outstr, long double nbr, int p, int t);

#endif
