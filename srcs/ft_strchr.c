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

char	*ft_strchr(char *str, char chr)
{
	while (*str)
	{
		if (*str == chr)
			return (str);
		str++;
	}
	return (NULL);
}

char	*ft_strrchr(char *str, char chr)
{
	char	*str_cp;

	str_cp = str + ft_strlen(str) - 1;
	while (str_cp >= str)
	{
		if (*str_cp == chr)
			return (str_cp);
		str_cp--;
	}
	return (NULL);
}
