/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 20:42:19 by astepano          #+#    #+#             */
/*   Updated: 2017/03/07 20:42:21 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <wchar.h>

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			ft_tolower(int c);
char		*ft_strjoin(char const *s1, char const *s2);
void		ft_putstr(const char *s);
char		*ft_itoa_base(long long value, int base);
int			ft_strcchr(const char *str, char c);
size_t		ft_nbrlen(char *nbr);
char		*ft_strjoinchr(char const c1, char *s2);
char		*ft_nbrjoinchr_count(char const c1, int count, char *s2);
char		*ft_strjoinchr_end(char const c1, int count, char *s2);
char		*ft_strjoinchr_start(char const c1, int count, char *s2);
char		*ft_utoa_base(unsigned long long value, int b, char size, int hash);
char		*ft_wint_to_str(wint_t wint);
char		*ft_wchar_to_str(wchar_t *s, int max_len);
char		*ft_strcut(char *str, int max_len);

#endif
