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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*res;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!res)
		return (NULL);
	ft_strcpy(res, s1);
	ft_strcat(res, s2);
	return (res);
}

char	*ft_strjoin_r(char **strs, const char *delim)
{
	size_t	total_len;
	size_t	delimiter_len;
	size_t	i;
	size_t	offset;
	char	*res;

	delimiter_len = ft_strlen(delim);
	total_len = 0;
	i = -1;
	while (strs[++i])
		total_len += ft_strlen(strs[i]) + delimiter_len;
	total_len -= delimiter_len * (total_len > 0);
	res = malloc(sizeof(char) * (total_len + 1));
	if (!res)
		return (NULL);
	i = -1;
	offset = 0;
	while (strs[++i])
	{
		offset += ft_strlcpy(&res[offset], strs[i], total_len + 1);
		if (strs[i + 1])
			offset += ft_strlcpy(&res[offset], delim, delimiter_len + 1);
	}
	return (res);
}
