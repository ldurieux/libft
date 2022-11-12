/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 19:58:51 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/18 19:58:52 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_base(const char *str, const char *base)
{
	int			res;
	ptrdiff_t	digit;
	int			sign;
	size_t		raddix;

	if (!str || !base)
		return (0);
	res = 0;
	sign = 1;
	raddix = ft_strlen(base);
	while (ft_is_whitespace(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (1)
	{
		digit = (ptrdiff_t)ft_strchr(base, *str++);
		if (!digit)
			break ;
		digit -= (ptrdiff_t)base;
		res = (int)(res * raddix + digit);
	}
	return (res * sign);
}

long	ft_atol_base(const char *str, const char *base)
{
	long		res;
	ptrdiff_t	digit;
	int			sign;
	size_t		raddix;

	if (!str || !base)
		return (0);
	res = 0;
	sign = 1;
	raddix = ft_strlen(base);
	while (ft_is_whitespace(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (1)
	{
		digit = (ptrdiff_t)ft_strchr(base, *str++);
		if (!digit)
			break ;
		digit -= (ptrdiff_t)base;
		res = (long)(res * raddix + digit);
	}
	return (res * sign);
}

long long	ft_atoll_base(const char *str, const char *base)
{
	long long	res;
	ptrdiff_t	digit;
	int			sign;
	size_t		raddix;

	if (!str || !base)
		return (0);
	res = 0;
	sign = 1;
	raddix = ft_strlen(base);
	while (ft_is_whitespace(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (1)
	{
		digit = (ptrdiff_t)ft_strchr(base, *str++);
		if (!digit)
			break ;
		digit -= (ptrdiff_t)base;
		res = (long long)(res * raddix + digit);
	}
	return (res * sign);
}
