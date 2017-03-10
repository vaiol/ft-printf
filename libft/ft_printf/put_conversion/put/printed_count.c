#include "put.h"

int		printed_count(void)
{
	int	count;

	count = (int)g_count;
	g_count = 0;
	return (count);
}
