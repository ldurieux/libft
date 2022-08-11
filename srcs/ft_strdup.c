#include "libft.h"

char	*ft_strdup(const char* src)
{
	char	*res;
	t_size	src_len;

	src_len = ft_strlen(src);
	res = malloc(sizeof(char) * (src_len + 1));
	if (!res)
		return (NULL);
	ft_memcpy(res, src, src_len);
	res[src_len] = '\0';
	return (res);
}
