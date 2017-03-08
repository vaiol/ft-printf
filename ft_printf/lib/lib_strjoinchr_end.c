#include "lib.h"

char	*ft_strjoinchr_end(char const c1, int count, char *s2)
{
	char	*str;
	size_t	i;

	if (!s2)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s2) + count + 1));
	if (!str)
		return (0);
	i = 0;
	while (s2[i])
	{
		str[i] = s2[i];
		i++;
	}
	while ((count--) > 0)
		str[i++] = c1;
	str[i] = '\0';
	free(s2);
	return (str);
}