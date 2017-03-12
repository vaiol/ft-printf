#include "float.h"

void 	pre_parse(long double *nbr, t_arrays *arrays)
{
	int i;

	i = 1;
	while (i || *nbr)
	{
		*(arrays->z) = *nbr;
		*nbr = 1000000000 * ((*nbr) - *(arrays->z)++);
		i = 0;
	};
}

void	post_parse(t_arrays *arrays, t_indecies *indecies)
{
	if (arrays->a < arrays->z)
	{
		indecies->i = 10;
		indecies->e = 9 * (arrays->r - arrays->a);
		while (*arrays->a >= indecies->i)
		{
			indecies->i *= 10;
			indecies->e++;
		}
	}
	else
		indecies->e = 0;
}

int 	init(long double *nbr, t_arrays *arrays, int t, t_indecies **indecies)
{
	*indecies = (t_indecies *) malloc(sizeof(t_indecies));
	(*indecies)->prefix = "-0X+0X 0X-0x+0x 0x";
	(*indecies)->e2 = 0;
	(*indecies)->pl = 1;
	if ((*nbr) < 0 || 1 / (*nbr) < 0)
		(*nbr) = -(*nbr);
	else
	{
		(*indecies)->prefix++;
		(*indecies)->pl = 0;
	}
	if (infinite(*nbr, t, arrays->copy, *indecies))
		return (1);
	(*nbr) = frexpl(*nbr, &((*indecies)->e2)) * 2;
	if (*nbr)
	{
		(*indecies)->e2--;
		(*nbr) *= 0x1p28;
		(*indecies)->e2 -= 28;
	}
	return (0);
}

void	ftoa(char *outstr, long double nbr, int p, int t)
{
	uint32_t	big[(LDBL_MAX_EXP + LDBL_MANT_DIG) / 9 + 1];
	t_arrays	*arrays;
	t_indecies	*indecies;

	arrays = (t_arrays *) malloc(sizeof(t_arrays));
	arrays->copy = outstr;
	if (init(&nbr, arrays, t, &indecies))
		return;
	if (indecies->e2 < 0)
		arrays->a = arrays->r = arrays->z = big;
	else
		arrays->a = arrays->r = arrays->z = big + sizeof(big) / sizeof(*big) - LDBL_MANT_DIG - 1;
	p = p < 0 ? 6 : p;
	pre_parse(&nbr, arrays);
	parse_int(indecies, arrays);
	parse_fract(indecies, arrays, t, p);
	post_parse(arrays, indecies);
	rounder(p, t, arrays, indecies);
	if ((t | 32) == 'g')
		handle_g(&p, arrays, &t, indecies);
	next_function(indecies, arrays, p, t);
}

void 	next_function(t_indecies *indecies, t_arrays *arrays, int p, int t)
{
	t_bufs	*bufs;
	char	*estr;

	bufs = (t_bufs *)malloc(sizeof(t_bufs));
	bufs->ebuf = &(bufs->ebuf0[sizeof(int) * 3]);
	if ((t | 32) != 'f')
	{
		estr = fmt_u(indecies->e < 0 ? -(indecies->e) : indecies->e, bufs->ebuf);
		while (bufs->ebuf-estr < 2)
			*--estr='0';
		*--estr = (indecies->e < 0 ? '-' : '+');
		*--estr = t;
	}
	out(&(arrays->copy), indecies->prefix, indecies->pl);
	if ((t|32) == 'f')
		handle_f(arrays, p, bufs);
	else
		handle_e(arrays, p, estr, bufs);
	*(arrays->copy) = 0;
}
