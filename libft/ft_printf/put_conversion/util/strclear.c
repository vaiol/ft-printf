#include "util.h"

char	*strclear(char *str)
{
	free(str);
	return (ft_strdup(""));
}
