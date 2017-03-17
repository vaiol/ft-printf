#include "libft.h"

static int	check(const char chr, const int base)
{
	int		i;
	char	*basement;

	if (chr == '\0' || base < 1 || base > 16)
		return (-1);
	basement = "0123456789abcdef";
	i = 0;
	while (i < base)
	{
		if (ft_tolower(chr) == basement[i])
			return (i);
		i++;
	}
	return (-1);
}

long long	ft_atoi_base(const char *str, const int base)
{
	unsigned long long	result;
	int					minus;
	size_t				i;

	i = 0;
	minus = 1;
	while (str[i] == ' ' || str[i] == '\t'
		   || str[i] == '\n' || str[i] == '\v'
		   || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	result = 0;
	while (check(str[i], base) >= 0)
	{
		result = result * base + (check(str[i], base));
		if (result >= 9223372036854775807 && minus == 1)
			return (-1);
		else if (result > 9223372036854775807 && minus == -1)
			return (0);
		i++;
	}
	return ((long long)(result * minus));
}
