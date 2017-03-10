#ifndef PUT_H
# define PUT_H

#include <unistd.h>

size_t			g_count;

int				printed_count(void);
void			ft_write(int fildes, const void *buf, size_t nbyte);
void			putstr(char const *s);

#endif
