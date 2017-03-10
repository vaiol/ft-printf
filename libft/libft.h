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
char		*ft_itoa_base(long long value, int base);
int			ft_strcchr(const char *str, char c);
char		*ft_strcut(char *str, int max_len);
int			ft_printf(const char *restrict format, ...);

#endif
