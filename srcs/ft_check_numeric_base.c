/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_numeric_base.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 19:58:53 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/18 19:58:54 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_check_numeric_base(const char *base)
{
	size_t	len;

	if (!base)
		return (0);
	len = ft_strlen(base);
	if (len < 2)
		return (0);
	while (*base)
	{
		if (*base == '-' || *base == '+' || ft_is_whitespace(*base))
			return (0);
		if (ft_strchr(base + 1, *base))
			return (0);
		base++;
	}
	return (1);
}
