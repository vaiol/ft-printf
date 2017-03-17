#include "float.h"

unsigned  long long ftohex(long double f, unsigned bits, unsigned eBits, int *e)
{
	long double			fNorm;
	int					shift;
	unsigned long long	significand;
	unsigned			signBits;

	signBits = bits - eBits - 1;
	if (f == 0.0)
		return ((unsigned)(*e = 0));
	fNorm = f;
	shift = 0;
	while(fNorm >= 2.0)
	{
		fNorm /= 2.0;
		shift++;
	}
	while(fNorm < 1.0)
	{
		fNorm *= 2.0;
		shift--;
	}
	fNorm = fNorm - 1.0;
	significand = (unsigned long long)(fNorm * ((1LL << signBits) + 0.5f));
	*e = shift;
	return (significand);
}

static char 		*get_exponent(int e, t_conversion *c)
{
	char	*result;
	char	*postfix;

	postfix = (c->type == 'x') ? "p" : "P";
	result = ft_itoa_base(e, 10);
	if (result[0] != '-')
		result = ft_strjoin_free("+", result, SECOND);
	result = ft_strjoin_free(postfix, result, SECOND);
	return (result);
}

static char			*get_prefix(long double nbr, t_conversion *c, char *str)
{
	char	*prefix;

	prefix = (nbr == 0.0) ? "0" : "1";
	if (c->precision > 0 || str[0])
		prefix = ft_strjoin(prefix, ".");
	if (c->type == 'x')
		prefix = ft_strjoin("0x", prefix);
	else
		prefix = ft_strjoin("0X", prefix);
	return (prefix);
}

static char			*add_precision(char *str, t_conversion *c)
{
	int		len;

	len = (int)ft_strlen(str);
	if (c->precision > len)
		str = strjoinchr(str, '0', c->precision - len, END);
	else if (c->precision < len)
		str = ft_strcut(str, c->precision);
	return (str);
}

char				*handle_a(long double nbr, t_conversion *c)
{
	unsigned long long	hex;
	int					sign;
	char 				*str;
	int					e;

	sign = 0;
	c->type += ('x' - 'a');
	if (nbr < 0 || (1 / nbr) < 0)
	{
		nbr = -nbr;
		sign = 1;
	}
	if (nbr == INFINITY || nbr != nbr)
		return (infin(nbr, c, sign));
	if (nbr == 0.0)
		c->precision = 0;
	hex = ftohex(nbr, 64, 11, &e);
	str = utoa_base(hex, 16, (char)c->type, 0);
	str = round_cut(str);
	str = add_precision(str, c);
	str = ft_strjoin_free(get_prefix(nbr, c, str), str, SECOND);
	str = ft_strjoin_free(str, get_exponent(e, c), BOTH);
	if (sign)
		str = ft_strjoin_free("-", str, SECOND);
	return (str);
}