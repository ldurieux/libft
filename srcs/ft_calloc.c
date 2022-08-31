/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:12:36 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/11 12:12:38 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void		*res;
	char		*c_ptr;
	t_uint64	*i_ptr;
	size_t		mem_size;

	mem_size = count * size;
	res = malloc(mem_size);
	if (!res)
		return (NULL);
	i_ptr = (t_uint64 *) res;
	while (mem_size > sizeof(t_uint64) - 1)
	{
		*i_ptr++ = 0;
		mem_size -= sizeof(t_uint64);
	}
	c_ptr = (char *) i_ptr;
	while (mem_size-- > 0)
		*c_ptr++ = 0;
	return (res);
}
