# include "handle.h"

int		nbrlen(int nbr)
{
	int len;

	if (nbr == 0)
		return (1);
	len = 0;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

#define K 6

double ft_pow(double base, double ex);

double nth_root(double A, int n)
{
	int 	k;
	double	x[K];

	x[0] = 1;
	k = 0;
	while (k < K - 1)
	{
		x[k + 1] = (1.0 / n) * ((n - 1) * x[k] + A / ft_pow(x[k], n - 1));
		k++;
	}
	return x[K - 1];
}

double ft_pow(double base, double ex)
{
	double half_pow;

	if (base == 0)
		return 0;
	if (ex == 0)
		return 1;
	else if (ex < 0)
		return (1 / ft_pow(base, -ex));
	else if (ex > 0 && ex < 1)
		return nth_root(base, (int)(1 / ex));
	else if ((int)ex % 2 == 0)
	{
		half_pow = ft_pow(base, ex / 2);
		return half_pow * half_pow;
	}
	else
		return base * ft_pow(base, ex - 1);
}

int 	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int		put_exponent(char *e_buffer, int exponent)
{
//	int		i;
//	int	frst;
//
//	i = e_count;
//	while (i > 0)
//	{
//		e_buffer[*e_index] = exponent
//		frst = (int)ft_abs((int)(exponent / ft_pow(10.0, i - 1)));
//		e_buffer[*e_index] = (char)((frst % 10) + 48);
//		(*e_index)++;
//		i--;
//	}
	char 	*tmp;
	int 	i;

	tmp = ft_itoa_base(exponent, 10);
	i = 0;
	while (tmp[i])
	{
		e_buffer[i] = tmp[i];
		i++;
	}
	free(tmp);
	return (i);
}

void	put_fraction(char *e_buffer, int index, int precision, double nbr)
{
	int		i;
	double	exponent;
	int		valueFloat;

	exponent = (double)abs((int)nbr);
	if(precision > 0)
	{
		e_buffer[index++] = '.';
		i = 1;
		while (i <= precision)
		{
			valueFloat = (int)((nbr - exponent) * ft_pow(10.0, i));
			e_buffer[index] = (char)(((valueFloat) % 10) + 48);
			index++;
			i++;
		}
	}
}

void	addout(char *out, int index)
{
	if (out[index] == '.')
	{
		addout(out, index - 1);
		return ;
	}
	if (out[index] == '9')
	{
		addout(out, index - 1);
		out[index] = '0';
		return ;
	}
	out[index]++;
}

void	ft_round(char *str, int index)
{
	if (str[index] >= '5')
	{
		addout(str, index - 1);
	}
}



char	*handle_float(double nbr, int precision)
{
	int	exponent;
	char	*e_buffer;
	int		e_count;
	int 	i;
	int j;
	if(nbr < 0)
	{
		nbr = -nbr;
		j = 0;
	}
	exponent = ft_abs((int)nbr);
	e_count = nbrlen(exponent);
	e_buffer = malloc(sizeof(char) * (e_count + (++precision) + 2));
	i = put_exponent(e_buffer, exponent);
	put_fraction(e_buffer, i, precision, nbr);
	i = 0;
	if(precision > 0)
		i = 1;
	ft_round(e_buffer, e_count + precision + i - 1);
	precision = precision == 1 ? 0 : precision;
	e_buffer[e_count + precision + i - 1] = '\0';
	if(j == 0)
		e_buffer = ft_strjoin("-", e_buffer);
	return (e_buffer);
}
