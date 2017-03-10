/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 19:24:20 by astepano          #+#    #+#             */
/*   Updated: 2017/03/08 21:16:16 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include "../../libft.h"

size_t	g_count;

typedef enum    e_position
{
    BEGIN,
    END
}               t_position;

int		get_count_symbols(void);
void	ft_write(int fildes, const void *buf, size_t nbyte);
void	putstr(char const *s);
char	*ft_utoa_base(unsigned long long value, int b, char size, int hash);
char	*strjoinchr(char *str, char const chr, int count, t_position position);
char	*strjoinchr_begin(char *str, char const chr, int count, size_t margin);
char	*ft_wint_to_str(wint_t wint);
char	*wchartostr(wchar_t *s, int max_len);
char	*handle_apostrophe(char *nbr);
void	putstr(const char *s);
char	*strclear(char *str);

#endif
