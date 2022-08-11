/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:13:01 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/11 12:13:02 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*strlen_aligned(const char *chr_ptr,
	register t_size *lw_ptr, register t_size lw)
{
	while (1)
	{
		lw = *lw_ptr++;
		if ((lw - 0x0101010101010101) & ~lw & 0x8080808080808080)
		{
			chr_ptr = (char *)(lw_ptr - 1);
			if (chr_ptr[0] == 0)
				return (chr_ptr);
			if (chr_ptr[1] == 0)
				return (chr_ptr + 1);
			if (chr_ptr[2] == 0)
				return (chr_ptr + 2);
			if (chr_ptr[3] == 0)
				return (chr_ptr + 3);
			if (chr_ptr[4] == 0)
				return (chr_ptr + 4);
			if (chr_ptr[5] == 0)
				return (chr_ptr + 5);
			if (chr_ptr[6] == 0)
				return (chr_ptr + 6);
			if (chr_ptr[7] == 0)
				return (chr_ptr + 7);
		}
	}
}

/* first check unaligned bytes one by one
 * then do it by 8 bytes once we're aligned
*/
t_size	ft_strlen(const char *str)
{
	const char	*chr_ptr;

	chr_ptr = str;
	while (((t_size)chr_ptr & 0x07) != 0)
	{
		if (*chr_ptr == '\0')
			return (chr_ptr - str);
		chr_ptr++;
	}
	return (strlen_aligned(chr_ptr, (t_size *)chr_ptr, 0) - str);
}

static const char	*strnlen_aligned(const char *chr_ptr,
	register t_size *lw_ptr, register t_size lw, const char *max)
{
	while ((char *)lw_ptr < max)
	{
		lw = *lw_ptr++;
		if ((lw - 0x0101010101010101) & ~lw & 0x8080808080808080)
		{
			chr_ptr = (char *)(lw_ptr - 1);
			if (chr_ptr[0] == 0)
				return (chr_ptr);
			if (chr_ptr[1] == 0)
				return (chr_ptr + 1);
			if (chr_ptr[2] == 0)
				return (chr_ptr + 2);
			if (chr_ptr[3] == 0)
				return (chr_ptr + 3);
			if (chr_ptr[4] == 0)
				return (chr_ptr + 4);
			if (chr_ptr[5] == 0)
				return (chr_ptr + 5);
			if (chr_ptr[6] == 0)
				return (chr_ptr + 6);
			if (chr_ptr[7] == 0)
				return (chr_ptr + 7);
		}
	}
	return (max);
}

t_size	ft_strnlen(const char *str, t_size n)
{
	const char	*chr_ptr;
	t_size		len;

	chr_ptr = str;
	while (((t_size)chr_ptr & 0x07) != 0 && (t_size)(chr_ptr - str) < n)
	{
		if (*chr_ptr == '\0')
			return (chr_ptr - str);
		chr_ptr++;
	}
	len = strnlen_aligned(chr_ptr, (t_size *)chr_ptr, 0, str + n) - str;
	return (len * (len < n) + n * (len >= n));
}
