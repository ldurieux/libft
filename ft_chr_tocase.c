/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr_tocase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:50:11 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/31 11:50:12 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define CASE_OFFSET	32

int	ft_toupper(int chr)
{
	if (chr >= 'a' && chr <= 'z')
		return (chr - CASE_OFFSET);
	return (chr);
}

int	ft_tolower(int chr)
{
	if (chr >= 'A' && chr <= 'Z')
		return (chr + CASE_OFFSET);
	return (chr);
}
