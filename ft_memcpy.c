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
	unsigned char	*c_dst;

	if (!dst || !src)
		return (NULL);
	i = (size_t)-1;
	c_dst = (unsigned char *)dst;
	while (++i < len)
		c_dst[i] = ((unsigned const char *)src)[i];
	return (dst);
}
