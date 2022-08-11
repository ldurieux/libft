/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:12:43 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/11 12:12:44 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_uint64	ft_factorial(t_int64 value)
{
	t_int64		i;
	t_uint64	res;

	if (value < 0)
		return (0);
	res = 1;
	i = 1;
	while (++i <= value)
		res *= i;
	return (res);
}
