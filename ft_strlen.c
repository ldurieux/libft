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

#define ALIGN_CHECK 0x07
#define NULL_CHECK_LOW 0x0101010101010101
#define NULL_CHECK_HIGH 0x8080808080808080

// NOLINTBEGIN
static const char	*strlen_aligned(const char *chr_ptr,
	register size_t *lw_ptr, register size_t lw)
{
	while (1)
	{
		lw = *lw_ptr++;
		if ((lw - NULL_CHECK_LOW) & ~lw & NULL_CHECK_HIGH)
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
// NOLINTEND

/* first check unaligned bytes one by one
 * then do it by 8 bytes once we're aligned
*/
size_t	ft_strlen(const char *str)
{
	const char	*chr_ptr;

	if (!str)
		return (0);
	chr_ptr = str;
	while (((size_t)chr_ptr & ALIGN_CHECK) != 0)
	{
		if (*chr_ptr == '\0')
			return (chr_ptr - str);
		chr_ptr++;
	}
	return (strlen_aligned(chr_ptr, (size_t *)chr_ptr, 0) - str);
}

// NOLINTBEGIN
static const char	*strnlen_aligned(const char *chr_ptr,
	register size_t *lw_ptr, register size_t lw, const char *max)
{
	while ((char *)lw_ptr < max)
	{
		lw = *lw_ptr++;
		if ((lw - NULL_CHECK_LOW) & ~lw & NULL_CHECK_HIGH)
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
// NOLINTEND

size_t	ft_strnlen(const char *str, size_t n)
{
	const char	*chr_ptr;
	size_t		len;

	if (!str)
		return (0);
	chr_ptr = str;
	while (((size_t)chr_ptr & ALIGN_CHECK) != 0 && (size_t)(chr_ptr - str) < n)
	{
		if (*chr_ptr == '\0')
			return (chr_ptr - str);
		chr_ptr++;
	}
	len = strnlen_aligned(chr_ptr, (size_t *)chr_ptr, 0, str + n) - str;
	return (len * (len < n) + n * (len >= n));
}
