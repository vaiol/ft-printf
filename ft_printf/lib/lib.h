#ifndef LIBPRINTF_H
# define LIBPRINTF_H

# include "../../libft.h"

size_t	g_count;

int		get_count_symbols(void);
void	ft_write(int fildes, const void *buf, size_t nbyte);
void	lib_putstr(char const *s);
char	*ft_utoa_base(unsigned long long value, int b, char size, int hash);
size_t	ft_nbrlen(char *nbr);
char	*ft_strjoinchr(char const c1, char *s2);
char	*ft_nbrjoinchr_count(char const c1, int count, char *s2);
char	*ft_strjoinchr_end(char const c1, int count, char *s2);
char	*ft_strjoinchr_start(char const c1, int count, char *s2);
char	*ft_wint_to_str(wint_t wint);
char	*ft_wchar_to_str(wchar_t *s, int max_len);
char	*get_apostrophe(char *nbr);

#endif
