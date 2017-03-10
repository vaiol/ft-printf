#include "put.h"

void	ft_write(int fildes, const void *buf, size_t nbyte)
{
	g_count += write(fildes, buf, nbyte);
}
