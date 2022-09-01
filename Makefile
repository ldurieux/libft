SRCS = \
	srcs/ft_strlen.c \
	srcs/ft_memcpy.c \
	srcs/ft_strcmp.c \
	srcs/ft_putstr.c \
	srcs/ft_atoi.c \
	srcs/ft_itoa.c \
	srcs/ft_convert_base.c \
	srcs/ft_calloc.c \
	srcs/ft_strstr.c \
	srcs/ft_strcpy.c \
	srcs/ft_strcat.c \
	srcs/ft_str_tocase.c \
	srcs/ft_str_is.c \
	srcs/ft_swap.c \
	srcs/ft_factorial.c \
	srcs/ft_power.c \
	srcs/ft_strtrm.c \
	srcs/ft_strsmp.c \
	srcs/ft_strjoin.c \
	srcs/ft_strtoi.c \
	srcs/ft_strdup.c \
	srcs/ft_strspn.c \
	srcs/ft_strtok.c \
	srcs/ft_strpbrk.c \
	srcs/ft_strsplit.c \
	srcs/ft_strrev.c \
	srcs/ft_strchr.c \
	srcs/ft_memset.c \
	srcs/ft_putnbr.c \
	srcs/ft_check_numeric_base.c \
	srcs/ft_atoi_base.c \
	srcs/ft_itoa_base.c \
	srcs/ft_memmem.c \
	srcs/ft_bzero.c \
	srcs/ft_memmove.c \
	srcs/ft_memchr.c \
	srcs/ft_memcmp.c \
	srcs/ft_chr_is.c \
	srcs/ft_chr_tocase.c \
	srcs/ft_substr.c \
	srcs/ft_strtrim.c \
	srcs/ft_strmapi.c \

SRCS_BONUS = \
	srcs/ft_lstnew.c \
	srcs/ft_lstadd.c \
	srcs/ft_lstsize.c \
	srcs/ft_lstlast.c \
	srcs/ft_lstdel.c \
	srcs/ft_lstiter.c \

HEADERS = includes/

OBJS		= ${SRCS:.c=.o}
OBJS_BONUS	= ${SRCS_BONUS:.c=.o}
DEPS		= ${SRCS:.c=.d}
DEPS_BONUS	= ${SRCS_BONUS:.c=.d}
CC			= gcc
CCFLAGS		= -Wall -Wextra -Werror
DEPSFLAGS	= -MMD -MP
NAME		= libft.a
RM			= rm -Rf
AR			= ar
AR_FLAGS	= rc

.PHONY: all clean fclean re bonus

$(NAME) : $(OBJS)
		$(AR) $(AR_FLAGS) $@ $(OBJS)

bonus : $(OBJS) $(OBJS_BONUS)
		$(AR) $(AR_FLAGS) $(NAME) $(OBJS) $(OBJS_BONUS)

all : $(NAME)

clean :
		-$(RM) $(OBJS) $(DEPS) $(OBJS_BONUS) $(DEPS_BONUS)

fclean : clean
		-$(RM) $(NAME)

re : fclean all

-include $(DEPS) $(DEPS_BONUS)

%.o : %.c Makefile
		$(CC) $(CCFLAGS) $(DEPSFLAGS) -I$(HEADERS) -c $< -o $@
