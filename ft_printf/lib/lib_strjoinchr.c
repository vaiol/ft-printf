#include "lib.h"

char	*ft_strjoinchr(char const c1, char *s2)
{
	char	*str;
	size_t	i;

	if (!s2)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s2) + 2));
	if (!str)
		return (0);
	i = 0;
	str[i] = c1;
	while (s2[i])
	{
		str[i + 1] = s2[i];
		i++;
	}
	str[i + 1] = '\0';
	free(s2);
	return (str);
}
