/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:13:05 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/11 12:13:06 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_strstr(const char *haystack, const char *needle)
{
	t_size	i;

	if (!needle[0])
		return (haystack);
	while (*haystack)
	{
		i = 0;
		while (haystack[i] == needle[i] && haystack[i])
			i++;
		if (!needle[i])
			return (haystack);
		haystack++;
	}
	return (NULL);
}

const char	*ft_strrstr(const char *haystack, const char *needle)
{
	t_size		i;
	const char	*hs_copy;

	if (!needle[0])
		return (haystack);
	hs_copy = haystack + ft_strlen(haystack) - 1;
	while (hs_copy >= haystack)
	{
		i = 0;
		while (hs_copy[i] == needle[i] && hs_copy[i])
			i++;
		if (!needle[i])
			return (hs_copy);
		hs_copy--;
	}
	return (NULL);
}
