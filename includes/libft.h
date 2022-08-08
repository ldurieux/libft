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

/*PRINT*/
void		ft_putstr(char *str);

/*STRING*/
t_size		ft_strlen(const char *str);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strstr(const char *haystack, const char *needle);

/*MEM*/
void		*ft_memcpy(void *dst, const void *src, t_size len);
void		*ft_calloc(t_size count, t_size size);

/*INT STRING CONVERSION*/
int			ft_atoi(const char *str);
long		ft_atol(const char *str);
long long	ft_atoll(const char *str);
char		*ft_itoa(int value);
char		*ft_ltoa(long value);
char		*ft_lltoa(long long value);
char		*ft_convert_base(const char *str,
				const char *from, const char *to);

/*INLINES*/
/*CHAR TYPE*/
static inline t_bool	ft_is_whitespace(const char chr)
{
	return (chr == ' ' || chr == '\f' || chr == '\n'
		|| chr == '\r' || chr == '\t' || chr == '\v');
}

static inline t_bool	ft_is_digit(const char chr)
{
	return (chr >= '0' && chr <= '9');
}

static inline t_int64	ft_chr_index(const char *str, const char chr)
{
	t_int64	index;

	index = -1;
	while (str[++index])
		if (str[index] == chr)
			return (index);
	return (-1);
}

/*STRING*/
static inline t_bool	ft_str_contains(const char *str, const char *search)
{
	while (*str)
		if (ft_chr_index(search, *str++) != -1)
			return (1);
	return (0);
}

/*SIMPLE MATH*/
static inline t_uint64	ft_abs(t_int64 value)
{
	return (
		value * (value > 0)
		+ value * ((value < 0) * -1)
	);
}

#endif
