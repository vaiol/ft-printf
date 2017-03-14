#include "float.h"

/*
** re-writen original frexpl function from math.h
*/

long double ft_frexpl(long double value, int *e)
{
	long double mantissa;
	int			exponent;
	int 		sign;

	mantissa = 0;
	if (value == 0.0 || value == -0.0)
	{
		return mantissa;
	}
	mantissa = value;
	exponent = 0;
	sign = 1;
	if (mantissa < 0.0)
	{
		sign--;
		mantissa = -(mantissa);
	}
	while (mantissa < 0.5)
	{
		mantissa *= 2.0;
		exponent -= 1;
	}
	while (mantissa >= 1.0)
	{
		mantissa *= 0.5;
		exponent++;
	}
	mantissa *= sign;
	*e = exponent;
	return (mantissa);
}
