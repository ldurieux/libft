#include "libft.h"

void	*ft_calloc(t_size count, t_size size)
{
	void		*res;
	char		*c_ptr;
	t_uint64	*i_ptr;
	t_size		mem_size;

	mem_size = count * size;
	res = malloc(mem_size);
	if (!res)
		return (NULL);
	i_ptr = (t_uint64 *) res;
	while (mem_size > 7)
	{
		*i_ptr++ = 0;
		mem_size -= 8;
	}
	c_ptr = (char *) i_ptr;
	while (mem_size-- > 0)
		*c_ptr++ = 0;
	return (res);
}
