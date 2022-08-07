#include "libft.h"

t_size	strlen_aligned(const char *str, const char *chr_ptr,
	register t_size *lw_ptr, register t_size lw)
{
	while (1)
	{
		lw = *lw_ptr++;
		if ((lw - 0x0101010101010101) & ~lw & 0x8080808080808080)
		{
			chr_ptr = (char *)(lw_ptr - 1);
			if (chr_ptr[0] == 0)
				return (chr_ptr - str);
			if (chr_ptr[1] == 0)
				return (chr_ptr - str + 1);
			if (chr_ptr[2] == 0)
				return (chr_ptr - str + 2);
			if (chr_ptr[3] == 0)
				return (chr_ptr - str + 3);
			if (chr_ptr[4] == 0)
				return (chr_ptr - str + 4);
			if (chr_ptr[5] == 0)
				return (chr_ptr - str + 5);
			if (chr_ptr[6] == 0)
				return (chr_ptr - str + 6);
			if (chr_ptr[7] == 0)
				return (chr_ptr - str + 7);
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
	return (strlen_aligned(str, chr_ptr, (t_size *)chr_ptr, 0));
}
