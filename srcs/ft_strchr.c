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

const char	*ft_strchr(const char *str, char chr)
{
	while (*str)
	{
		if (*str == chr)
			return (str);
		str++;
	}
	return (NULL);
}

const char	*ft_strrchr(const char *str, char chr)
{
	const char	*str_cp;

	str_cp = str + ft_strlen(str) - 1;
	while (str_cp >= str)
	{
		if (*str_cp == chr)
			return (str_cp);
		str_cp--;
	}
	return (NULL);
}
