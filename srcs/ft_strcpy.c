/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:12:57 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/11 12:12:58 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char	*dest, const char *src)
{
	t_size	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strncpy(char *dest, const char *src, t_size n)
{
	t_size	i;

	i = 0;
	while (*src && i < n)
		dest[i++] = *src++;
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}

t_size	ft_strlcpy(char *dest, const char *src, t_size size)
{
	t_size	i;

	i = 0;
	while (*src && i < size - 1)
		dest[i++] = *src++;
	dest[i] = '\0';
	while (*src++)
		i++;
	return (i);
}
