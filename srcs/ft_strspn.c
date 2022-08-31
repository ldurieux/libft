/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:32:50 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/11 17:32:51 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline t_bool	ft_match_one_of(const char chr, const char *array)
{
	while (*array)
		if (chr == *array++)
			return (1);
	return (0);
}

size_t	ft_strspn(const char *str, const char *accept)
{
	size_t	i;

	i = 0;
	while (ft_match_one_of(str[i], accept))
		i++;
	return (i);
}

size_t	ft_strcspn(const char *str, const char *reject)
{
	size_t	i;

	i = 0;
	while (!ft_match_one_of(str[i], reject))
		i++;
	return (i);
}
