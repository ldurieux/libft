#include "libft.h"

char	*ft_strsimplified(char *str)
{
	t_size	to_idx;
	t_size	from_idx;

	str = ft_strtrimmed(str);
	from_idx = 0;
	to_idx = 0;
	while (str[from_idx])
	{
		if (ft_is_whitespace(str[from_idx]))
		{
			while (ft_is_whitespace(str[from_idx]))
				from_idx++;
			str[to_idx++] = ' ';
		}
		str[to_idx++] = str[from_idx++];
	}
	str[to_idx] = '\0';
	return (str);
}
