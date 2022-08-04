#include "../includes/libft.h"

void	ft_putstr(char *str)
{
	t_size len;

	len = ft_strlen(str);
	write(1, str, len);
}
