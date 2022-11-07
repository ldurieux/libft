/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 19:46:34 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/14 19:46:36 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BITS_IN_BYTE 8

static inline t_uint64	make_mask(const t_uint8 value)
{
	t_uint64	res;
	t_uint8		i;

	res = 0;
	i = 0;
	while (i++ < BITS_IN_BYTE)
		res = (res << BITS_IN_BYTE) + value;
	return (res);
}

void	*ft_memset(void *dst, int value, size_t len)
{
	t_uint8		*c_ptr;
	t_uint64	*i_ptr;
	t_uint64	mask;

	if (!dst)
		return (NULL);
	i_ptr = (t_uint64 *) dst;
	mask = make_mask(value);
	while (len > BITS_IN_BYTE - 1)
	{
		*i_ptr++ = mask;
		len -= BITS_IN_BYTE;
	}
	c_ptr = (t_uint8 *) i_ptr;
	while (len-- > 0)
		*c_ptr++ = value;
	return (dst);
}
