#include "float.h"

static void 	rounder2(int e, int i, t_arrays *arrays)
{
	*(arrays->d) = *(arrays->d) + i;
	while (*(arrays->d) > 999999999)
	{
		*(arrays->d)-- = 0;
		(*(arrays->d))++;
	}
	if (arrays->d < arrays->a)
		arrays->a = arrays->d;
	for (i = 10, e = 9 * (arrays->r - arrays->a); *arrays->a >= i; i *= 10, e++);
}

static void		rounder1(int i, t_arrays *arrays, uint32_t x, t_indecies *indecies)
{
	long double	round;
	long double	small;

	round = CONCAT(0x1p,LDBL_MANT_DIG);
	if (*(arrays->d) / i & 1)
		round += 2;
	if (x < i / 2)
		small = 0x0.8p0;
	else if (x == i / 2 && arrays->d + 1 == arrays->z)
		small = 0x1.0p0;
	else
		small = 0x1.8p0;
	if (indecies->pl && *(indecies->prefix) == '-')
	{
		round *= -1;
		small *= -1;
	}
	*(arrays->d) -= x;
	if (round + small != round)
		rounder2(indecies->e, i, arrays);
}

void			rounder(int p, int t, t_arrays *arrays, t_indecies *indecies)
{
	int			i;
	int			j;
	uint32_t	x;

	j = p - ((t | 32) != 'f') * indecies->e - ((t | 32) =='g' && p);
	if (j < 9 * (arrays->z - arrays->r - 1))
	{
		arrays->d = arrays->r + 1 + (j + 9 * LDBL_MAX_EXP) / 9 - LDBL_MAX_EXP;
		j += 9 * LDBL_MAX_EXP;
		j %= 9;
		j++;
		i = 10;
		while (j < 9)
		{
			i *= 10;
			j++;
		}
		x = *(arrays->d) % i;
		if (x || arrays->d + 1 != arrays->z)
			rounder1(i, arrays, x, indecies);
		if (arrays->z > arrays->d + 1)
			arrays->z = arrays->d + 1;
		while (!arrays->z[-1] && arrays->z > arrays->a)
			arrays->z--;
	}
}