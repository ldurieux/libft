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

char	*ft_convert_base(const char *str, const char *from, const char *to)
{
	t_int64	value;

	if (!str || !from || !to)
		return (NULL);
	if (!(ft_check_numeric_base(from) && ft_check_numeric_base(to)))
		return (NULL);
	value = ft_atoll_base(str, from);
	return (ft_lltoa_base(value, to));
}
