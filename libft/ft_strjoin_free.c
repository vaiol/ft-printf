#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, t_free f)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	if (f == BOTH || f == FIRST)
		free(s1);
	if (f == BOTH || f == SECOND)
		free(s2);
	return (str);
}

