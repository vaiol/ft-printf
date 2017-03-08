#include "lib.h"

static char	*apostrophe_result(int len, int slen, char *result, char *nbr)
{
	size_t	a;
	int		nlen;

	nlen = (int)ft_nbrlen(nbr);
	a = 0;
	while (slen >= 0 && ++a)
	{
		if (a && !(a % 4) && nlen > 0)
			result[slen--] = ',';
		else
		{
			result[slen--] = nbr[len--];
			nlen--;
		}
	}
	return (result);
}

char		*get_apostrophe(char *nbr)
{
	char	*result;
	int		len;
	int		slen;
	int		nlen;

	if (!nbr)
		return (NULL);
	nlen = (int)ft_nbrlen(nbr);
	len = (int)ft_strlen(nbr);
	slen = len + ((nlen - 1) / 3);
	result = (char *)malloc(sizeof(char) * (slen + 1));
	result[slen--] = '\0';
	len--;
	result = apostrophe_result(len, slen, result, nbr);
	free(nbr);
	return (result);
}
