/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 18:08:55 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/27 16:22:12 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline t_bool	ft_match_one_of(const char chr, const char *array)
{
	while (*array)
		if (chr == *array++)
			return (1);
	return (0);
}

static inline t_size	ft_count_words(const char *str, const char *delims)
{
	t_size	count;

	count = 0;
	while (*str)
	{
		while (ft_match_one_of(*str, delims))
			str++;
		if (!*str)
			break ;
		while (*str && !ft_match_one_of(*str, delims))
			str++;
		count++;
	}
	return (count);
}

char	**ft_strsplit(const char *str, const char *delims)
{
	t_size	words;
	t_size	i;
	char	**res;

	words = ft_count_words(str, delims);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < words)
		res[i++] = ft_strtok_r(str, delims, &str);
	res[i] = NULL;
	return (res);
}
