/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:12:55 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/11 12:12:55 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	t_size	i;

	i = ft_strlen(dest);
	while (*src)
		dest[i++] = *src++;
	dest[i] = '\0';
	return (dest);
}

char	*ft_strncat(char *dest, const char *src, t_size n)
{
	t_size	i;
	t_size	j;

	i = ft_strlen(dest);
	j = 0;
	while (src[j] && j < n)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}

t_size	ft_strlcat(char *dest, const char *src, t_size size)
{
	t_size	i;
	t_size	j;

	i = 0;
	while (dest[i] && i < size)
		i++;
	j = 0;
	while (src[j] && (i + j) < size - 1)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i > size && size > 0)
		dest[i + j] = '\0';
	j += ft_strlen(src + j);
	return (i + j);
}
