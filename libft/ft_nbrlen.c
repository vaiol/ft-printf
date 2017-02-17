#include "libft.h"

size_t		ft_nbrlen(char *nbr)
{
	size_t	len;

	len = 0;
	while (nbr[len] && (nbr[len] > '9' || nbr[len] < '0'))
		len++;
	return (ft_strlen(nbr + len));
}

size_t		ft_nbrlenu(unsigned long long nbr)
{
	size_t	len;

	len = 1;
	while (nbr /= 10)
		len++;
}

