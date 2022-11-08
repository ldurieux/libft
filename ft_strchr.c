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
	chr = (unsigned char)chr;
	while (*str)
	{
		if (*str == chr)
			return ((char *)str);
		str++;
	}
	if (chr == 0)
		return ((char *)str);
	return (NULL);
}

char	*ft_strrchr(const char *str, int chr)
{
	const char	*str_cp;

	if (!str)
		return (NULL);
	chr = (unsigned char)chr;
	str_cp = str + ft_strlen(str) - 1;
	if (chr == 0)
		return ((char *)str_cp + 1);
	while (str_cp >= str)
	{
		if (*str_cp == chr)
			return ((char *)str_cp);
		str_cp--;
	}
	return (NULL);
}
