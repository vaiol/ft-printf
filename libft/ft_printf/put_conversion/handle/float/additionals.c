#include "float.h"

void	out(char **sp, const char *s, size_t l)
{
	while (l--) {
		**sp = *s;
		(*sp)++;
		s++;
	}
}

void	pad(char **sp, char c, int w, int l)
{
	char pad[FLOAT_SIZE];

	if (l >= w)
		return;
	l = w - l;
	ft_memset(pad, c, l > (int)sizeof(pad) ? sizeof(pad) : (size_t)l);
	while (l >= (int)sizeof(pad))
	{
		out(sp, pad, sizeof pad);
		l -= (int)sizeof(pad);
	}
	out(sp, pad, (size_t)l);
}

char	*fmt_unsigned(uintmax_t x, char *s)
{
	unsigned long	y;

	while (x > ULONG_MAX)
	{
		*(--s) = (char)('0' + x % 10);
		x /= 10;
	}
	y = x;
	while (y)
	{
		*(--s) = (char)('0' + y % 10);
		y /= 10;
	}
	return (s);
}

char	*fmt_base(uintmax_t x, char *s, int base)
{
	unsigned long	y;

	while (x > ULONG_MAX)
	{
		*(--s) = (char)('0' + x % base);
		x /= base;
	}
	y = x;
	while (y)
	{
		*(--s) = (char)('0' + y % base);
		y /= base;
	}
	return (s);
}

int		infinite(long double nbr, int t, char *sp, t_indecies *i)
{
	if (nbr == INFINITY || nbr != nbr)
	{
		char *s = (t & 32) ? "inf\0" : "INF\0";
		if (nbr != nbr)
			s = (t & 32) ? "nan\0" : "NAN\0", i->pl = 0;
		out(&sp, i->prefix, (size_t)i->pl);
		out(&sp, s, 4);
		return (1);
	}
	return (0);
}
