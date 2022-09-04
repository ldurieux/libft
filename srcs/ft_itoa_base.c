/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 20:09:07 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/18 20:09:08 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define INT_MAX_SIZE 10
#define LONG_MAX_SIZE 19
#define LLONG_MAX_SIZE 19

static inline char	*make_res(char *buf_ptr, long long tmp)
{
	char	*res;

	res = malloc(sizeof(char) * (tmp + 1));
	if (!res)
		return (NULL);
	ft_memcpy(res, buf_ptr + 1, tmp);
	res[tmp] = '\0';
	return (res);
}

char	*ft_itoa_base(int value, const char *base)
{
	int		tmp;
	char	buf[INT_MAX_SIZE + 1];
	char	*buf_ptr;
	size_t	raddix;

	if (!base || !ft_check_numeric_base(base))
		return (NULL);
	raddix = ft_strlen(base);
	buf_ptr = &buf[INT_MAX_SIZE];
	tmp = value;
	while (tmp != 0)
	{
		*buf_ptr-- = base[ft_abs(tmp % (t_int64)raddix)];
		tmp /= (int)raddix;
	}
	tmp = (value < 0) * '-' + (value == 0) * base[0];
	if (tmp)
		*buf_ptr-- = (char)tmp;
	tmp = (int)(&buf[INT_MAX_SIZE] - buf_ptr);
	return (make_res(buf_ptr, tmp));
}

char	*ft_ltoa_base(long value, const char *base)
{
	long	tmp;
	char	buf[LONG_MAX_SIZE + 1];
	char	*buf_ptr;
	size_t	raddix;

	if (!base || !ft_check_numeric_base(base))
		return (NULL);
	raddix = ft_strlen(base);
	buf_ptr = &buf[LONG_MAX_SIZE];
	tmp = value;
	while (tmp != 0)
	{
		*buf_ptr-- = base[ft_abs(tmp % (t_int64)raddix)];
		tmp /= (long)raddix;
	}
	tmp = (value < 0) * '-' + (value == 0) * base[0];
	if (tmp)
		*buf_ptr-- = (char)tmp;
	tmp = (long)(&buf[LONG_MAX_SIZE] - buf_ptr);
	return (make_res(buf_ptr, tmp));
}

char	*ft_lltoa_base(long long value, const char *base)
{
	long long	tmp;
	char		buf[LLONG_MAX_SIZE + 1];
	char		*buf_ptr;
	size_t		raddix;

	if (!base || !ft_check_numeric_base(base))
		return (NULL);
	raddix = ft_strlen(base);
	buf_ptr = &buf[LLONG_MAX_SIZE];
	tmp = value;
	while (tmp != 0)
	{
		*buf_ptr-- = base[ft_abs(tmp % (t_int64)raddix)];
		tmp /= (long long)raddix;
	}
	tmp = (value < 0) * '-' + (value == 0) * base[0];
	if (tmp)
		*buf_ptr-- = (char)tmp;
	tmp = (long long)(&buf[LLONG_MAX_SIZE] - buf_ptr);
	return (make_res(buf_ptr, tmp));
}
