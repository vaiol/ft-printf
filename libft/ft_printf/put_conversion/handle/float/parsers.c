#include "float.h"

void	parse_int(t_indecies *i, t_arrays *a)
{
	int			sh;
	uint64_t	x;
	uint32_t	carry;

	while (i->e2 > 0)
	{
		carry = 0;
		sh = MIN(29, i->e2);
		a->d = a->z - 1;
		while (a->d >= a->a)
		{
			x = ((uint64_t)*(a->d) << sh) + carry;
			*(a->d) = (uint32_t)(x % 1000000000);
			carry = (uint32_t)(x / 1000000000);
			a->d--;
		}
		if (!a->z[-1] && a->z > a->a)
			a->z--;
		if (carry)
			*--(a->a) = carry;
		i->e2 -= sh;
	}
}

void	parse_fract(t_indecies *i, t_arrays *a, int t, int p)
{
	uint32_t	carry;
	uint32_t	*z2;
	uint32_t	rm;
	int			sh;

	while (i->e2 < 0)
	{
		carry =0;
		sh = MIN(9, -i->e2);
		a->d = a->a;
		while (a->d < a->z)
		{
			rm = *(a->d) & (1 << sh) - 1;
			*(a->d) = (*(a->d) >> sh) + carry;
			carry = (1000000000 >> sh) * rm;
			a->d++;
		}
		if (!*(a->a))
			a->a++;
		if (carry)
			*(a->z)++ = carry;
		z2 = ((t | 32) == 'f' ? a->r : a->a) + 2 + p / 9;
		a->z = MIN(a->z, z2);
		i->e2 += sh;
	}
}
