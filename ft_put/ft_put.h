/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 19:43:14 by astepano          #+#    #+#             */
/*   Updated: 2017/02/16 19:43:16 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUT_H
# define FT_PUT_H

# include <unistd.h>
# include <stdlib.h>

size_t	*g_count;

int		get_count_symbols(void);
void	ft_write(int fildes, const void *buf, size_t nbyte);
void	ft_putstr(char const *s);

#endif
