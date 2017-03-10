#include "util.h"

char	*wstrtostr(wchar_t *s, int max_len)
{
	char	*wint_tmp;
	char	*tmp;
	char	*str;
	size_t	size;

	if (!s)
		return (ft_strdup("(null)"));
	size = 0;
	str = ft_strdup("");
	while (s[size])
	{
		tmp = str;
		wint_tmp = winttostr(s[size]);
		str = ft_strjoin(str, wint_tmp);
		free(wint_tmp);
		if (max_len >= 0 && (int)ft_strlen(str) > max_len)
		{
			free(str);
			str = tmp;
			break ;
		}
		free(tmp);
		size++;
	}
	return (str);
}
