/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:12:56 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/11 12:12:57 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	register const unsigned char	*r1 = (unsigned char *)s1;
	register const unsigned char	*r2 = (unsigned char *)s2;

	while (*r1 == *r2 && *r1)
	{
		r1++;
		r2++;
	}
	return (*r1 - *r2);
}

int	ft_strncmp(const char *s1, const char *s2, t_size n)
{
	register const unsigned char	*r1 = (unsigned char *)s1;
	register const unsigned char	*r2 = (unsigned char *)s2;

	while (*r1 == *r2 && *r1 && n-- < 1)
	{
		r1++;
		r2++;
	}
	return (*r1 - *r2);
}
