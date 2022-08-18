#include "libft.h"

t_bool	ft_check_numeric_base(const char *base)
{
	t_size	len;

	len = ft_strlen(base);
	if (len < 2)
		return (0);
	while (*base)
	{
		if (*base == '-' || *base == '+' || ft_is_whitespace(*base))
			return (0);
		if (ft_strchr(base + 1, *base))
			return (0);
		base++;
	}
	return (1);
}
