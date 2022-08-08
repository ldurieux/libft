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

HEADERS = includes/

OBJS		= ${SRCS:.c=.o}
DEPS		= ${SRCS:.c=.d}
CC			= gcc
CCFLAGS		= -Wall -Wextra -fsanitize=address -g3
DEPSFLAGS	= -MMD -MP
NAME		= libft

.PHONY: all clean fclean re

$(NAME) : $(OBJS)
		$(CC) $(CCFLAGS) -I$(HEADERS) -o $@ $^

all : $(NAME)

clean :
		-rm -f $(OBJS) $(DEPS)

fclean : clean
		-rm -f $(NAME)

re : fclean all

-include $(DEPS)

%.o : %.c Makefile
		$(CC) $(CCFLAGS) $(DEPSFLAGS) -I$(HEADERS) -c $< -o $@
