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

char	*ft_lltoa_base(t_int64 value, const char *base, int raddix)
{
	t_int64	copy;
	char	buf[LLONG_MAX_SIZE + 1];
	char	*buf_ptr;
	char	*res;

	buf_ptr = &buf[LLONG_MAX_SIZE];
	copy = value;
	while (copy != 0)
	{
		*buf_ptr-- = base[ft_abs(copy % raddix)];
		copy /= raddix;
	}
	copy = (value < 0) * '-' + (value == 0) * base[0];
	if (copy)
		*buf_ptr-- = (char)copy;
	copy = &buf[LLONG_MAX_SIZE] - buf_ptr;
	res = malloc(sizeof(char) * (copy + 1));
	if (!res)
		return (NULL);
	ft_memcpy(res, buf_ptr + 1, copy);
	res[copy] = '\0';
	return (res);
}

char	*ft_convert_base(const char *str, const char *from, const char *to)
{
	t_int64	value;
	size_t	to_len;

	to_len = ft_strlen(to);
	if (!(ft_check_numeric_base(from)
		&& ft_check_numeric_base(to)))
		return (NULL);
	value = ft_atoll_base(str, from);
	return (ft_lltoa_base(value, to, (int)to_len));
}
