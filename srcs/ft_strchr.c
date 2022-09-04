/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 00:29:07 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/12 00:29:08 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int chr)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == chr)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

char	*ft_strrchr(const char *str, int chr)
{
	const char	*str_cp;

	if (!str)
		return (NULL);
	str_cp = str + ft_strlen(str) - 1;
	while (str_cp >= str)
	{
		if (*str_cp == chr)
			return ((char *)str_cp);
		str_cp--;
	}
	return (NULL);
}
