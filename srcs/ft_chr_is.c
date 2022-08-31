/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr_is.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:45:06 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/31 11:45:07 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define ASCII_MAX	127

t_bool	ft_isalpha(int chr)
{
	return ((chr >= 'A' && chr <= 'Z') || (chr >= 'a' && chr <= 'z'));
}

t_bool	ft_isdigit(int chr)
{
	return (chr >= '0' && chr <= '9');
}

t_bool	ft_isalnum(int chr)
{
	return (ft_isalpha(chr) || ft_isdigit(chr));
}

t_bool	ft_isascii(int chr)
{
	return (chr <= ASCII_MAX);
}

t_bool	ft_isprint(int chr)
{
	return (chr <= '~' && chr >= ' ');
}
