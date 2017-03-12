#include "float.h"

void	parse_int(t_indecies *indecies, t_arrays *arrays)
{
	int			sh;
	uint64_t	x;
	uint32_t	carry;

	while (indecies->e2 > 0)
	{
		carry = 0;
		sh = MIN(29, indecies->e2);
		arrays->d = arrays->z - 1;
		while (arrays->d >= arrays->a)
		{
			x = ((uint64_t)*(arrays->d) << sh) + carry;
			*(arrays->d) = (uint32_t)(x % 1000000000);
			carry = (uint32_t)(x / 1000000000);
			arrays->d--;
		}
		if (!arrays->z[-1] && arrays->z > arrays->a)
			arrays->z--;
		if (carry)
			*--(arrays->a) = carry;
		indecies->e2 -= sh;
	}
}

void	parse_fract(t_indecies *indecies, t_arrays *arrays, int t, int p)
{
	uint32_t	carry;
	uint32_t	*z2;
	uint32_t	rm;

	while (indecies->e2 < 0)
	{
		carry =0;
		int sh = MIN(9, -indecies->e2);
		arrays->d = arrays->a;
		while (arrays->d < arrays->z)
		{
			rm = *(arrays->d) & (1 << sh) - 1;
			*(arrays->d) = (*(arrays->d) >> sh) + carry;
			carry = (1000000000 >> sh) * rm;
			arrays->d++;
		}
		if (!*(arrays->a))
			arrays->a++;
		if (carry)
			*(arrays->z)++ = carry;
		z2 = ((t | 32) == 'f' ? arrays->r : arrays->a) + 2 + p / 9;
		arrays->z = MIN(arrays->z, z2);
		indecies->e2 += sh;
	}
}

