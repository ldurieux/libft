SRCS =  main.c \
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

HEADERS = includes/

OBJS		= ${SRCS:.c=.o}
DEPS		= ${SRCS:.c=.d}
CC			= gcc
CCFLAGS		= -Wall -Wextra -g
DEPSFLAGS	= -MMD -MP
NAME		= libft
RM			= rm -f

.PHONY: all clean fclean re

$(NAME) : $(OBJS)
		$(CC) $(CCFLAGS) -I$(HEADERS) -o $@ $^

all : $(NAME)

clean :
		-$(RM) $(OBJS) $(DEPS)

fclean : clean
		-$(RM) $(NAME)

re : fclean all

-include $(DEPS)

%.o : %.c Makefile
		$(CC) $(CCFLAGS) $(DEPSFLAGS) -I$(HEADERS) -c $< -o $@
