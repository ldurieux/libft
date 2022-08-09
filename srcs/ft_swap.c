#include "libft.h"

void	ft_swap(void *a, void *b, t_size size)
{
	void *tmp;

	tmp = malloc(size);
	ft_memcpy(tmp, a, size);
	ft_memcpy(a, b, size);
	ft_memcpy(b, tmp, size);
	free(tmp);
}
