#include "float.h"

void	out(char **sp, const char *s, size_t l)
{
	while (l--) {
		**sp = *s;
		(*sp)++;
		s++;
	}
}

void	pad(char **sp, char c, int w, int l, int fl)
{
	char pad[256];

	if (fl & (LEFT_ADJ | ZERO_PAD) || l >= w) return;
	l = w - l;
	memset(pad, c, l>sizeof pad ? sizeof pad : l);
	for (; l >= sizeof pad; l -= sizeof pad)
		out(sp, pad, sizeof pad);
	out(sp, pad, l);
}

char	*fmt_u(uintmax_t x, char *s)
{
	unsigned long	y;

	while (x > ULONG_MAX)
	{
		*--s = '0' + x % 10;
		x/=10;
	}
	y = x;
	while (y)
	{
		*--s = '0' + y % 10;
		y /= 10;
	}
	return s;
}

int infinite(long double nbr, int t, char *sp, t_indecies *indecies)
{
	if (nbr == INFINITY || nbr != nbr)
	{
		char *s = (t & 32) ? "inf\0" : "INF\0";
		if (nbr != nbr)
			s = (t & 32) ? "nan\0" : "NAN\0", indecies->pl = 0;
		out(&sp, indecies->prefix, indecies->pl);
		out(&sp, s, 4);
		return (1);
	}
	return (0);
}
