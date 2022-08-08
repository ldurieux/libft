#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	t_size	i;

	while (*haystack)
	{
		i = 0;
		while (haystack[i] == needle[i] && haystack[i])
			i++;
		if (!needle[i])
			return (haystack);
		haystack++;
	}
	return (NULL);
}
