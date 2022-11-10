/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:12:48 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/11 12:12:49 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t			i;
	char			*c_dst;
	const char		*c_src;

	if (!dst || !src)
		return (NULL);
	i = (size_t)-1;
	c_dst = (char *)dst;
	c_src = (const char *)src;
	while (++i < len)
		c_dst[i] = c_src[i];
	return (dst);
}

void	*ft_memccpy(void *dst, const void *src, int chr, size_t len)
{
	size_t		i;
	char		*c_dst;
	const char	*c_src;

	if (!dst || !src)
		return (NULL);
	c_dst = dst;
	c_src = src;
	i = 0;
	while (i < len && c_src[i] != chr)
	{
		c_dst[i] = c_src[i];
		i++;
	}
	return (dst);
}
