#include "float.h"

static void	handle_g2(t_indecies *indecies)
{
	indecies->i *= 10;
	indecies->j++;
}

void		handle_g(int *p, t_arrays *arrays, int *t, t_indecies *indecies)
{
	if (!(*p))
		(*p)++;
	if ((*p) > indecies->e && indecies->e >= -4)
	{
		(*t)--;
		(*p) -= indecies->e + 1;
	}
	else
	{
		(*t) -= 2;
		(*p)--;
	}
	if (arrays->z > arrays->a && arrays->z[-1])
	{
		indecies->i = 10;
		indecies->j = 0;
		while ((arrays->z[-1] % indecies->i) == 0)
			handle_g2(indecies);
	}
	else
		indecies->j = 9;
	if (((*t) | 32) == 'f')
		(*p) = MIN((*p),MAX(0, 9 * (arrays->z - arrays->r - 1) - indecies->j));
	else
		(*p) = MIN((*p), MAX(0, 9 * (arrays->z - arrays->r - 1) + indecies->e - indecies->j));
}

void 		handle_f(t_arrays *arrays, int p, t_bufs *bufs)
{
	if (arrays->a > arrays->r)
		arrays->a = arrays->r;
	for (arrays->d = arrays->a; arrays->d <= arrays->r; arrays->d++)
	{
		char *s = fmt_u(*(arrays->d), bufs->buf + 9);
		if (arrays->d != arrays->a)
		{
			while (s > bufs->buf)
				*--s = '0';
		}
		else if (s == bufs->buf + 9)
			*--s='0';
		out(&(arrays->copy), s, bufs->buf + 9 - s);
	}
	if (p)
		out(&(arrays->copy), ".", 1);
	for (; arrays->d < arrays->z && p>0; arrays->d++, p-=9)
	{
		char *s = fmt_u(*(arrays->d), bufs->buf + 9);
		while (s > bufs->buf)
			*--s='0';
		out(&(arrays->copy), s, MIN(9, p));
	}
	pad(&(arrays->copy), '0', p + 9, 9, 0);
}

void 		handle_e(t_arrays *arrays, int p, char *estr, t_bufs *bufs)
{
	if (arrays->z <= arrays->a)
		arrays->z = arrays->a + 1;
	for (arrays->d = arrays->a; arrays->d < arrays->z && p>=0; arrays->d++)
	{
		char *s = fmt_u(*(arrays->d), bufs->buf + 9);
		if (s == bufs->buf + 9)
			*--s='0';
		if (arrays->d != arrays->a)
		{
			while (s > bufs->buf)
				*--s='0';
		}
		else
		{
			out(&(arrays->copy), s++, 1);
			if (p > 0)
				out(&(arrays->copy), ".", 1);
		}
		out(&(arrays->copy), s, MIN(bufs->buf + 9 - s, p));
		p -= bufs->buf + 9 - s;
	}
	pad(&(arrays->copy), '0', p+18, 18, 0);
	out(&(arrays->copy), estr, bufs->ebuf - estr);
}