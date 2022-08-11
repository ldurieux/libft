/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:29:03 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/11 14:29:04 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char **strs, char *delimiter)
{
	t_size	total_len;
	t_size	delimiter_len;
	t_size	i;
	t_size	offset;
	char	*res;

	delimiter_len = ft_strlen(delimiter);
	total_len = 0;
	i = -1;
	while (strs[++i])
		total_len += ft_strlen(strs[i]) + delimiter_len;
	if (total_len > 0)
		total_len -= delimiter_len;
	res = malloc(sizeof(char) * (total_len + 1));
	i = -1;
	offset = 0;
	while (strs[++i])
	{
		offset += ft_strlcpy(&res[offset], strs[i], total_len + 1);
		if (strs[i + 1])
			offset += ft_strlcpy(&res[offset], delimiter, delimiter_len + 1);
	}
	res[offset] = '\0';
	return (res);
}
