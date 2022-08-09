#include "libft.h"

char	*ft_strtrimmed_lead(char *str)
{
	while (ft_is_whitespace(*str))
		str++;
	return (str);
}

char	*ft_strtrimmed_trail(char *str)
{
	t_size	len;
	t_size	i;

	len = ft_strlen(str);
	i = len - 1;
	while (i > 0 && ft_is_whitespace(str[i]))
		i--;
	if (i == 0 && ft_is_whitespace(str[i]))
		str[i] = '\0';
	else if (i != len - 1)
		str[i + 1] = '\0';
	return (str);
}

char	*ft_strtrimmed(char *str)
{
	str = ft_strtrimmed_lead(str);
	str = ft_strtrimmed_trail(str);
	return (str);
}
