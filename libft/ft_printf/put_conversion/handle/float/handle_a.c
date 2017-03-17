#include <printf.h>
#include "float.h"

unsigned long long	ftohex(long double f, unsigned bits, unsigned eBits)
{
	long double	fNorm;
	int			shift;
	long long	exp;
	long long	significand;
	unsigned	signBits;

	signBits = bits - eBits - 1;
	if (f == 0.0)
		return 0;
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
	significand = fNorm * ((1LL << signBits) + 0.5f);
	exp = shift + ((1 << (eBits- 1)) - 1);
	return (exp << (bits-eBits-1)) | significand;
}

char 				*get_exponent(char *exp, int sign, t_conversion *c)
{
	char	*result;
	char	*postfix;
	int		e;

	postfix = (c->type == 'x') ? "p" : "P";
	e = ((int)ft_atoi_base(exp, 16));
	if (exp[0] != '0' && sign)
		e -= 4095;
	if (exp[0] != '0')
		e -= 1023;
	result = ft_itoa_base(e, 10);
	if (result[0] != '-')
		result = ft_strjoin_free("+", result, SECOND);
	result = ft_strjoin_free(postfix, result, SECOND);
	free(exp);
	return (result);
}

char				*get_prefix(long double nbr, t_conversion *c, char *str)
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

char				*hextoa(char *str, int sign, t_conversion *c, long double nbr)
{
	char	*prefix;
	char	*exp;
	char	*tmp;
	int 	len;

	tmp = str;
	str = ft_strdup(str + HEX_PREF_SIZE);
	str = round_cut(str);
	prefix = get_prefix(nbr, c, str);
	len = (int)ft_strlen(str);
	if (c->precision > len)
		str = strjoinchr(str, '0', c->precision - len, END);
	else if (c->precision < len)
		str = ft_strcut(str, c->precision);
	exp = ft_strcut(tmp, HEX_PREF_SIZE);
	str = ft_strjoin_free(prefix, str, SECOND);
	exp = get_exponent(exp, sign, c);
	str = ft_strjoin_free(str, exp, BOTH);
	if (sign)
		str = ft_strjoin_free("-", str, SECOND);
	return (str);
}

char				*handle_a(long double nbr, t_conversion *c)
{
	unsigned long long	hex;
	int					sign;
	char 				*str;

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
	hex = ftohex(nbr, 64, 11);
	str = utoa_base(hex, 16, c->type, 0);
	return (hextoa(str, sign, c, nbr));
}
