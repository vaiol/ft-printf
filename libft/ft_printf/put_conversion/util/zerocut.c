#include "util.h"

char	*zerocut(char *nbr)
{
	int	i;

	i = (int)ft_strlen(nbr) - 1;
	while (i >= 0)
	{
		if (nbr[i] != '0')
			break ;
		i--;
	}
	return (ft_strcut(nbr, i + 1));
}
