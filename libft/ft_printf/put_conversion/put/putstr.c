#include "put.h"

void	putstr(char const *s)
{
	size_t size;

	size = 0;
	while (s[size])
		size++;
	ft_write(1, s, size);
}
