#include "put_form.h"

char	*ft_getwint(wint_t wint)
{
	char	*str;

	if (wint <= 0x7F)
	{
		str = (char *)malloc(sizeof(char) * 2);
		str[0] = (char)wint;
		str[1] = '\0';
		return (str);
	}
	if (wint <= 0x7FF)
	{
		str = (char *)malloc(sizeof(char) * 3);
		str[0] = (char)(((wint & 0x07c0) >> 6) + 0xc0);
		str[1] = (char)((wint & 0x003F) + 0x80);
		str[2] = '\0';
		return (str);
	}
	if (wint <= 0xFFFF)
	{
		str = (char *)malloc(sizeof(char) * 4);
		str[0] = (char)(((wint & 0xF000) >> 12) + 0xE0);
		str[1] = (char)(((wint & 0x0Fc0) >> 6) + 0x80);
		str[2] = (char)((wint & 0x003F) + 0x80);
		str[3] = '\0';
		return (str);
	}
	if (wint <= 0x10FFFF)
	{
		str = (char *)malloc(sizeof(char) * 5);
		str[0] = (char)(((wint & 0x1c0000) >> 18) + 0xF0);
		str[1] = (char)(((wint & 0x03F000) >> 12) + 0x80);
		str[2] = (char)(((wint & 0x0Fc0) >> 6) + 0x80);
		str[3] = (char)((wint & 0x003F) + 0x80);
		str[4] = '\0';
		return (str);
	}
}

char	*ft_getwstr(wchar_t *s, int max_len)
{
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
		str = ft_strjoin(str, ft_getwint(s[size]));
		if (max_len >= 0 && ft_strlen(str) > max_len)
		{
			free(str);
			str = tmp;
			break;
		}
		free(tmp);
		size++;
	}
	return (str);
}

char 		*ft_strcut(char *str, size_t max_len)
{
	char 	*result;
	size_t	str_len;
	size_t	i;

	if (max_len < 0)
		return (str);
	str_len = ft_strlen(str);
	if (str_len < max_len)
		max_len = str_len;
	result = (char *)malloc(sizeof(char) * (max_len + 1));
	i = 0;
	while (i < max_len)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	free(str);
	return (result);
}

void		put_string(t_format *form, va_list valist)
{
	char	*str;
	int 	count;

	if (form->conversion.flag == L)
		str = ft_getwstr(va_arg(valist, wchar_t *), form->precision);
	else
		str = va_arg(valist, char *);
	str = ft_strcut(str, (size_t)form->precision);
	count = form->minimum_width - (int)ft_strlen(str);
	if (count > 0)
	{
		if (form->padding == '-')
			str = ft_strjoinchr_end(' ', count, str);
		else if (form->padding == '0')
			str = ft_strjoinchr_start('0', count, str);
		else
			str = ft_strjoinchr_start(' ', count, str);
	}
	ft_putstr(str);
	free(str);
}