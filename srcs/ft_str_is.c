#include "libft.h"

t_bool	ft_str_iswhitespace(const char *str)
{
	t_size	i;

	i = 0;
	while (str[i])
		if (!ft_is_whitespace(str[i++]))
			return (0);
	return (1);
}

t_bool	ft_str_isalphanum(const char *str)
{
	t_size	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= 'A' && str[i] <= 'Z')
				|| (str[i] >= '0' && str[i] <= '9')))
			return (0);
		i++;
	}
	return (1);
}

t_bool	ft_str_isletter(const char *str)
{
	t_size	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= 'A' && str[i] <= 'Z')))
			return (0);
		i++;
	}
	return (1);
}

t_bool	ft_str_isdigit(const char *str)
{
	t_size	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

t_bool	ft_str_isprintable(const char *str)
{
	t_size	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] >= 127)
			return (0);
		i++;
	}
	return (1);
}
