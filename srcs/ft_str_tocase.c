#include "libft.h"

/*return -1 if chr is a lowercase letter
 *		  1 if chr is an uppercase letter
 *		  0 otherwise
*/
static inline int	ft_is_letter(const char chr)
{
	return ((chr >= 'a' && chr <= 'z') * -1 + (chr >= 'A' && chr <= 'Z'));
}

static inline t_bool	ft_is_alphanum(const char chr)
{
	return (ft_is_letter(chr) || (chr >= '0' && chr <= '9'));
}

char	*ft_str_tolowcase(char *str)
{
	t_size	i;

	i = 0;
	while (str[i])
	{
		if (ft_is_letter(str[i]) == 1)
			str[i] += 32;
		i++;
	}
	return (str);
}

char	*ft_str_toupcase(char *str)
{
	t_size	i;

	i = 0;
	while (str[i])
	{
		if (ft_is_letter(str[i]) == -1)
			str[i] -= 32;
		i++;
	}
	return (str);
}

char	*ft_str_capitalize(char *str)
{
	t_bool	first_letter;
	t_size	i;
	int		is_letter;

	first_letter = 1;
	i = 0;
	while (str[i])
	{
		if (ft_is_alphanum(str[i]))
		{
			is_letter = ft_is_letter(str[i]);
			if (is_letter == -1 && first_letter)
				str[i] -= 32;
			else if (is_letter == 1 && !first_letter)
				str[i] += 32;
			first_letter = 0;
		}
		else
			first_letter = 1;
		i++;
	}
	return (str);
}
