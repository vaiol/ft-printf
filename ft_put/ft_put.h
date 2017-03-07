/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 20:42:41 by astepano          #+#    #+#             */
/*   Updated: 2017/03/07 20:42:44 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUT_H
# define FT_PUT_H

# include <unistd.h>
# include <stdlib.h>

size_t	g_count;

int		get_count_symbols(void);
void	ft_write(int fildes, const void *buf, size_t nbyte);
void	ft_putstr(char const *s);

#endif
