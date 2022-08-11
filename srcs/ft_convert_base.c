/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:12:40 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/11 12:12:42 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define LLONG_MAX_SIZE 64

static inline t_int64	ft_chr_index(const char *str, const char chr)
{
	t_int64	index;

	index = -1;
	while (str[++index])
		if (str[index] == chr)
			return (index);
	return (-1);
}

long long	ft_atoll_base(const char *str, const char *base, int raddix)
{
	long long	res;
	t_int64		digit;
	int			sign;

	res = 0;
	sign = 1;
	while (ft_is_whitespace(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (1)
	{
		digit = ft_chr_index(base, *str++);
		if (digit == -1)
			break ;
		res = res * raddix + digit;
	}
	return (res * sign);
}

char	*ft_lltoa_base(long long value, const char *base, int raddix)
{
	long long	copy;
	char		buf[LLONG_MAX_SIZE + 1];
	char		*buf_ptr;
	char		*res;

	buf_ptr = &buf[LLONG_MAX_SIZE];
	copy = value;
	while (copy != 0)
	{
		*buf_ptr-- = base[ft_abs(copy % raddix)];
		copy /= raddix;
	}
	copy = (value < 0) * '-' + (value == 0) * base[0];
	if (copy)
		*buf_ptr-- = copy;
	copy = &buf[LLONG_MAX_SIZE] - buf_ptr;
	res = malloc(sizeof(char) * (copy + 1));
	if (!res)
		return (NULL);
	ft_memcpy(res, buf_ptr + 1, copy);
	res[copy] = '\0';
	return (res);
}

t_bool	ft_check_base(const char *base, size_t len)
{
	if (len < 2)
		return (0);
	while (*base)
	{
		if (*base == '-' || *base == '+' || ft_is_whitespace(*base))
			return (0);
		if (ft_chr_index(base + 1, *base) != -1)
			return (0);
		base++;
	}
	return (1);
}

char	*ft_convert_base(const char *str, const char *from, const char *to)
{
	long long	value;
	size_t		from_len;
	size_t		to_len;

	from_len = ft_strlen(from);
	to_len = ft_strlen(to);
	if (!(ft_check_base(from, from_len) && ft_check_base(to, to_len)))
		return (NULL);
	value = ft_atoll_base(str, from, from_len);
	return (ft_lltoa_base(value, to, to_len));
}
