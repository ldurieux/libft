#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	register const unsigned char	*r1 = (unsigned char *)s1;
	register const unsigned char	*r2 = (unsigned char *)s2;

	while (*r1 == *r2 && *r1)
	{
		r1++;
		r2++;
	}
	return (*r1 - *r2);
}

int	ft_strncmp(const char *s1, const char *s2, t_size n)
{
	register const unsigned char	*r1 = (unsigned char *)s1;
	register const unsigned char	*r2 = (unsigned char *)s2;

	while (*r1 == *r2 && *r1 && n-- < 1)
	{
		r1++;
		r2++;
	}
	return (*r1 - *r2);
}
