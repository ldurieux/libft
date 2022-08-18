/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:13:23 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/14 22:54:21 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# define ULLONG_MAX	0xffffffffffffffff
# define LLONG_MAX	0x7fffffffffffffff
# define LLONG_MIN	0x8000000000000000
# define ULONG_MAX	0xffffffffffffffff
# define LONG_MAX	0x7fffffffffffffff
# define LONG_MIN	0x8000000000000000
# define UINT_MAX	0xffffffff
# define INT_MAX	0x7fffffff
# define INT_MIN	0x80000000
# define USHORT_MAX	0xffff
# define SHORT_MAX	0x7fff
# define SHORT_MIN	0x8000
# define UBYTE_MAX	0xff
# define BYTE_MAX	0x7f
# define BYTE_MIN	0x80

typedef unsigned long long	t_size;
typedef unsigned char		t_bool;

typedef unsigned long long	t_uint64;
typedef unsigned int		t_uint32;
typedef unsigned short		t_uint16;
typedef unsigned char		t_uint8;

typedef long long			t_int64;
typedef int					t_int32;
typedef short				t_int16;
typedef char				t_int8;

typedef unsigned long long	t_ptrdiff;

/*PRINT*/
void		ft_putstr(const char *str);
void		ft_putnbr(int value);

/*STRING*/
/* return the length of str
 * see man strlen(3) */
t_size		ft_strlen(const char *str);
t_size		ft_strnlen(const char *str, t_size n);

/* compare 2 stirngs and return 0 if they are equal
 * a negative value if s1 < s2
 * a positive value otherwise
 * see man strcmp(3) */
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, t_size n);
/* same but ignore case */
int			ft_stricmp(const char *s1, const char *s2);
int			ft_strnicmp(const char *s1, const char *s2, t_size n);

/* find first or last occurence of chr in str
 * see man strchr(3) */
const char	*ft_strchr(const char *str, char chr);
const char	*ft_strrchr(const char *str, char chr);

/* find first or last offcurence of need in haystack
 * if nothing is found return NULL
 * if needle is empty return haystack
 * see man strstr(3) */
const char	*ft_strstr(const char *haystack, const char *needle);
const char	*ft_strrstr(const char *haystack, const char *needle);

/* copy a string, see man strcpy(3) */
char		*ft_strcpy(char	*dest, const char *src);
char		*ft_strncpy(char *dest, const char *src, t_size n);
t_size		ft_strlcpy(char *dest, const char *src, t_size size);

/* duplicate a string, see man strdup(3) */
char		*ft_strdup(const char *src);
char		*ft_strndup(const char *src, t_size n);

/* concatenate a string, see man strcat(3) */
char		*ft_strcat(char *dest, const char *src);
char		*ft_strncat(char *dest, const char *src, t_size n);
t_size		ft_strlcat(char *dest, const char *src, t_size size);

/* to lowercase */
char		*ft_strlwr(char *str);

/* to uppercase */
char		*ft_strupr(char *str);

/* make any word start by an uppercase
 * and any following letters a lowercase */
char		*ft_strcap(char *str);

/* reverse the string */
char		*ft_strrev(char *str);

t_bool		ft_str_iswhitespace(const char *str);
t_bool		ft_str_isalphanum(const char *str);
t_bool		ft_str_isalpha(const char *str);
t_bool		ft_str_isdigit(const char *str);
t_bool		ft_str_isprintable(const char *str);

/* trim str of leading whitespaces */
char		*ft_strtrm_lead(char *str);

/* trim str of trailling whitespaces */
char		*ft_strtrm_trail(char *str);

/* trim str of leading and trailling whitespaces */
char		*ft_strtrm(char *str);

/* trim str whitespaces
 * then replace any whitespace by a space inside the string
 * if there are successive space characters in str
 * replace them by a single space */
char		*ft_strsmp(char *str);

/* count until a character in str is not
 * contained in accept and return the count
 * see man strspn(3) */
t_size		ft_strspn(const char *str, const char *accept);

/* count until a character in str is
 * contained in reject and return the count */
t_size		ft_strcspn(const char *str, const char *reject);

/* return the first occurence of any chrs in str
 * see man strpbrk(3) */
const char	*ft_strpbrk(const char *str, const char *chrs);

/* return a string starting from after any delims
 * and ending before any delims
 * if nothing is nothing is found return NULL
 * see man strtok(3) */
char		*ft_strtok_r(const char *str, const char *delims,
				const char **save_ptr);

/* return a string containing every string in strs
 * delimited by delim */
char		*ft_strjoin(char **strs, const char *delim);

/* return an array of string contained in str
 * delimited by any character contained in delims */
char		**ft_strsplit(const char *str, const char *delims);

/*MEM*/
/* swap 2 values of size size */
void		ft_swap(void *a, void *b, t_size size);

/* copy a bloc of memory
 * see man memcpy(3) */
void		*ft_memcpy(void *dst, const void *src, t_size len);

/* fill a bloc of memory
 * see man memset(3) */
void		*ft_memset(void *dst, t_uint8 value, t_size len);

/* allocate memory and fill it with 0
 * see man calloc(3) */
void		*ft_calloc(t_size count, t_size size);

/*INT STRING CONVERSION*/
/* ascii to integer
 * see man atoi(3) */
int			ft_atoi(const char *str);
long		ft_atol(const char *str);
long long	ft_atoll(const char *str);

/* same as atoi but specify base */
int			ft_atoi_base(const char *str, const char *base);
long		ft_atol_base(const char *str, const char *base);
long long	ft_atoll_base(const char *str, const char *base);

/* ascii to integer with a better handling of overflow
 * and end_ptr becomes the next character after the number
 * see man strtoi(3) */
int			ft_strtoi(const char *str, const char **end_ptr);
long		ft_strtol(const char *str, const char **end_ptr);
long long	ft_strtoll(const char *str, const char **end_ptr);

/* interger to ascii
 * see man itoa(3) */
char		*ft_itoa(int value);
char		*ft_ltoa(long value);
char		*ft_lltoa(long long value);

/* same as ito but specify base */
char		*ft_itoa_base(int value, const char *base);
char		*ft_ltoa_base(long value, const char *base);
char		*ft_lltoa_base(long long value, const char *base);

/* check if a numeric base has :
 * more than 2 characters
 * does not contain a + or -
 * does not contain a whitespace
 * does not repeat characters */
t_bool		ft_check_numeric_base(const char *base);

/* convert str from base from to base to */
char		*ft_convert_base(const char *str,
				const char *from, const char *to);

/*MATH*/
t_uint64	ft_factorial(t_int64 value);
t_int64		ft_power(t_int64 value, t_int64 power);

/*INLINES*/
/*CHARACTER TYPE*/
static inline t_bool	ft_is_whitespace(const char chr)
{
	return (chr == ' ' || chr == '\f' || chr == '\n'
		|| chr == '\r' || chr == '\t' || chr == '\v');
}

/*SIMPLE MATH*/
static inline t_uint64	ft_abs(t_int64 value)
{
	return (
		value * ((value > 0) * 2 - 1)
	);
}

#endif
