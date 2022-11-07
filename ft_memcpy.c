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
	t_uint64		*i_dst;
	const t_uint64	*i_src;
	char			*c_dst;
	const char		*c_src;

	if (!dst || !src)
		return (NULL);
	i = -1;
	if ((t_uint64)dst % sizeof(t_uint64) == 0
		&& (t_uint64)src % sizeof(t_uint64) == 0
		&& len % sizeof(t_uint64) == 0)
	{
		i_dst = (t_uint64 *)dst;
		i_src = (const t_uint64 *)src;
		while (++i < len / sizeof(t_uint64))
			i_dst[i] = i_src[i];
		return (dst);
	}
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
