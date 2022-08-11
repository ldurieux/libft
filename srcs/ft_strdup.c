/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:25:36 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/11 16:25:37 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*res;
	t_size	src_len;

	src_len = ft_strlen(src);
	res = malloc(sizeof(char) * (src_len + 1));
	if (!res)
		return (NULL);
	ft_memcpy(res, src, src_len);
	res[src_len] = '\0';
	return (res);
}
