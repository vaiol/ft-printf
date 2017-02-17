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
# include <wchar.h>

size_t	*g_count;

int		get_count_symbols(void);
size_t	ft_write(int fildes, const void *buf, size_t nbyte);
size_t	ft_putchar(char c);
size_t	ft_putstr(char const *s);
size_t	ft_putnbr(long long n);
size_t	ft_putnbr_unsigned(unsigned long long n);
size_t	ft_putb(unsigned long long n, int base, char size);
size_t	ft_putmem(void *memory);
size_t	ft_putwint(wint_t wint);
size_t	ft_putwstr(wchar_t *s);

#endif
