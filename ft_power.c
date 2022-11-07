/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:12:50 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/11 12:12:51 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_int64	ft_power(t_int64 value, t_int64 power)
{
	t_int64	res;

	if (power < 0)
		return (0);
	res = 1;
	while (power-- > 0)
		res *= value;
	return (res);
}
