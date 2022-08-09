#include "libft.h"

t_int64	ft_power(t_int64 value, t_int64 power)
{
	t_int64	res;

	if (power < 0)
		return (0);
	res = 1;
	while (power-- > 0)
		res *= value;
	return (res);
}
