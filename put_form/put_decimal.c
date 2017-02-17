#include "put_form.h"

char						*get_apostrophe(char *nbr)
{
	char 	*result;
	size_t	a;
	int		len;
	int 	nbr_len;
	int		new_len;

	len = (int)ft_strlen(nbr);
	nbr_len = (int)ft_nbrlen(nbr);
	new_len = len + ((nbr_len - 1) / 3);
	result = (char *)malloc(sizeof(char) * (new_len + 1));
	result[new_len--] = '\0';
	len--;
	a = 1;
	while (new_len >= 0)
	{
		if (a && !(a % 4) && nbr_len > 0)
			result[new_len--] = ',';
		else
		{
			result[new_len--] = nbr[len--];
			nbr_len--;
		}
		a++;
	}
	free(nbr);
	return (result);
}

static unsigned long long	get_unsigned(t_format *form, va_list valist)
{
	unsigned long long	result;

	if (form->conversion.flag == N)
		result = va_arg(valist, unsigned int);
	else if (form->conversion.flag == HH)
		result = va_arg(valist, unsigned char);
	else if (form->conversion.flag == H)
		result = va_arg(valist, unsigned short);
	else if (form->conversion.flag == L)
		result = va_arg(valist, unsigned long);
	else if (form->conversion.flag == LL)
		result = va_arg(valist, unsigned long long);
	else if (form->conversion.flag == Z)
		result = va_arg(valist, size_t);
	else if (form->conversion.flag == J)
		result = va_arg(valist, uintmax_t);
	return (result);
}

static long long			get_signed(t_format *form, va_list valist)
{
	long long	result;

	if (form->conversion.flag == N)
		result = va_arg(valist, int);
	else if (form->conversion.flag == HH)
		result = va_arg(valist, char);
	else if (form->conversion.flag == H)
		result = va_arg(valist, short);
	else if (form->conversion.flag == L)
		result = va_arg(valist, long);
	else if (form->conversion.flag == LL)
		result = va_arg(valist, long long);
	else if (form->conversion.flag == Z)
		result = va_arg(valist, ssize_t);
	else if (form->conversion.flag == J)
		result = va_arg(valist, intmax_t);
	return (result);
}

void						put_decimal(t_format *form, va_list valist)
{
	if (form->conversion.an_unsigned != d)
		put_unsigned(form, get_unsigned(form, valist));
	else
		put_signed(form, get_signed(form, valist));
}
