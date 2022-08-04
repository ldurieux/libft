#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef unsigned long long	t_size;
typedef unsigned long long	t_uint64;

void	ft_putstr(char *str);

t_size	ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);

void	*ft_memcpy(void *dst, const void *src, t_size len);

#endif
